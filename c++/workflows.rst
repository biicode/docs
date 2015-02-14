.. _cpp_workflows:


Workflows
==========

Working with your own blocks
------------------------------

You've built a program and reused your **sum function** in the :ref:`Getting Started <cpp_getting_started>`. Now it's time to add new functionality to your published **myuser/math** block, like a **subtract function**, and use it in your block **myuser/calc**.

The layout is:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    +-- deps
  |    |    +-- myuser
  |    |    |    +-- math
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h

Opening your block
^^^^^^^^^^^^^^^^^^^
Open the block **myuser/math** for editing on the same project, execute:

.. code-block:: bash

  ~/mycalc$ bii open myuser/math

``bii open command`` retrieves the complete block to your ``blocks`` folder, and deletes it from your ``deps`` folder.
In this case, it will open the specific version you depend on. 

The resulting layout is:

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Now, add the new function, **subtract** and use it on your main.cpp

**operations.h**

.. code-block:: cpp

   #pragma once
   int sum(int a, int b);
   int subtract(int a, int b);

**operations.cpp**

.. code-block:: cpp

   #include "operations.h"
   int sum(int a, int b) {return a+b;}
   int subtract(int a, int b){return a-b;}


**main.cpp**

.. code-block:: cpp

   #include "google/gtest/gtest.h"
   #include "operations.h"
   
   TEST(Sum, Normal) {
    EXPECT_EQ(5, sum(2, 3));
   }
   TEST(Subtract, Normal) {
    EXPECT_EQ(-1, subtract(2, 3));
   }
   int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
   }


Build, ``bii cpp:build`` and run your tests ``myuser_math_main`` to check everything is working.


Publishing updated code
^^^^^^^^^^^^^^^^^^^^^^^

Publish the math block again. As you now have 2 blocks opened (calc, math), specify the name of the block you want to publish:

.. code-block:: bash

   ~/mycalc$ bii publish myuser/math

By default, ``bii publish`` uses the DEV tag. Check on your online biicode profile it's been published.

Using ``DEV`` tag, the latest ``DEV`` version is overrided, so ``[parents]`` section of your **biicode.conf**  remains unmodified:

.. code-block:: text

  [parent]
     myuser/math: 0


Closing edited block
^^^^^^^^^^^^^^^^^^^^

You can now close **myuser/math** block, it and it will return, with the code already updated, to your ``deps`` folder:

.. code-block:: bash

   ~/mycalc$ bii close myuser/math


Then you can modify the content of your **myuser/calc**:

**main.cpp**

.. code-block:: cpp
   
   #include <iostream>
   #include "myuser/math/operations.h"
   
   using namespace std;
   int main() {
      cout<<"2 + 3 = "<< sum(2, 3)<<endl;
      cout<<"2 - 3 = "<< subtract(2,3)<<endl;
   }


and build it, reusing also the new function:

.. code-block:: bash

   ~/mycalc$ bii cpp:build
   ~/mycalc$ bin\myuser_calc_main
   2 + 3 = 5
   2 - 3 = -1

Congrats! You just edited your dependencies and updated the changes. 
You know that we are available at |biicode_forum_link| for any problems.
You can also |biicode_write_us| for suggestions and feedback, they are always welcomed.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>

.. _edit_dependecies:


Working with any published block
---------------------------------

To **edit a published block**, follow the steps below:

Open a block
^^^^^^^^^^^^

Open a block locally to modify and publish a new version of a block.

.. code-block:: bash

  ~/$ bii init myproject
  ~/$ cd myproject
  ~/myproject$ bii open username/blockname:VERSION


**Example**

Let's open |example_block| (version=lastest by default) to edit it:

.. |example_block| raw:: html

   <a href="http://www.biicode.com/lasote/json11" target="_blank">lasote/json11 block</a>

.. code-block:: bash

  $ bii open lasote/json11 

Then you can code on it as if it was yours and changes will be reflected in your code, at build time.

Suppose that you want to open version ``1`` instead of the latest ``lasote/json11`` version, you should execute: 

.. code-block:: bash

  $ bii open lasote/json:1


Publish the changes
^^^^^^^^^^^^^^^^^^^

Once your changes build, publish your own version of the block. 

If **the block in edition isn't yours**:

  * Rename **lasote** folder with your **username**. 
  * Delete the ``[parents]`` section content in your **biicode.conf** file.

.. container:: infonote

    Remember to ``bii cpp:build`` before publishing!

And publish:

.. code-block:: bash

  $ bii publish  

.. container:: infonote
  
  Check :ref:`bii:publish command<bii_publish_command>` to know more.


Close the block
^^^^^^^^^^^^^^^

Then you can close the block to remove it from your blocks folder:

.. code-block:: bash

  $ bii close user_name/block_name

If you're following the **Example**, execute:

.. code-block:: bash

  $ bii close user_name/json11


Depend on the block you've just published
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Now, if you want to depend on the block you've just published:

  * Update your #include (s) to the ones referring to your new published version
  * If you didn't publish it as STABLE, do it or update your :ref:`policies.bii <policies>` file to accept DEV versions.
  * Execute ``bii find`` and you're ready to build as usual. Here's :ref:`bii find command documentation<bii_find_command>`.


.. container:: infonote

  If you need more information about publish or close command:

  * :ref:`Publish command <bii_publish_command>`
  * :ref:`Close command <bii_close_command>`


Working with Git (or other VCS)
-----------------------------------

Biicode does not intend to be version control system. We recommend you using a control version system so you can keep your code safe and versioned.
You can use also SVN or CVS.   


Versioning your code
^^^^^^^^^^^^^^^^^^^^

The natural way to work is maintaining a correspondence between a *biicode block* and a *Git repository*.
Simply go to your block folder (**calc** and **math** in the previous example) and initialize a new git repository.

.. code-block:: text

  +-- mycalc
  |    +-- blocks
  |    |    +-- myuser
  |    |    |    +-- calc
  |    |    |    |    +-- main.cpp
  |    |    |    +-- math
  |    |    |    |    +-- main.cpp
  |    |    |    |    +-- operations.cpp
  |    |    |    |    +-- operations.h
  |    +-- deps

Go to the block's folder and initialize the git repository. Then add the changes to index and commit them:

.. code-block:: bash

  $ cd mycalc/blocks/myuser/calc
  $ git init .
  $ git add .
  $ git commit -m "Added new operation to operations.cpp"

You can also add a remote repository:

.. code-block:: bash

  $ git remote add origin https://github.com/user/repo.git

And push your commits: 

.. code-block:: bash

  $ git push origin master


.. container:: infonote
    
  You can learn more about adding remote repositories on |github_remote| or on |bitbucket_remote|. 


.. container:: infonote
    
  You can push to git the whole biicode project folder if you want to keep the building folder and project configuration. But, generally it's not necessary or recommended. Each computer may need their specific project settings, ant the you can regenerate all build layout with ``bii cpp:configure`` or ``bii cpp:build`` command. 


As usual, you can publish your code to biicode when you want to, generally when you have a version to share.

.. code-block:: bash

  $ bii publish

That's all! Now you have your code under version control.


Ignoring files
_______________

Maybe you want to have all files on git, but there are some files you don't want to publish to biicode.
Use :ref:`ignore.bii file<ignore_bii>` to specify which files should be ignored and not published to biicode.


Work with published blocks
^^^^^^^^^^^^^^^^^^^^^^^^^^^ 

In previous sections, it's explained how to work with any published block just using biicode (you would run ``bii open`` command). 

Well, that's still available, but when working with Git, it's best to ``clone`` the github repository.

Let's see an example:

User ``mike`` has pushed to github and published a block named ``mike/math`` to biicode. 
He was working at home, with Linux.

Next day Mike wants to develop further his block at work, with Windows.
If Mike executes ``bii open`` the source code is not a github repository, is only a copy of his block in biicode. 
So Mike should better init a new biicode project and run:

.. code-block:: bash

  $ bii init work_project
  $ cd work_project
  $ bii new mike/math
  $ cd blocks/mike/math
  $ git clone https://github.com/mike_on_github/math.git .

Now Mike has the github repository to continue developing his biicode block under a control version system.
From now, Mike just needs to make ``git pull`` command to fetch and merge the remote changes.


Travis integration
^^^^^^^^^^^^^^^^^^^^^

You can automate the publication to biicode when you push your code to github.
Check this awesome |blog_post| to know how. 


**Got any doubts?** Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.


.. |github_remote| raw:: html
    
    <a href="https://help.github.com/articles/adding-a-remote/" target="_blank">github here</a>


.. |bitbucket_remote| raw:: html
    
    <a href="https://confluence.atlassian.com/display/BITBUCKET/Create+a+repository" target="_blank">bitbucket here</a>


.. |blog_post| raw:: html

    <a href="http://blog.biicode.com/automatically-build-publish-via-travis-ci-github/" target="_blank">blog post here</a>
