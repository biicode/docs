SQLite
======

SQLite is a software library that implements a self-contained, serverless, zero-configuration, transactional SQL database engine. SQLite is the most widely deployed SQL database engine in the world.

For more information about this library, visit their `official website <http://www.sqlite.org/>`_.

You can find `SRombauts' C++ SQLite3 wrapper library <https://github.com/SRombauts/SQLiteCpp>`_ at `sqlite/sqlite <http://www.biicode.com/sqlite/sqlite/sqlite/master/5>`_ and plain SQLite is at `fenix/sqlite <https://www.biicode.com/fenix/sqlite>`_.

Shopping list database
----------------------
This example uses SQLiteC to create a database called LIST in which stores information about your shopping list. Take a deep look into the code in order to understand how it works and make your own one soon!

Creating a project
^^^^^^^^^^^^^^^^^^

Create a new project with a simple layout and place the code inside.

.. code-block:: bash

   $ bii init sqlite_basic -L
   $ cd sqlite_basic
   $ # create shopping_db.cpp and copy its content

**shopping_db.cpp**

.. code-block:: cpp
   :emphasize-lines: 2

	#include <stdlib.h>
	#include <sqlite3.h>
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

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 your_user/sqlite_basic depends on:
       system:
          stdio.h
          stdlib.h
          string
       unresolved:
          sqlite3.h

Edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     sqlite/sqlite: 8
 
 [includes]
     sqlite3.h: sqlite/sqlite/sqlite3

Check again with **bii deps** to show all dependencies are now resolved.

Build the project
^^^^^^^^^^^^^^^^^

Build the *shopping_db.cpp* and execute it.

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # execute it!

You can see the results of the queries at the output:
  
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
  
SQLite++ Wrapper
----------------
`The following example from SRombauts <https://github.com/SRombauts/SQLiteCpp/tree/master/examples/example1>`_, explains how-to use the SQLite++ wrapper. Following the previous example, we'll develop this in the same project's folder.

Jus place *main.cpp*, *example.db3* and *logo.png* files inside:

**sqlite_basic/main.cpp**

.. literalinclude:: /_static/code/cpp/examples/sqlite/main.cpp
   :language: cpp
   :emphasize-lines: 17

Download: :download:`example.db3 </_static/code/cpp/examples/sqlite/example.db3>`, :download:`logo.png </_static/img/c++/examples/logo.png>`.

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check again with **bii deps** and edit the *biicode.conf* file.

.. code-block:: text

 [requirements]
     sqlite/sqlite: 8
 
 [includes]
     sqlite3.h: sqlite/sqlite/sqlite3
     SQLiteCpp/*: sqlite/sqlite/include

 [data]
     main.cpp + examle.db3 logo.png

Build the example
^^^^^^^^^^^^^^^^^

Compile it and run the executable by doing:

.. code-block:: bash

	$ bii build
	$ cd bin
	$ # run executable

You will see next console output:

.. code-block:: bash

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

Open and build
--------------
This examples are already in biicode at `examples/sqlite_basic <http://www.biicode.com/examples/sqlite_basic>`_ and `examples/sqlite <http://www.biicode.com/examples/sqlite>`_.

This is a way to give them a quick look and check how it works.

Both examples are simple to run, just open the blocks and build them like this:

.. code-block:: bash

   $ bii init sqlite_project
   $ cd sqlite_project
   $ bii open examples/sqlite_basic
   $ bii open examples/sqlite
   $ bii build

Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.
