============================================
OpenGL ES: How to cross compile with biicode
============================================

Introduction
------------
As you know, when you are using biicode to develop your RaspberryPi applications
you are compiling using a cross compiler in your develop machine. So, when you
want to develop an OpenGLES application is necessary to obtain some files from
your RaspberryPi for being able to cross compile in your develop machine, like headers
with OpenGLES interfaces an shared libraries files. Biicode allows you to do
this almost automatically.

How can i do it?
-----------------
First of all make sure that your RaspberryPi is connected to your local network,
and you have permissions grants to access it. Then you should create a new hive,
let's call it triangle.

.. code-block:: bash

	$ bii new triangle
    ..
	you@yourmachine ~/bii_ws $ cd triangle

When you have your shining new hive, you should execute the following command:

.. code-block:: bash

	you@yourmachine ~/bii_ws/triangle $ bii rpi:initopengles pi 192.168.1.69
    pi@192.168.1.69's password:
    receiving incremental file list
    ..
    INFO: OpenGLES necessary files downloaded.
    INFO: CMake updated.
    you@yourmachine ~/bii_ws/triangle $

If you don't provide arguments, biicode takes values provided in settings.bii
configuration file for user and IP address of RaspberryPi.

Once executed this command you are ready to develop your awesome OpenGLES
applications as usual with biicode. Lets try some of predefined examples to see
how easy it would be.


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
