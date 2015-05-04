.. _littlecms:

Little CMS
===========

Little CMS is an Open Source Color Management Engine. This example demonstrates how to get started using **LittleCMS** by Marti Maria with biicode.

**Little CMS** intends to be an OPEN SOURCE **small-footprint color management engine**, with special focus on accuracy and performance. It uses the International Color Consortium standard (ICC), which is the modern standard when regarding to color management. This examples have been tested in Windows, OS X and Linux-systems.
Check the Sources:

   1. `Original Little CMS Library <http://www.littlecms.com//>`_.
   2. Biicode Little CMS block at `martimaria/littlecms <http://www.biicode.com/martimaria/littlecms>`_.
   3. `Github repository <https://github.com/MariadeAnton/little-cms>`_.
   4. `LittleCMS Documentation <http://sourceforge.net/projects/lcms/files/lcms/2.6/>`_.

ICC Profile Examples
----------------------

In this example we'll create a devicelink that decodes TIFF8 Lab files using Little CMS. You only have to write ``#include "lcms2.h"`` at the top of your code.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new project and a *lcms-main.c* file:

.. code-block:: bash

   $ bii init lcms -L
   $ cd lcms
   $ # Create lcms-main.c and copy the code

**lcms-main.c**

.. code-block:: cpp

    //  Little cms
    //  Copyright (C) 1998-2010 Marti Maria
    //
    // Permission is hereby granted, free of charge, to any person obtaining 
    // a copy of this software and associated documentation files (the "Software"), 
    // to deal in the Software without restriction, including without limitation 
    // the rights to use, copy, modify, merge, publish, distribute, sublicense, 
    // and/or sell copies of the Software, and to permit persons to whom the Software 
    // is furnished to do so, subject to the following conditions:
    //
    // The above copyright notice and this permission notice shall be included in 
    // all copies or substantial portions of the Software.
    //
    // THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
    // EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
    // THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND 
    // NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE 
    // LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION 
    // OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION 
    // WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

    // Creates a devicelink that decodes TIFF8 Lab files 

    #include "lcms2.h"
    #include <stdlib.h>
    #include <math.h>

    static
    double DecodeAbTIFF(double ab)
    {
      if (ab <= 128.)
        ab += 127.;
      else
        ab -= 127.;

      return ab;
    }

    static
    cmsToneCurve* CreateStep(void)
    {
      cmsToneCurve* Gamma;
      cmsUInt16Number* Table;
      int i;
      double a;

      Table = calloc(4096, sizeof(cmsUInt16Number));
      if (Table == NULL) return NULL;

      for (i=0; i < 4096; i++) {
        a = (double) i * 255. / 4095.;
        a = DecodeAbTIFF(a);
        Table[i] = (cmsUInt16Number) floor(a * 257. + 0.5);
      }
      Gamma = cmsBuildTabulatedToneCurve16(0, 4096, Table);
      free(Table);
      return Gamma;
    }


    static
    cmsToneCurve* CreateLinear(void)
    {
      cmsUInt16Number Linear[2] = { 0, 0xffff };
      return cmsBuildTabulatedToneCurve16(0, 2, Linear);          
    }



    // Set the copyright and description
    static
    cmsBool SetTextTags(cmsHPROFILE hProfile)
    {
        cmsMLU *DescriptionMLU, *CopyrightMLU;
        cmsBool  rc = FALSE;
        DescriptionMLU  = cmsMLUalloc(0, 1);
        CopyrightMLU    = cmsMLUalloc(0, 1);
        if (DescriptionMLU == NULL || CopyrightMLU == NULL) goto Error;
        if (!cmsMLUsetASCII(DescriptionMLU,  "en", "US", "Little cms Tiff8 CIELab")) goto Error;
        if (!cmsMLUsetASCII(CopyrightMLU,    "en", "US", "Copyright (c) Marti Maria, 2010. All rights reserved.")) goto Error;
        if (!cmsWriteTag(hProfile, cmsSigProfileDescriptionTag,  DescriptionMLU)) goto Error;
        if (!cmsWriteTag(hProfile, cmsSigCopyrightTag,           CopyrightMLU)) goto Error;     
        rc = TRUE;

    Error:
        if (DescriptionMLU)
            cmsMLUfree(DescriptionMLU);
        if (CopyrightMLU)
            cmsMLUfree(CopyrightMLU);
        return rc;
    }


    int main(int argc, char *argv[])
    {
      cmsHPROFILE hProfile;
      cmsPipeline *AToB0;
      cmsToneCurve* PreLinear[3];
      cmsToneCurve *Lin, *Step;

      fprintf(stderr, "Creating lcmstiff8.icm...");
        
        remove("lcmstiff8.icm");
      hProfile = cmsOpenProfileFromFile("lcmstiff8.icm", "w");

      // Create linearization
      Lin  = CreateLinear();
      Step = CreateStep();

      PreLinear[0] = Lin;
      PreLinear[1] = Step;
      PreLinear[2] = Step;

      AToB0 = cmsPipelineAlloc(0, 3, 3);
      cmsPipelineInsertStage(AToB0, 
      cmsAT_BEGIN, cmsStageAllocToneCurves(0, 3, PreLinear));
      cmsSetColorSpace(hProfile, cmsSigLabData);
      cmsSetPCS(hProfile, cmsSigLabData);
      cmsSetDeviceClass(hProfile, cmsSigLinkClass);
      cmsSetProfileVersion(hProfile, 4.2);
      cmsWriteTag(hProfile, cmsSigAToB0Tag, AToB0);
      SetTextTags(hProfile);
      cmsCloseProfile(hProfile);
      cmsFreeToneCurve(Lin);
      cmsFreeToneCurve(Step);
      cmsPipelineFree(AToB0);
        
      fprintf(stderr, "Done.\n");
      return 0;
    }

Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 INFO: Processing changes...
 youruser/lcms depends on:
       system:
          math.h
          stdlib.h
       unresolved:
          lcms2.h

Now, edit the *biicode.conf* file generated in the project folder. Map your ``[includes]`` to point to martimatia/littlecms:

.. code-block:: text

 [includes]
     lcms2.h: martimaria/littlecms/include/

Now do **bii find** and biicode will find the most recent version available of Little CMS library:

.. code-block:: bash

 $  bii find
 INFO: Processing changes...
 INFO: Finding missing dependencies in server
 INFO: Looking for martimaria/littlecms...
 INFO: Block candidate: martimaria/martimaria/littlecms/master
 INFO:   Version martimaria/littlecms: 1 (STABLE) valid
 INFO:   Version martimaria/littlecms: 0 (STABLE) valid
 INFO: Analyzing compatibility for found dependencies...
 INFO: All dependencies resolved
 Find resolved new dependencies:
         martimaria/littlecms: 1
 INFO: Saving files from: martimaria/littlecms

Have a look at your *biicode.conf* again to ensure Little CMS library was added to your project:

.. code-block:: text

 [requirements]
     martimaria/littlecms: 1
 
 [includes]
     lcms2.h: martimaria/littlecms/include/

Check again with **bii deps** and now all dependencies are resolved.

Build the project
^^^^^^^^^^^^^^^^^

Next, the only thing left is building the project:

.. code-block:: bash

  $ bii build

Execute the binary placed in bin directory:

.. code-block:: bash

  $ bin/youruser_lcms_lcms-main

Once you execute you should see an output like this one, and a the ``lcmstiff8.icm`` file created into your bin folder:
  
.. code-block:: bash
   
   Creating lcmstiff8.icm...Done

You can find more examples at `examples/littlecms <http://www.biicode.com/examples/littlecms>`_, give them a try!

Open and build
--------------

This example is already in biicode at `examples/littlecms <http://www.biicode.com/examples/littlecms>`_.

It is simple to run, just open the block and build it like this:

.. code-block:: bash

 $ bii init lcms
 $ cd lcms
 $ bii open examples/littlecms


There are three different files in the project, note that all of them use Little CMS , simply by including the library.

Build the block and execute any of them!

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # Execute!


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.