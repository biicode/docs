.. _override_deps:

Override a dependency
----------------------

Let's say you depend on: 

* ``erincatto/box2d:10`` that depends on ``diego/glfw:0``. 

|

And you'd rather depend on:

*  ``erincatto/box2d:10`` and ``diego/glfw:1``. 

|

Write your preferred versions in your **biicode.conf** and biicode will use those versions in your project: 

.. code-block:: text

  [requirements] 
    # required blocks (with version)
    erincatto/box2d: 10
    diego/glfw:1

Execute **bii build** and it's updated.


Override a dependency with block tracks
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Create a block track when you need a personalized fix over the original library**.

Let's create a block track from **diego/glfw** block:

* Open the block:

.. code-block:: bash

  ~$ bii init myproject
  ~$ cd myproject
  ~/myproject$ bii open diego/glfw

* Code, adjust it to your needs.

* Write the track name between brackets in the ``[parent]`` section of the **biicode.conf** file. Specify ``version -1`` because we want create a new block. 

*biicode.conf*

.. code-block:: text

  [parent]
      diego/glfw(myuser/glfw): -1

* Execute ``bii publish`` and enter your profile *www.biicode.com/myuser* to check the new track. 

**Depend on that new block track:**

* Write in your **biicode.conf** file ``[requirements]`` :

    *biicode.conf*

    .. code-block:: text

      [requirements] 
        # required blocks (with version)
        diego/glfw(myuser/glfw): 1

* Execute ``bii build`` and it's updated.

.. container:: infonote

    What if you want to get back again to the original library? 
      
    * Write in your **biicode.conf** file ``[requirements]`` :

      .. code-block:: text

        [requirements] 
            # required blocks (with version)
          diego/glfw: 0
    
