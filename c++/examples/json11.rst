.. _json11_examples:

json11
======

json11 is a tiny JSON library for C++11, providing JSON parsing and serialization.

The main block is `here <https://www.biicode.com/lasote/json11>`_, which is generated from this `github repo <https://github.com/lasote/json11>`_

Simple convert data to json and vice versa 
--------------------------------------------

This example is `already in biicode <http://www.biicode.com/examples/json11>`_, it is very simple to build it, by just opening the block and building it.

.. code-block:: bash

   $ bii init json11
   $ cd json11
   $ bii open examples/json11
   $ bii cpp:build

The code of the example is like this:

.. code-block:: cpp

  	#include <string.h>
	#include <cstdio>
	#include <iostream>
	#include <sstream>
	#include "lasote/json11/json11.hpp"
	#include <cassert>
	#include <list>
	#include <set>
	#include <unordered_map>

	using namespace json11;
	using std::string;


	int main(int argc, char **argv) {
	    

	    // STRING TO JSON
	    const string simple_test =
		R"({"k1":"v1", "k2":42, "k3":["a",123,true,false,null]})";

	    string err;
	    auto json = Json::parse(simple_test, err);
	    std::cout << "k1: " << json["k1"].string_value() << "\n";
	    std::cout << "k3: " << json["k3"].dump() << "\n";

	    
	    // JSON FROM LITERAL
	    Json obj = Json::object({
		{ "k1", "v1" },
		{ "k2", 42.0 },
		{ "k3", Json::array({ "a", 123.0, true, false, nullptr }) },
	    });

	    std::cout << "obj: " << obj.dump() << "\n";

	    // CUSTOM CLASS JSON ENCODE
	    class Point {
	    public:
		int x;
		int y;
		Point (int x, int y) : x(x), y(y) {}
		Json to_json() const { return Json::array { x, y }; }
	    };

	    std::vector<Point> points = { { 1, 2 }, { 10, 20 }, { 100, 200 } };
	    std::string points_json = Json(points).dump();
	    printf("%s\n", points_json.c_str());
	}

Now, run the example.

.. code-block:: bash

   $ bin/examples_json11_test


As you can see with this library you can create json objects from string literals, standard collections and even custom classes in an easy way!

.. code-block:: bash

	k1: v1
	k3: ["a", 123, true, false, null]
	obj: {"k1": "v1", "k2": 42, "k3": ["a", 123, true, false, null]}
	[[1, 2], [10, 20], [100, 200]]

