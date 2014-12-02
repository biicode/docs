.. _virtual_bii:

``virtual.bii``: defining virtual resources
============================================

The optional ``virtual.bii`` file, located inside the ``bii`` folder of your block, allows you to **define virtual resources** for that particular block. Virtual resources are an advanced feature that biicode offers you, to define platform-specific implementations for your files. In general, you can define the actual implementation for any given file via an appropriate python function, that implements some condition. 

.. _virtual_cells:

Virtual Cells
-------------

Virtual resources are **those whose actual implementation depends on the current compilation platform, or any other conditions** you may want to specify. These conditions are specified in a special ``virtual.bii`` file, for every block, using simple python code.

Imagine you want different code to be compiled or executed depending on different conditions, like whether you are in a production or a testing environment, Windows or Linux platforms, or even the compiler version. This is possible making use of **virtual resources**.

So, let's say you have this ``main.cpp`` and two different versions of ``sphere.h`` and its corresponding implementation file ``sphere.cpp``, under two separate folders called ``test`` and ``development``.

.. code-block:: cpp
	:linenos:

	#include "sphere.h"

	using namespace std;
	int main() {
		Sphere s(2.0f);
		cout << "Volume: " << s.volume() << endl;
		return 1;
	}

Note that the ``main.cpp`` file includes the ``sphere.h`` header file, but makes no reference to the actual location of this resource —and the corresponding implementation, ``sphere.cpp``—. In fact, there is no such file as ``sphere.h`` located in the same folder as ``main.cpp``. The actual file to be included in your code is determined by a spectial ``virtual.bii`` configuration file, **written in python language**.

You need to create this file in your block's ``bii`` folder, and write the code that selects the virtual resource to be used in each case. **Every rule is implemented as a python function** —you can give it whatever name you want, that has no relevance—, **whose docstring contains the list of resources affected by that particular rule, and returns a literal python string with the name of the folder containing the desired implementations of the virtual resources**. This function will receive as a parameter your project settings configuration.

In this example we are defining a python function that decides which implementation of the ``sphere.h`` and ``sphere.cpp`` resurces is to be used depending on the value of the user defined variable ``model`` in the user's :ref:`project settings file<settings_bii>`. In this case we are returning the name of the ``test`` folder, or the ``develop`` folder, and we must include in this locations appropriate implementations for each of these resources.

.. code-block:: python
	:linenos:

	def choose_implementation(settings):
		"""sphere.h sphere.cpp"""
		mode = settings.user.get('mode')
		if mode == 'test':
			return "test"
		elif mode == 'develop':
			return "develop"

Additionaly, we must remember to define the appropriate configuration in our ``settings.bii`` file. Assuming we desire to use the implemetations contained in the ``test`` folder, we shoul include the following lines in our yaml configuration file:

.. code-block:: text

	user:
		mode: test

The ``virtual.bii`` file is always written in python language. **It is not possible to make any imports, but you will have direct access to the project settings**, received as a parameter.


**Got any doubts?** `Ask in our forum <http://forum.biicode.com>`_