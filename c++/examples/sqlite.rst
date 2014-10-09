SQLite
======

SQLite is a software library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine. SQLite is the most widely deployed SQL database engine in the world. For more information about this library, visit their `official website <http://www.sqlite.org/>`_.

You can find here the `SQLite library site <http://www.biicode.com/sqlite/sqlite/sqlite/master/5>`_ .

Hello SQLite Example
^^^^^^^^^^^^^^^^^^^^
This example creates a database called LIST in which stores information about your shopping list. Take a deep look into the code in order to understand how it works and make your own one soon!

How to replicate
-----------------
This example is `already in biicode <http://www.biicode.com/examples/sqlite_basic>`_, it's simple to run, just open the block and build it like this:

.. code-block:: bash

   $ bii init sql
   $ cd sql
   $ bii open examples/sqlite_basic
   $ bii cpp:build

The code of the example is this one:

.. code-block:: cpp

	#include <stdlib.h>
	#include <sqlite/sqlite/sqlite3.h>
	#include <string>
	#include <stdio.h>
	 
	using namespace std;
	 
	static int select_callback(void *data, int argc, char **argv, char **azColName){
	   int i;
	   for(i=0; i<argc; i++){
	    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	   }
	   printf("\n");
	   return 0;
	}
	void execute_sql(sqlite3 *db, string zSql, sqlite3_callback xCallback, void *pArg){
	 
	    int  rc;
	    char *pzErrMsg = 0;
	    rc = sqlite3_exec(db, zSql.c_str(), xCallback, pArg, &pzErrMsg);
	    if( rc != SQLITE_OK ){
	    fprintf(stderr, "SQL error: %s\n", pzErrMsg);
	        sqlite3_free(pzErrMsg);
	    }
	}
	 
	void connect(sqlite3 **db){
	    int  rc;
	    rc = sqlite3_open("test.db", db);
	    if( rc ){
	        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(*db));
	        exit(0);
	    }else{
	        fprintf(stdout, "Opened database successfully\n");
	    }
	}
	 
	int main(int argc, char* argv[])
	{
	    sqlite3 *db;
	    sqlite3_callback void_callback;
	    string query;
	 
	    /* Open database */
	    connect(&db);
	 
	    query = "CREATE TABLE IF NOT EXISTS LIST (STORE CHAR(50),NAME TEXT NOT NULL UNIQUE, NUMBER INT);";
	    execute_sql(db, query, void_callback, 0);
	 
	    query = "INSERT OR REPLACE INTO LIST (STORE, NAME, NUMBER) VALUES ('Veggies', 'Spinach', 3);"\
	        "INSERT OR REPLACE INTO LIST (NUMBER, STORE, NAME) VALUES (7,'Drinks', 'Coffee');"\
	        "INSERT OR REPLACE INTO LIST (NAME, STORE, NUMBER) VALUES ('Onion', 'Veggies', 1);";
	    execute_sql(db, query, void_callback, 0);
	 
	    printf("\nSELECT, List Veggies\n\n");
	    query = "SELECT * from LIST where STORE='Veggies'";
	    execute_sql(db, query, select_callback, 0);
	    
	    printf("\nSELECT, List Drinks\n\n");
	    query = "SELECT * from LIST where STORE='Drinks'";
	    execute_sql(db, query, select_callback, 0);
	    
	    query = "UPDATE LIST set NUMBER = 2 where NAME='Coffee'";
	    execute_sql(db, query, void_callback, 0);
	    
	    query = "DELETE from LIST where NAME='Spinach';";
	    execute_sql(db, query, void_callback, 0);

	    printf("\nSELECT, Updated Lists:\n\n");
	        query = "SELECT * from LIST";
	    execute_sql(db, query, select_callback, 0);
	 
	    /* Close database */
	    sqlite3_close(db);
	    fprintf(stdout, "Closed database successfully\n");


	 
	    return 0;
	}


Now, run the hello example.

.. code-block:: bash

   $ bin/examples_sqlite_basic_main.exe

You can see the results of the queries in the output:

  
.. code-block:: bash
   

		SELECT, List Veggies

		STORE = Veggies
		NAME = Spinach
		NUMBER = 3

		STORE = Veggies
		NAME = Onion
		NUMBER = 1


		SELECT, List Drinks

		STORE = Drinks
		NAME = Coffee
		NUMBER = 7


		SELECT, Updated Lists:

		STORE = Drinks
		NAME = Coffee
		NUMBER = 2

		STORE = Veggies
		NAME = Onion
		NUMBER = 1

		Closed database successfully



Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
  
SQLite++ Wrapper
^^^^^^^^^^^^^^^^
The following example how-to use the SQLite++ wrapper. You can find this example in `the biicode SQLite samples block <http://www.biicode.com/examples/sqlite>`_ .

**main.cpp**

.. literalinclude:: /_static/code/cpp/examples/sqlite/main.cpp
   :language: cpp
   :linenos:

**Download:**
:download:`sqlite_example.zip </_static/code/cpp/examples/sqlite/sqlite_example.zip>`

Create a block:

.. code-block:: bash

	$ bii init my_project
	$ cd my_project
	$ bii new examples/sqlite


Unzip those files in your block, then you need to resolve all the dependencies of this ``main.cpp``. Then you can compile it

.. code-block:: bash

	$ bii find
	$ bii cpp:build


You will see next console output after executing the command:

.. code-block:: bash

	$ cd bin
	$ bin $ ./examples_sqlite_main
	SQLite database file 'examples/sqlite/example.db3' opened successfully
	SQLite table 'test' exists=1
	execAndGet=second line
	SQLite statement 'SELECT id as test_id, value as test_val, weight as test_weight FROM test WHERE weight > ?' compiled (3 	columns in the result)
	binded with integer value '2' :
	aliased result ["test_id", "test_val", "test_weight"]
	row (1, "first word" 10 bytes, 2.3)
	row (2, "second line" 11 bytes, 6.7)
	row (3, "and a last one" 14 bytes, 9.5)
	row (4, "" 0 bytes, 18)
	...
