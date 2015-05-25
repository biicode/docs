.. _sdl:

SDL
===

`SDL: Simple DirectMedia Layer <http://www.libsdl.org/>`_ is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.  

SDL library is stored at `miguel/sdl2 <https://www.biicode.com/miguel/sdl2/master>`_.

Graphical window interface
--------------------------

In this example you will open a new graphical window and load a background texture.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new project and a *main_sdl.cpp* file:

.. code-block:: bash

   $ bii init sdl_example -L
   $ cd sdl_example
   $ # Create main_sdl.cpp

Now place the following code inside *main_sdl.cpp*:

**main_sdl.cpp**

.. code-block:: cpp

  #include "SDL.h"
  #include <iostream>

  int main(int argc, char *argv[])
  {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
      std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
      return 1;
    }

    SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    SDL_Renderer *ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_Surface *bmp = SDL_LoadBMP("examples/sdl_example/media/sdl.bmp");

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, bmp);
    SDL_FreeSurface(bmp);

    if (tex == nullptr)
    {
      SDL_DestroyRenderer(ren);
      SDL_DestroyWindow(win);
      std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
      SDL_Quit();
      return 1;
    }

    //Wait for 3 seconds and render and present the screen each time
    for (int i = 0; i < 3; ++i)
    {
      //First clear the renderer
      SDL_RenderClear(ren);
      //Draw the texture
      SDL_RenderCopy(ren, tex, NULL, NULL);
      //Update the screen
      SDL_RenderPresent(ren);
      //Take a quick break
      SDL_Delay(3000);
    }

  SDL_DestroyTexture(tex);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();

}

Now, add a cool background .bmp like `this one <http://squarebitstudios.tk/files/0002/sdl.bmp>`_ to a new folder "**media**" and link it with your *main_sdl.cpp* file in *biicode.conf* ``[data]`` section like this:

.. code-block:: text

 [data]
     main_sdl.cpp + media/sdl.bmp

Now, change your path to the file in your code:

.. code-block:: cpp
 
 SDL_Surface *bmp = SDL_LoadBMP("your_user/sdl_example/media/sdl.bmp"); //Replace "your_user"!


Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 your_user/sdl_example depends on:
       system:
          iostream
       unresolved:
          SDL.h

Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]`` to point to ``miguel/sdl2/include/SDL.h``:

.. code-block:: text

 [requirements]
     miguel/sdl2: 3
 
 [includes]
     SDL.h: miguel/sdl2/include


Check again with **bii deps** and now all dependencies are solved.

Activating C++11
^^^^^^^^^^^^^^^^

Building your project like this throws the next error:

..  code-block:: bash
 
 $ bii build
  ...
  C:\...\sdl_example\main_sdl.cpp:21:13: error: 'nullptr' was not declared in this scope
  if (tex == nullptr)
             ^

So we have to activate C++11 support. With biicode you can reuse cmake macros, so we'll use this one: `biicode/cmake/tools.cmake <https://www.biicode.com/biicode/biicode/cmake/master/4/tools.cmake>`_. It is very easy.

* Edit *CMakeLists.txt* and write:

 ..  code-block:: cmake
   
   # Including tools.cmake from biicode/cmake user block
   INCLUDE(biicode/cmake/tools)

   ADD_BII_TARGETS()

   # Calling specific macro to activate c++11 flags
   ACTIVATE_CPP11(INTERFACE ${BII_BLOCK_TARGET})

* Type **bii find** and all is done!

..  code-block:: bash
 
 $ bii find
 INFO: Processing changes...
 INFO: Finding missing dependencies in server
 INFO: Looking for biicode/cmake...
 ...
 INFO: Saving files from: biicode/cmake

Build the project
^^^^^^^^^^^^^^^^^

The only thing left is building the project:

.. code-block:: bash

  $ bii build

Execute the binary placed in bin directory and this is how output looks like:

.. code-block:: bash

  $ cd bin
  $ ./your_user_sdl_example_main_sdl

Here is the result:

.. image:: /_static/img/c++/examples/sdl_example.png


That's it!

Open and build
--------------

This example is already in biicode: `examples/sdl_example <https://www.biicode.com/examples/sdl_example>`_.

To give it a try, create a new project and open the block:

.. code-block:: bash

 $ bii init sdl_project
 $ cd sdl_project
 $ bii open examples/sdl_example

Build the example and execute it:

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # Execute it

You will see your the above graphical window with SDL background texture.

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_, visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.