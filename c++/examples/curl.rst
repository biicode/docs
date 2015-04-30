cURL
====

`cURL <http://curl.haxx.se/>`_ is a command line tool and library for transferring data with URL syntax, supporting DICT, FILE, FTP, FTPS, Gopher, HTTP, HTTPS, IMAP, IMAPS, POP3, POP3S, SCP, SMTP, SMTPS, Telnet, TFTP... and supports SSL certificates, HTTP POST, HTTP PUT, FTP uploading, HTTP form based upload...

You can check `cURL documentation <http://curl.haxx.se/docs/>`_ for more information.

cURL library is stored at `lasote/curl <https://www.biicode.com/lasote/curl>`_ generated from this `github repo <https://github.com/lasote/curl>`_.

HTML page gatherer
------------------

This example demonstrates some basics using  **cURL**. You'll learn to open a website URL, show and copy to a file its html's code.

Creating a new project
^^^^^^^^^^^^^^^^^^^^^^

Create a new project and a *html-page.cpp* inside like this:

.. code-block:: bash

   $ bii init curl_example -L
   $ cd curl_example
   $ # Create html-page.cpp

The code of the example is this one, it goes to `biicode's docs website <http://docs.biicode.com>`_ and copies the html code and streams it (copies it to a file, copies it into a string and shows it in the terminal).

Copy the code in *html-page.cpp*:

**html-page.cpp**

.. code-block:: cpp

  #include <curl/curl.h>
  #include <fstream>
  #include <sstream>
  #include <iostream>

  using namespace std;

  // callback function writes data to a std::ostream
  static size_t data_write(void* buf, size_t size, size_t nmemb, void* userp)
  {
    if(userp)
    {
      std::ostream& os = *static_cast<std::ostream*>(userp);
      std::streamsize len = size * nmemb;
      if(os.write(static_cast<char*>(buf), len))
        return len;
    }

    return 0;
  }

  //timeout is in seconds
  CURLcode curl_read(const std::string& url, std::ostream& os, long timeout = 30)
  {
    CURLcode code(CURLE_FAILED_INIT);
    CURL* curl = curl_easy_init();

    if(curl)
    {
      if(CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &data_write))
      && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L))
      && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L))
      && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_FILE, &os))
      && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout))
      && CURLE_OK == (code = curl_easy_setopt(curl, CURLOPT_URL, url.c_str())))
      {
        code = curl_easy_perform(curl);
      }
      curl_easy_cleanup(curl);
    }
    return code;
  }

  int main()
  {
    curl_global_init(CURL_GLOBAL_ALL);

    std::ofstream ofs("html-web-output.html");
    if(CURLE_OK == curl_read("http://docs.biicode.com/", ofs))
    {
      cout<<"Web page successfully written to file!!"<<endl;
    }

    std::ostringstream oss;
    if(CURLE_OK == curl_read("http://docs.biicode.com/", oss))
    {
      cout<<"Web page successfully written to string!!"<<endl;
      std::string html = oss.str();
    }

    if(CURLE_OK == curl_read("http://docs.biicode.com/", std::cout))
    {
      cout<<endl<<"Web page successfully written to standard output!!"<<endl;
    }

    curl_global_cleanup();
  }


Manage your dependencies
^^^^^^^^^^^^^^^^^^^^^^^^

Check the dependencies of the project with **bii deps**:

..  code-block:: bash
 
 $ bii deps
 your_user/curl_example depends on:
       system:
          fstream
          iostream
          sstream
       unresolved:
          curl/curl.h


Now, edit the *biicode.conf* file generated in the project folder. Add your ``[requirements]`` depending on the version you want and map your ``[includes]``:

.. code-block:: text

 [requirements]
     lasote/curl: 2
 
 [includes]
     curl/*.h: lasote/curl/include


Check again with **bii deps** to show all resolved dependencies.

Build the project
^^^^^^^^^^^^^^^^^

Now, build and run the HTML page gatherer.

.. code-block:: bash

 $ bii build
 $ cd bin
 $ # execute it!
 Web page successfully written to file!!
 Web page successfully written to string!!
 <!DOCTYPE html>
 <!--[if IE 8]><html class="no-js lt-ie9" lang="en" > <![endif]-->
 ...
 Web page successfully written to standard output!!

Once you execute you should see an output like that one. Go to your bin folder and open *html-web-view.html* in your browser to see **biicode's docs web page**!

Open and build
--------------

This and other examples with cURL are already in biicode: `examples/curl <http://www.biicode.com/examples/curl>`_.

To give this one a try, create a new project and open the block:

.. code-block:: bash

 $ bii init curl_example
 $ cd bcl_example
 $ bii open examples/curl

Build the example and execute it:

.. code-block:: bash

 $ bii build
 $ cd bin
 $ examples_curl_html-page
 Web page successfully written to file!!
 Web page successfully written to string!!
 <!DOCTYPE html>
 <!--[if IE 8]><html class="no-js lt-ie9" lang="en" > <![endif]-->
 ...
 Web page successfully written to standard output!!


Any doubts? Do not hesitate to `contact us <http://web.biicode.com/contact-us/>`_ visit our `forum <http://forum.biicode.com/>`_ and feel free to ask any questions.



