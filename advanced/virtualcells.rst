.. _virtual_cells:

Virtual Cells
================

Virtual resources are those whose actual implementation depends on the current compilation platform, or any other conditions you may want to specify. These conditions are specified in a special ``virtual.bii`` file, for every block, using simple python code.

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

Note that the ``main.cpp`` file includes the ``sphere.h`` header file, but makes no reference to the actual location of this resource —and the corresponding implementation, ``sphere.cpp``—. In fact, there is no such file as ``sphere.h`` located in the same folder as ``main.cpp``. The actual file to be included in your code is determined by a spectial ``virtual.bii`` configuration file, written in python language. You need to create this file in your block's ``bii`` folder, and write the code that selects the virtual resource to be used in each case. **Every rule is implemented as a python function** —you can give it whatever name you want—, **whose docstring contains the list of resurces affected by that particular rule**.

In this example we are defining a function that decides which implementation of the ``sphere.h`` and ``sphere.cpp`` resurces is to be used depending on the presenece or not of the ``test`` key in our project secttings. **The return vale for this function must be the name of the folder containing the valid implementations of the virtual resources** for each condition —in our case, the ``test`` folder, or the ``develop`` folder—.

.. code-block:: python
	:linenos:

	def func(settings):
		"""sphere.h sphere.cpp"""
		if settings.user.get('test'):
			return "test"
		else:
			return "develop"

The ``virtual.bii`` file —as other biicode configuration files— is written in python language. It is not possible to make any imports, but you will have direct access to the project settings, received as a parameter. In this case a custom setting ``test`` is being used, and we are checking for its presence inside a python function.

