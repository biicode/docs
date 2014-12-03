.. _arduino_installation:

Installation
============

**Biicode** is a file-oriented Dependencies Manager for C and C++ developers. Install both 
Biicode and the Arduino tools to get started.

.. _download_client_binaries:

Install Biicode
-----------------

**Download** `Biicode Installer <https://www.biicode.com/downloads>`_ and double-click the downloaded package to install it.

Open the terminal and **make sure biicode is installed**:


.. code-block:: bash

   ~$ bii --version

.. container:: infonote

    Check alternative installations for:

    *  :ref:`Debian based distrobutions <alternative_install_debian>`
    *  :ref:`Arch based distrobutions <alternative_install_archlinux>`


Install Arduino tools
-----------------------

To start, install required tools like CMake or GCC:

        .. code-block:: bash

           $ bii setup:arduino


Avoid Arduino's SDK installation if you've got it installed already. Re-run ``bii setup:arduino`` command to verify everything is installed.

**Any issues**, `contact us at our forum <http://forum.biicode.com/category/arduino>`__, and feel free to ask any questions. 


Install Arduino tools manually
-------------------------------
Install, set up and verify some **tools to build Arduino projects with biicode**. 

Follow these steps if something failed during the automatic installation explained before. If you experience any issues, please `contact us at our forum <http://forum.biicode.com/category/client>`_, we'll try to solve your problem as soon as possible.

.. container:: tabs-section
    
    .. _arduino_cmake_linux:
    .. container:: tabs-item

        .. rst-class:: tabs-title
            
            Linux

        Install the required development tools as root:

        .. code-block:: bash

            $ sudo apt-get install build-essential cmake

        That's all!

    .. _arduino_cmake_mac:
    .. container:: tabs-item

        .. rst-class:: tabs-title
            
            MacOS

        You need to get installed both XCode Developer Tools and CMake:

        #. The XCode Developer Tools

           .. code-block:: bash

            $ xcode-select --install


        #. Download and install `CMake 3.0.2 version <http://www.cmake.org/cmake/resources/software.html>`_ for your Mac OSX.

    .. _arduino_cmake_win:
    .. container:: tabs-item

        .. rst-class:: tabs-title

            Windows

        1. Download and install CMake. You can `download the latest version of CMake here <http://www.cmake.org/cmake/resources/software.html>`_.

        3. Add to your user ``PATH`` environment variable the path to CMake. We recommend `Rapid Environment Editor <http://www.rapidee.com/>`_ for editing environment variables. Otherwise, go to **My Computer**, click **Properties**, click **Advanced System Settings** and in the System Properties window click the **Environment Variables** button. then you will see a new window and in **User Variables** you'll find the variable ``PATH``:

           .. image:: /_static/img/cpp_windows_path.png

        Add CMake binaries folders (i.e. ``C:\Program Files (x86)\CMake 2.8\bin``).

        You might need to close and open again any ``cmd`` windows in order to load the new value for the ``PATH`` variable.


Now, you can check CMake is working properly. Open a terminal window and run the following command. If the output message looks similar to this, CMake is successfully installed.

.. code-block:: bash

    $ cmake --version
    cmake version [version]

Install Arduino SDK manually
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
`Download the Arduino software <http://arduino.cc/en/Main/Software>`_ first, it is important to choose a SDK compatible with your board. If you need more info visit the `official Arduino website <http://arduino.cc/en/Main/Software>`_.

If you have any questions, we are available at |biicode_forum_link|. You can also |biicode_write_us| for suggestions and feedback.

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">biicode's forum</a>
 

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">write us</a>
