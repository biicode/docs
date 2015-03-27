OpenCV
======

`OpenCV (Open Source Computer Vision Library) <http://opencv.org/>`_ is a great open source computer vision and machine learning software library. OpenCV was built to provide a *common infrastructure for computer vision* applications and to accelerate the use of machine perception in the commercial products.

The versions of OpenCV library at biicode are:
	
	* OpenCV 2.4.10 at `diego/opencv <http://www.biicode.com/diego/opencv>`_.

	* OpenCV 3.0 beta at `diego/opencv (beta) <http://www.biicode.com/diego/diego/opencv/beta>`_.

Both versions are available at biicode using the :ref:`hooks feature <hooks_conf>` generated from this `github repo <https://github.com/drodri/opencv-biicode>`_. 

In this example we'll show how to get started with OpenCV using two features: showing an image and detecting faces with the `object detection module <http://docs.opencv.org/ref/master/d2/d64/tutorial_table_of_content_objdetect.html>`_.

Showing an image and detecting faces
------------------------------------

In this example we'll show how to get started with OpenCV using two features: showing an image and detecting faces with the `object detection module <http://docs.opencv.org/ref/master/d2/d64/tutorial_table_of_content_objdetect.html>`_.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a project and place the source files and images inside:

.. code-block:: bash

 $ bii init opencv_sample -L
 $ cd opencv_sample
 $ # copy all following files inside

* Showing an image:

 **main.cpp**

 .. literalinclude:: /_static/code/cpp/examples/opencv/main.cpp
    :language: cpp
    :linenos:

 Download file: :download:`bii.png </_static/img/c++/examples/bii.png>`.

* Object detection example uses a CascadeClasifier class and a xml file with the algorithm to detect faces.

 **mainface.cpp**

 .. literalinclude:: /_static/code/cpp/examples/opencv/mainface.cpp
    :language: cpp
    :linenos:

 Download files: :download:`hugh.png </_static/img/c++/examples/hugh.png>`, :download:`haarcascade_eye_tree_eyeglasses.xml </_static/code/cpp/examples/opencv/haarcascade_eye_tree_eyeglasses.xml>`, :download:`haarcascade_frontalface_alt.xml </_static/code/cpp/examples/opencv/haarcascade_frontalface_alt.xml>`.

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 INFO: Processing changes...
 examples/mycvproject depends on:
       system:
          iostream
          stdio.h
       unresolved:
          opencv/cv.h
          opencv/highgui.h
          opencv2/highgui/highgui.hpp
          opencv2/imgproc/imgproc.hpp
          opencv2/objdetect/objdetect.hpp

Edit *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]`` and your ``[data]``:

.. code-block:: text

 [requirements]
     diego/opencv: 2
 
 [includes]
    opencv/*: diego/opencv
    opencv2/*: diego/opencv
 
 [data]
    main.cpp + opencv_bii.png
    mainface.cpp + haarcascade_frontalface_alt.xml haarcascade_eye_tree_eyeglasses.xml opencv_hugh.png

Now, checking **bii deps**, your dependencies are resolved.


Build the project
^^^^^^^^^^^^^^^^^

Now execute **bii build** to build the project.

.. container:: infonote

 Windows users need Visual Studio. Execute:

 .. code-block:: bash 

     $ bii configure -G "Visual Studio 12"

.. code-block:: bash
 
 $ bii build

Go to bin directory and execute the binaries:

.. code-block:: bash
 
 $ cd bin
 $./youruser_opencv_sample_main

.. image:: /_static/img/c++/examples/opencv_bii.png

.. code-block:: bash
 
 $./youruser_opencv_sample_mainface

.. image:: /_static/img/c++/examples/opencv_hugh.png

Open and build
--------------

This example is already in biicode at `examples/opencv_sample <http://www.biicode.com/examples/opencv_sample>`_, so you can give it a try.

Create a new project and open the block:

.. code-block:: bash

 $ bii init mycvproject
 $ cd mycvproject
 $ bii open examples/opencv_sample

Just build and run both examples:

.. code-block:: bash

 $ bii build
 $./youruser_opencv_sample_main
 $./youruser_opencv_sample_mainface


Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.