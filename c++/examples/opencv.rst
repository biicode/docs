OpenCV
======

`OpenCV (Open Source Computer Vision Library) <http://opencv.org/>`_ is a great open source computer vision and machine learning software library. OpenCV was built to provide a *common infrastructure for computer vision* applications and to accelerate the use of machine perception in the commercial products.

The versions of OpenCV library at biicode are:
	
	* `OpenCV 2.4.10 <http://www.biicode.com/diego/opencv>`_

	* `OpenCV 3.0 beta <http://www.biicode.com/diego/diego/opencv/beta>`_

Both versions are available at biicode using the :ref:`hooks feature <hooks_conf>` generated from this `github repo <https://github.com/drodri/opencv-biicode>`_. 

In this example we'll show how to get started with OpenCV using two features: showing an image and detecting faces with the `object detection module <http://docs.opencv.org/ref/master/d2/d64/tutorial_table_of_content_objdetect.html>`_.

Open the examples
-----------------

This example is already in biicode, `check it out <http://www.biicode.com/examples/opencv_sample>`_!

.. code-block:: bash

 $ bii init mycvproject
 $ cd mycvproject
 $ bii open examples/opencv_sample

.. container:: infonote

 Windows users need Visual Studio. Execute:

 .. code-block:: bash 

     $ bii cpp:configure -G "Visual Studio 12"

Check the code
--------------

The first feature using openCV is showing an image:

**main.cpp**

.. literalinclude:: /_static/code/cpp/examples/opencv/main.cpp
   :language: cpp
   :linenos:

Next, we'll use the object detection example. It uses a CascadeClasifier class and a xml file with the algorithm to detect faces.

**mainface.cpp**

.. literalinclude:: /_static/code/cpp/examples/opencv/mainface.cpp
   :language: cpp
   :linenos:


Build and run the examples
--------------------------

Now execute ``bii cpp:build`` to build the project.

.. code-block:: bash
 
 $ bii cpp:build

Go to bin directory and execute the binaries:

.. code-block:: bash
 
 $ cd bin
 $./examples_opencv_sample_main

.. image:: /_static/img/c++/examples/opencv_bii.png

.. code-block:: bash
 
 $./examples_opencv_sample_mainface

.. image:: /_static/img/c++/examples/opencv_hugh.png

Got any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.