.. _zmq_examples:

ZMQ with Google Protocol Buffers Serialization
==============================================

See previous example for more information about ZMQ.

An aspect that ZMQ does not cover is the serialization of messages, how to convert from classes
to a flat string (possibly binary for efficiency) and viceversa.

Protocol Buffers from Google is a serialization framework, that can be used for example for storing
and retrieving back information from disk. In this example we will use it for sending information over
a ZMQ socket.

Protocol buffers can be found in `this block <http://www.biicode.com/google/protobuf>`_ which was
very easily published from this `github repo <https://github.com/drodri/protobuf>`_.

We will first create a project and open the protocol buffers block:

.. code-block:: bash

   $ bii init zmq_protobuf
   $ cd zmq_protobuf
   $ bii open google/protobuf
   $ bii cpp:build
   
This will build the Protocol Buffers compiler (protoc or protoc.exe). Note that this is an optional
step, you can of course download manually this binary from the web.

Lets open now the examples block.vAs usual you can also create an empty block and copy-paste your files there.
We can also close the google/protobuf block, we have already compiled the "protoc" application,
and we no longer need it (it will be partly used as a dependency).

.. code-block:: bash

   $ bii open examples/zmq_protobuf
   $ bii close google/protobuf
   

In protocol-buffers, messages are defined in ".proto" files, that are converted into source code
files by the ``protoc`` generator. In this example we use the "message.proto" file used in the
original tutorial:

.. code-block:: text

   package tutorial;

   message Person {
     required string name = 1;
     required int32 id = 2;
     optional string email = 3;
   
     enum PhoneType {
       MOBILE = 0;
       HOME = 1;
       WORK = 2;
     }
   
     message PhoneNumber {
       required string number = 1;
       optional PhoneType type = 2 [default = HOME];
     }
   
     repeated PhoneNumber phone = 4;
   }
   
Creating the code is simple, move to the folder when this file is located and run the generator:

.. code-block:: bash

   $ cd blocks/examples/zmq_protobuf
   $ ../../../bin/protoc message.proto --cpp_out="."


This will generate 2 files: "message.pb.h" and "message.pb.cc". These two files can be used
from the client and server in the following way:

**hwclient.cpp**

.. code-block:: cpp

   #include "diego/zmqcpp/zmq.hpp"
   #include "message.pb.h"
   #include <string>
   #include <iostream>
   
   
   int main ()
   {
       GOOGLE_PROTOBUF_VERIFY_VERSION;
       
       tutorial::Person person; //fill a person data
       person.set_id(1234);
       person.set_name("john");
       person.set_email("john@mycompany.com");
       tutorial::Person::PhoneNumber* phone_number = person.add_phone();
       phone_number->set_number("1234567");
       phone_number->set_type(tutorial::Person::MOBILE);
       phone_number = person.add_phone();
       phone_number->set_number("7654321");
       phone_number->set_type(tutorial::Person::HOME);
       
       //  Prepare our context and socket
       zmq::context_t context (1);
       // Note we use here a PAIR socket, only 1 way message
       zmq::socket_t socket (context, ZMQ_PAIR);
   
       std::cout << "Connecting to server" << std::endl;
       socket.connect ("tcp://localhost:5555");
   
       std::string msg_str;
       person.SerializeToString(&msg_str);
       // create a zmq message from the serialized string
       zmq::message_t request (msg_str.size());
       memcpy ((void *) request.data (), msg_str.c_str(), msg_str.size());
       std::cout << "Sending Person data ..." << std::endl;
       socket.send (request);
      
       // Optional:  Delete all global objects allocated by libprotobuf.
       google::protobuf::ShutdownProtobufLibrary();
       return 0;
   }

**hwserver.cpp**

.. code-block:: cpp

   #include "diego/zmqcpp/zmq.hpp"
   #include <string>
   #include <iostream>
   #ifndef _WIN32
   #include <unistd.h>
   #else
   #include <windows.h>
   #endif
   
   #include "message.pb.h"
   #include <google/protobuf/text_format.h>
   
   
   int main () {
       //  Prepare our context and socket
       zmq::context_t context (1);
       zmq::socket_t socket(context, ZMQ_PAIR);
       socket.bind ("tcp://*:5555");
   
       while (true) {
           zmq::message_t request;
           //  Wait for next request from client
           socket.recv (&request);
           std::cout << "Received" << std::endl;
           tutorial::Person person;
           std::string msg_str(static_cast<char*>(request.data()), request.size());
           person.ParseFromString(msg_str);
           std::string text_str;
           google::protobuf::TextFormat::PrintToString(person, &text_str);
           std::cout << text_str << std::endl;
       }
       return 0;
   }
   
To resolve and retrieve dependencies, we just run the command:

.. code-block:: bash

   $ bii find
   
If in windows, it is necessary to specify VS (it doesnt work with MinGW), otherwise, you can skip this step

.. code-block:: bash

   $ bii cpp:configure -G “Visual Studio 12”


Then build and run, first the server, then the client (you need to open another console,
in the same folder)

.. code-block:: bash

   $ bii cpp:build
   $ bin/examples_zmq_protobuf_hwserver
   // another console
   $ bin/examples_zmq_protobuf_hwclient
   //in the server console:
   Received
   name: "john"
   id: 1234
   email: "john@mycompany.com"
   phone {
     number: "1234567"
     type: MOBILE
   }
   phone {
     number: "7654321"
     type: HOME
   }
