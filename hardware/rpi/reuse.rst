The best part: share and reuse code with biicode!
=================================================
**And now, the best part, check how easy is to share and reuse code using the biicode platform.**

Remember that you can also do the :ref:`"How to configure your biicode workspace" <config_raspberry_ws>` example.

What you need?
--------------

* Raspberry Pi
* 1 Led

The Blink class
---------------

Suppose that based on the blinking example, you have developed a more elaborated version of the blink example in a ``Blink`` class, that uses a thread to do such task in parallel transparent to the main thread of execution, and admits some parametrization. Please note that using threads for just switching a Led is probably overkill (due to the cost of thread context switching), so this is just an example.
This could be such class:

**blink.h**

.. code-block:: cpp
	
    #pragma once
    #include "pthread.h"
    #include <unistd.h>
    
    /** Class to blink a led of the raspberry Pi (connected GPIO) */
    class Blink{
    public:
        /** blinker on the "pin" pin */
        Blink(int pin=0);
        /** call this function to modify the frequency of blinking, specifying
        milliseconds ligth is on and milliseconds light is off */
        void set_frequency(int millis_up=1000, int millis_down=1000);
        /** start to blink, internally using a thread (which might not be 
        the best solution for just blinking a led) for demo purposes */
        void start(int millis_up=1000, int millis_down=1000);
        /** stop the thread, if wait is true, it waits to the thread to finish */
        void stop(bool wait=false);
    
    private:
        static void *my_thread(void* data);
        void blink();
        pthread_t thread_id;
        int pin;
        int millis_up;
        int millis_down;
        bool blinking;
    };

**blink.cpp**

.. code-block:: cpp
	
	#include "blink.h"
	#include <drogon/wiringpi/wiringpi/wiringpi.h>

	Blink::Blink(int pin): pin(pin){
		pinMode (pin, OUTPUT) ;
	}
	void Blink::set_frequency(int millis_up, int millis_down) {
		this->millis_up = millis_up;
		this->millis_down = millis_down;
	}
	void Blink::start(int millis_up, int millis_down){
		set_frequency(millis_up, millis_down);
		blinking=true;
		pthread_create(&thread_id,NULL, my_thread, this);
	}
	void Blink::stop(bool wait){
		blinking = false;
		if(wait)
			pthread_join(thread_id, NULL);
	}
	void *Blink::my_thread(void* data){
		((Blink*)data)->blink();
	}
	void Blink::blink(){
		while(blinking){
			digitalWrite (pin, HIGH) ;      // On
			usleep(millis_up * 1000);
			digitalWrite (pin, LOW) ;      // Off
			usleep(millis_down * 1000);
		}
	}
	
And the main would use it as:

**main.cpp**

.. code-block:: cpp
	
    #include "blink.h"
    #include <unistd.h>
    #include <drogon/wiringpi/wiringpi/wiringpi.h>
    
    int main (void)
    {
        wiringPiSetup();
        Blink b(0); //Blink on PIN 0
        b.start(1000, 100);
        for (int i=0; i<10;i++){
            //Do your tasks here, no need to manage the Led, it will
            //keep blinking
            sleep(1); 
        }
        b.stop();
    }

Publish your code
-----------------
The ``Blink`` class seems interesting, it is probable that you might need to reuse it in other projects or you might want to share with the community so other RaspberryPI users can reuse it easily in their projects.
This can be achieved with biicode, all you need to do is to publish your code:

.. code-block:: bash

	$ bii work
	...
	$ bii publish
	Introduce TAG: STABLE
	Introduce msg: Blinker class working (or whatever message you like)

Assuming that your user name is *your_user_name* and the block is named *your_block*, you could navigate to http://www.biicode.com, go to your profile and see your code there.

Reuse it!
---------

Reusing your ``Blink`` class in other projects is straightforward. All you need to do is to include and do a *find*. 
You can use the Blink class wherever you want in your own code, this is only an example.

**main.cpp**

.. code-block:: cpp
	
    #include "your_user_name/your_block/blink.h" // Needed for use Blink class
    #include <drogon/wiringpi/wiringpi/wiringpi.h> // Needed for setup wiring pi
    #include <unistd.h>
    
    int main(){
        wiringPiSetup();
        //code here	
        Blink b(0); //blink on PIN 0
        b.start(1000, 100);
        //more code here (tipically inside an infinite loop)
        sleep(10); 
    
        b.stop();
    }

Once you have the code, invoke ``find`` to resolve external dependencies, so the Blink class is retrieved, together with the wiringPI source code files. Then, build and run in your Raspberry Pi as usual. Remember, the generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware:

.. code-block:: bash

	$ bii find
	...
	$ bii cpp:build
	...
	$ bii rpi:send
	...
	$ bii rpi:ssh
	...
	pi@raspberrypi ~ $ cd bin
	pi@raspberrypi ~/bin $ ls
	[binary_name]
	pi@raspberrypi ~/bin $ sudo ./[binary_name]
