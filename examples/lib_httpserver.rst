HTTP Server
=====

This block implements an extensible and multi-platform HTTP server.

Supported S.O
-------------

It's tested on:

* Linux with GCC
* Windows with Mingw
* Windows with Visual Studio
* MacOS with Clang

How does it work?
-------------

It allow you to just implement a subclass of httpserver::HttpMiddleware to attend browsers or other http client requests.

A method "call" from your subclass object will be called with a Request* object and a Response* object.

Just modify the body and/or headers of Response object in your method and the server will do all the work.


How can i use it?
-------------
* Just copy the following files to a new block.
* Find the dependencies and execute your code:

.. code-block:: bash

    $ bii find
    $ bii cpp:run

* Open your web browser and go to *http://localhost:9000*


main.cpp
^^^^^^^^^^^^
This file just instance the server and run it with a simple configuration parameters.

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
^^^^^^^^^^^^
Define your HttpMiddleware subclass.

.. code-block:: cpp    


    #include "lasote/httpserver/http_middleware.h"

    using namespace httpserver;

    class MyHttpMiddleware : public httpserver::HttpMiddleware {
        public:
            MyHttpMiddleware() : HttpMiddleware(NULL){}
            MyHttpMiddleware(HttpMiddleware* other_middleware) : HttpMiddleware(other_middleware){
            }
            virtual ~MyHttpMiddleware();
            virtual void call(Request&, Response&);
    };


my_http_middle_ware.cpp
^^^^^^^^^^^^

Implement your HttpMiddleware subclass.
Just write the call method reading from request the variables or headers you need and modify response to print the output.

.. code-block:: cpp 

    #include "lasote/my_block/my_http_middle_ware.h"
    #include "sstream"
    #include "iostream"
    
    
    MyHttpMiddleware::~MyHttpMiddleware(){
    
    }
    
    void MyHttpMiddleware::call(Request& request, Response& response){
        ostringstream html;
    
        html << "<!DOCTYPE html>\n<html>\n<body>\n";
    
        if(request.get("name") != ""){
            html << "Hello " << request.get("name") << "<br><br>";
        }
    
        //Build the html form
        string form;
        form = "\
                    <form name='form' action='/' method='POST'>\n\
                        Name: <br>\n\
                        <input type='text' name='name'> <br>\n\
                        <input type='submit''/>\n\
                    </form>\n\
                  ";
    
        html << form << "</body>\n</html>\n";
    
        // Set content type we are printing
        response.content_type("text/html");
        // Set the body
        response.body = html.str();
    }


    
More information
-------------

You can find more information in readme.txt of `lasote/httpserver <https://www.biicode.com/lasote/blocks/lasote/httpserver/branches/master>`_


List of dependencies
-------------
* `melikyan/ptypes <https://www.biicode.com/melikyan/blocks/melikyan/ptypes/branches/master>`_: PTypes (C++ Portable Types Library) is a simple alternative to the STL that includes multithreading and networking. It defines dynamic strings, variants, character sets, lists and other basic data types along with portable thread and synchronization objects, IP sockets and named pipes. Its main `target audience' is developers of complex network daemons, robots or non-visual client/server applications of any kind.
* `lasote/genericipserver <https://www.biicode.com/lasote/blocks/lasote/genericipserver/branches/master>`_: Generic and extensible IP server.
* `lasote/thread_jobs <https://www.biicode.com/lasote/blocks/lasote/thread_jobs/branches/master>`_: Execute your tasks in threads managed by a pool.