.. _c++_troubleshooting:

Troubleshooting
===============

In this section you will find information and helpful resources, in case you encounter any problem while using our service. Don't panic, and try to find a solution for your problem bellow. If you can't find a solution, please `contact us at our forum <http://forum.biicode.com>`__ and describe your problem.


.. _eclipse_osx_binaries:

Eclipse projects: "Launch failed. Binary not found" (OS X)
----------------------------------------------------------

If you are using **OS X** as development platform, you will need some aditional setup for executing your biicode projects within Eclipse IDE. It could happen that after building your project, you cannot execute the binaries from the IDE toolbar, getting the following error:

.. image:: /_static/img/c++/binary_not_found.png

If you are getting this error, please proceed as follows:

#. Right-click on your project and select *Properties*.
#. Select *C/C++ Make project* and click on the *Binary Parser* subsection tab.
#. Unselect Mach-O Parser (deprecated).
#. Select Mach-O 64 Parser.
#. Click *OK*.

You can :ref:`read more in this section about configuring and IDE with your C/C++ projects <ide_configuration>`.