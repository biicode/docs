.. _littlecms:

Little CMS
===========

Little CMS is an Open Source Color Management Engine. This example demonstrates how to get started using **LittleCMS** by Marti Maria with biicode. The

**Little CMS** intends to be an OPEN SOURCE **small-footprint color management engine**, with special focus on accuracy and performance. It uses the International Color Consortium standard (ICC), which is the modern standard when regarding to color management. This examples have been tested in Windows, OS X and Linux-systems.
Check the Sources:

   1. `Original Little CMS Library <http://www.littlecms.com//>`_
   2. `Biicode Little CMS block <http://www.biicode.com/martimaria/littlecms>`_
   3. `Github repository <https://github.com/MariadeAnton/little-cms>`_
   4. `LittleCMS Documentatio <http://sourceforge.net/projects/lcms/files/lcms/2.6/>`_

ICC Profile Examples
----------------------

These examples are `already in biicode <http://www.biicode.com/examples/littlecms>`_, simple to run, just open the block and build it like this:

.. code-block:: bash

   $ bii init lcms
   $ cd lcms
   $ bii open examples/littlecms
   $ bii cpp:build

There are three different examples in the project, note that all of them use Little CMS , simply by including the library. We're focusing on mktiff8 example but you can execute and try any of them. This example creates a devicelink that decodes TIFF8 Lab files. This is the code used for the example:

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

    #include "martimaria/littlecms/include/lcms2.h"
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

Now, run the Mktiff example.

.. code-block:: bash

   $ bin/examples_littlecms_mktiff8.exe

Once you execute you should see an output like this one, and a the ``lcmstiff8.icm`` file created into your bin folder:
  
.. code-block:: bash
   
   Creating lcmstiff8.icm...Done


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.



