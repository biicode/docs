========================================
HTTP Server: how to control a led by web
========================================

This example use the :ref:`HTTP Server <httpserver>` library to control a LED.

How can i use it?
-----------------
* Just copy the following files to a new block.
* Find the dependencies and execute your code:

Once you have the code, invoke ``bii find`` to resolve external dependencies. Then, build and run in your Raspberry Pi as usual. Remember, the generated binary only work on your Raspberry Pi and have to run as sudo because it works on the hardware:

.. code-block:: bash

	$ bii find
	...
	$ bii cpp:build
	...
	$ bii rpi:send
	...
	$ bii rpi:ssh
	...
	pi@raspberrypi ~ $ cd [hive_name]
	pi@raspberrypi ~/[hive_name] $ ls
	[binary_name]
	pi@raspberrypi ~/[hive_name] $ sudo ./[binary_name]

* Open your web browser and go to *http://localhost:9000*

.. image:: ../../../_static/img/rpi/httpserverrpi.png

main.cpp
^^^^^^^^
This file just instances the server and run it with a simple configuration parameters.

.. code-block:: cpp 

	#include "lasote/httpserver/http_server.h"
	#include "my_http_middle_ware.h"

	using namespace httpserver;
	using namespace gip;

	int main(){
		MyHttpMiddleware my_mmiddleware;
		HttpServerConf conf(9000, 300, 60, 5);

		HttpServer http_server;

		http_server.run(&my_mmiddleware, &conf);

		return 0;

	}

my_http_middle_ware.h
^^^^^^^^^^^^^^^^^^^^^

Defines your HttpMiddleware subclass.

.. code-block:: cpp 

	#include "lasote/httpserver/http_middleware.h"
	#include "led.h"

	namespace httpserver {

		class MyHttpMiddleware : public HttpMiddleware {
			public:
				MyHttpMiddleware() : HttpMiddleware(NULL){}
				MyHttpMiddleware(HttpMiddleware* other_middleware) : HttpMiddleware(other_middleware){

				}
				virtual ~MyHttpMiddleware();
				virtual void call(Request&, Response&);
			private:
				Led myLed;
		};

	} /* namespace httpserver */


my_http_middle_ware.cpp
^^^^^^^^^^^^^^^^^^^^^^^

Implements HttpMiddleware subclass.
With the call method you can turn on or turn off a LED using the request info of the request.

.. code-block:: cpp 

    #include "my_http_middle_ware.h"
    #include "lasote/httpserver/exception.h"
    #include "lasote/httpserver/model/method.h"
    #include "sstream"
    #include "iostream"

    namespace httpserver {

    	MyHttpMiddleware::~MyHttpMiddleware(){

    	}
    	
        void  MyHttpMiddleware::call(Request&  request,  Response&  response){
    		ostringstream  html;
        	string checkedOn = "", checkedOff = "";

    		html  <<  "<!DOCTYPE html>\n<html>\n<body>\n";

    		if(request.get("mode") == "on"){ myLed.on(); checkedOn = "checked";}
    		if(request.get("mode") == "off"){ myLed.off(); checkedOff = "checked";}
    		
    		//Build the html form
    		string  form;
    		form  =  "\
    					<form name='formulary' action='/hello' method='POST'>\n\
    						 Led Mode (on/off): <br>\n\
    						<input type='radio' name='mode' value='on' " + checkedOn + "> On<br>\n\
    						<input type='radio' name='mode' value='off' " + checkedOff + "> Off<br>\n\
    						<input type='submit''/>\n\
    					</form>\n\
    				  ";

    		html  <<  form  <<  "</body>\n</html>\n";

    		// Set content type we are printing
    		response.content_type("text/html");
    		// Set the body
    		response.body  =  html.str();
    	}



    } /* namespace httpserver */


led.h
^^^^^

Defines a Led class for turn on/off the light.

.. code-block:: cpp 

	#include <drogon/wiringpi/wiringpi/wiringpi.h>

	class Led
	{
		public:
			Led(); //default constuctor
			virtual ~Led(); //default virtual destructor
			void on();
			void off();
		
		private:
			int pin;
	};

led.cpp
^^^^^^^

Implements the Led class

.. code-block:: cpp 

	#include "led.h"

	Led::Led()
	{
		pin = 0;
		wiringPiSetup () ;
		pinMode (pin, OUTPUT) ;
	}

	Led::~Led()
	{

	}

	void Led::on()
	{
		digitalWrite (pin, HIGH);
	}

	void Led::off()
	{
		digitalWrite (pin, LOW);
	}
