.. _cpp_publish_reuse:


Upload and reuse code
=====================

So in the previous step, we have integrated Google Test in our project, testing a simple **sum** function.

Can I do the same with my source code? Of course, that is exactly what biicode does! The only requisite for this it that you have to |biicode_signup|. It is completely **free**, and it will just take two minutes.


.. |biicode_signup| raw:: html
   
   <b><a href="https://www.biicode.com/accounts/signup" target="_blank">register an account</a></b>


1. Write reusable code
----------------------
In the previous step, we had the folder **myuser/myblock**. 
Now we can **rename "myuser" folder with the user name we have used in the signup**. 
In the examples we will keep **"myuser"** as the username, but please don't forget to replace its occurences for your real username.

It is also a good idea to **rename "myblock" folder** to something more meaningful,
lets imagine that we are building some mathematical library, so we rename it with **math**

Finally, good practices tell us that a good design for reusing our code later,
would be having the **sum** function in its own files:


**main.cpp**

.. code-block:: cpp

  #include "google/gtest/gtest.h"
  #include "operations.h"
  
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }


**operations.h**

.. code-block:: cpp

  #pragma once
  int sum(int a, int b);


**operations.cpp**

.. code-block:: cpp

  #include "operations.h"
  int sum(int a, int b) {return a+b;}

The final layout should be:

.. code-block:: text

  +-- myproject
    |    +-- blocks
    |    |    +-- myuser (remember: your actual username here)
    |    |    |    +-- math
    |    |    |    |    +-- main.cpp
    |    |    |    |    +-- operations.cpp
    |    |    |    |    +-- operations.h


Build with ``bii cpp:build`` and run your project again to check everything is ok.

.. code-block:: bash

   ~/myproject$ bii cpp:build
   ~/myproject$ bin\myuser_math_main  (your username here instead of myuser)
   ...
   [==========] 1 test from 1 test case ran. (2 ms total)
   [  PASSED  ] 1 test.


2. Upload your code
-------------------

**Publishing** your source code to biicode is simple:

.. code-block:: bash

   ~/myproject$ bii publish

This should upload your code to the servers, you can see it in your profile **www.biicode.com/myuser**

You have published your code as **DEV**  which means that such code is for your own development and testing. 
Possible tags are **DEV, ALPHA, BETA, STABLE**.

**DEV** publications are not freezed, every time you publish **you overwrite the last version**.


Check inside of your **block bii folder** (~/myproject/blocks/myuser/math/bii), the file **parents.bii**.
It tells you "who" is your parent (indicated with ``*`` symbol), i.e. the last published version of your block.
The file should contain:

.. code-block:: bash

   # This file contains your block ancestors versions
   * myuser/math: 0



3. Reuse your code
------------------
Once your code is in biicode, you can **reuse it in any project**, even in a different computer. Let's **create a new project to try it**.

Let's imagine that we are building a calculator and we want to reuse the published **sum** function

.. code-block:: bash

   ~/myproject$ cd ..  (get out of current project)
   ~$ bii init mycalc   (create new project mycalc)
   ~$ cd mycalc
   ~/mycalc$ bii new myuser/calc --hello=cpp

Now change the **main.cpp** file created with the following content

.. code-block:: cpp

   #include <iostream>
   #include "myuser/math/operations.h" //NOTE: Replace myuser!

   using namespace std;
   int main() {
      cout<<"2 + 3 = "<< sum(2, 3)<<endl;
   }


In the "getting started" we used ``bii find`` to let biicode find a suitable (compatible) version of our dependencies. 
You can also directly and explicitly specify them in the **bii/requirements.bii** file. 
In this example you depend on your published block **myuser/math**, and it only has one version (number 0). 

Create a folder named **bii** inside your ``~/mycalc/blocks/myuser/calc/`` and a **requirements.bii** file located in it.

.. code-block:: text

  +-- mycalc
    |    +-- blocks
    |    |    +-- myuser
    |    |    |    +-- calc
    |    |    |    |    +-- bii
    |    |    |    |    |    +-- requirements.bii
    |    |    |    |    +-- main.cpp

Open the **requirements.bii** with any text editor and write in it:

.. code-block:: bash

   myuser/math: 0


After that, all you have to do is to build and run your application:

.. code-block:: bash

   ~/mycalc$ bii cpp:build
   ~/mycalc$ bin\myuser_calc_main
    2 + 3 = 5


.. container:: infonote

   Take one minute to look into your **deps** folder. You can see there your source code. And what about Google Test? Shouldn't it be there? Not really. The **sum** function does not require Google Test at all, so Google Test is not required as dependency in your new calculator project (unless you also add it to define your own unit tests of this calculator, of course)



Congrats! You have just reused your **sum** function in a new project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feeback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


