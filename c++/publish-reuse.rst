.. _cpp_publish_reuse:


Upload and reuse code
=========================

So in the previous step, we have integrated Google Test in our project, testing a simple **sum** function. Can I do the same with my source code? Of course, that is exactly what biicode does! 
The only requisite for this it that you have to |biicode_signup|. It is completely **free**, and it will just take two minutes.


.. |biicode_signup| raw:: html
   
   <b><a href="https://www.biicode.com/accounts/signup" target="_blank">register an account</a></b>


1. Write reusable code
-------------------------------------
In the previous example, we created folders **username/myblock**. 

Software good practices tell us that a good design for reusing our code later is having, in this case, a **sum** function separated in its own reusable files. Add the following files to the folder ``myproject/blocks/username/myblock``:

**main.cpp**

.. code-block:: cpp

  #include "google/gtest/gtest.h"
  #include "addition.h"
  TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
  }
  int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }


**addition.h**

.. code-block:: cpp

  #pragma once
  int sum(int a, int b);


**addition.cpp**

.. code-block:: cpp

  #include "addition.h"
  int sum(int a, int b) {return a+b;}

The final layout should be:

.. code-block:: text

  +-- myproject
    |    +-- blocks
    |    |    +-- username
    |    |    |    +-- myblock
    |    |    |    |    +-- main.cpp
    |    |    |    |    +-- addition.cpp
    |    |    |    |    +-- addition.h

:underline:`Replace` ``username`` with your actual biicode user name.
It is also a good idea to rename ``myblock`` for something more meaningful, so we're changing it to ``math``.

Build with ``bii cpp:build`` and run your project again to check everything is ok.

.. code-block:: bash

   ~$ cd math
   ~math$ bii cpp:build


2. Upload your code
-------------------------------------

Publishing your source code to biicode is simple:

.. code-block:: bash

   ~math$ bii publish

This should upload your code to the servers, you can browse it in your profile: **https://www.biicode.com/username** (block math, version number 0). 

You just published your code as DEV (one of the possible publishing tags: DEV, ALPHA, BETA, STABLE) which means that such code is for your own development and testing. Take into account that each time you publish as DEV it overwrites the last version published.


3. Reuse your code
-------------------------------------
Once your code is in biicode, you can reuse it in any project, even in a different computer. **Let's create a new project** to try it, imagine that we are building a calculator and we will reuse from the already programmed **sum** function:

.. code-block:: bash

  ~myproject$ cd ..
  ~$ bii init mycalc
  ~$ cd mycalc
  ~mycalc$ bii new username/calc --hello=cpp

Now change the **main.cpp** file created with the following content, remember to substitute ``username`` with your biicode user name and ``math`` with your **published block's name**.

.. code-block:: cpp

  #include <iostream>
  #include "username/math/addition.h"

  using namespace std;
  int main() {
    cout<<"2 + 3 = "<< sum(2, 3)<<endl;
  }

In the "getting started" we used ``bii find`` to let biicode find a suitable (compatible) version of our dependencies. You can also directly specify which are our dependencies. In this example you depend on your published block **username/math**, and it only has one version (number 0). So you can write in the **bii/requirements.bii** file:

.. code-block:: text

  username/math: 0

After that, all you have to do is to build and execute your project:

.. code-block:: bash

  ~mycalc$ bii cpp:build
  ~mycalc$ cd bin
  ~bin$ username_calc_main
  2 + 3 = 5


.. container:: infonote

  Take one minute to look into your **deps** folder. You can see there your source code. And what about Google Test? Shouldn't it be there? Not really. The **sum** function does not require Google Test at all, so Google Test is not required as dependency in your new calculator project (unless you also add it to define your own unit tests of this calculator, of course)


Congrats! You have just reused your **sum** function in a new project. You know that we are available at |biicode_forum_link| for any problems. You can also |biicode_write_us| for suggestions and feeback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>


