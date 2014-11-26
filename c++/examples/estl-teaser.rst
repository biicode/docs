.. _estl-teaser:


estl-teaser
------------

|estl-teaser_homepage| The ESTL is a C++ STL-like library for embedded developers. It is a library that is designed for memory-constrained embedded C++ applications. This library uses no new or delete.

It is highly tested and should be quite portable. It uses only C++ 98 features due to compiler limitations on some of the target platforms that are currently in use.

We are including a vector class here but there is more to come! For more details, check out our ESTL. 

The main block is |bii_estl-teaser|, which is generated from this |fork_estl-teaser|.

Polygon Calculator
----------------------------

In this example you will calculate ,giving the coordenates, the angles and sides length of a polygon between 3 and 10 vertex. Then, create a project, open the example and open the file polygon.cpp:

.. code-block:: bash

   ~$ bii init estl-teaser
   ~$ cd estl-teaser
   ~/estl-teaser$ bii open examples/estl-teaser

Now lets check the code, **open the file examples/polygon.cpp** :

.. code-block:: cpp

    
  #include <cstdio>

  #include <estd/vector.h>

  #include <cmath>

  #include <stdio.h>


  //class to represent float Points in a X, Y axis.
  class MyClass
  {
      UNCOPYABLE(MyClass);

  public:

      MyClass() : XValue(0), YValue(0){}

      void setValue(float x, float y) { XValue = x; YValue = y; }

      float getX() const { return XValue; }

      float getY() const { return YValue; }

  private:

      float XValue;
      float YValue;
  };

  //Class to represent a float
  class Num
  {
      UNCOPYABLE(Num);

  public:

      Num() : fValue(-1) { }

      void setValue(float value) { fValue = value; }

      float getValue() const { return fValue; }

  private:

      float fValue;
  };

  /*
   * A simple method that initializes the elements in a vector
   */
  void fillVec(esrlabs::estd::vector<MyClass>& aVec, size_t count)
  {
      for(int i = 0; i < count; ++i)
      {
          // This is not possible because MyClass is not copyable.
  //        MyClass tmp;
  //        tmp.setValue(i);
  //        aVec.push_back(tmp);

          // make sure that the vector is not full. Otherwise
          // the vector will assert!
          if(!aVec.full()) {
              // Use the push_back method that returns a reference to an
              // underlying element.
              float x=0;
              float y=0;
              printf("%s","Axis X: " );
              scanf("%f",&x);
              printf("%s","Axis Y: " );
              scanf("%f",&y);
              aVec.push_back().setValue(x,y);
          }
      }
  }

  void fillVecInit(esrlabs::estd::vector<Num>& aVec, size_t count)
  {
      for(size_t i = 0; i < count; ++i)
      {
          // This is not possible because MyClass is not copyable.
  //        MyClass tmp;
  //        tmp.setValue(i);
  //        aVec.push_back(tmp);

          // make sure that the vector is not full. Otherwise
          // the vector will assert!
          if(!aVec.full()) {
              // Use the push_back method that returns a reference to an
              // underlying element.

              aVec.push_back().setValue(i);
          }
      }
  }
  /*
   * Use the const_iterator methods: cbegin, cend to print out the vector
   */
  void printVec(const esrlabs::estd::vector<Num>& aVec)
  {
      esrlabs::estd::vector<Num>::const_iterator iter;

      fprintf(stderr, "Vector contains:");
      for(iter = aVec.cbegin(); iter != aVec.cend(); ++iter)
      {
          fprintf(stderr, " %f", iter->getValue());
      }
      fprintf(stderr, "\n");
  }

  void printVec2(const esrlabs::estd::vector<MyClass>& aVec)
  {
      esrlabs::estd::vector<MyClass>::const_iterator iter;

      fprintf(stderr, "Vector contains:");
      for(iter = aVec.cbegin(); iter != aVec.cend(); ++iter)
      {
          fprintf(stderr, " %f", iter->getX());
          fprintf(stderr, " %f", iter->getY());
      }
      fprintf(stderr, "\n");
  }

  void getAngels(esrlabs::estd::vector<MyClass>& aVec, esrlabs::estd::vector<Num>& angles, int num)
  {
      

      // use operator[] to scale the values in the vector
      for(int i = 0; i < num; ++i)
      {
          MyClass v, u;
          int b = i-1;
          if(b<0){
              b=num-1;
          }

          v.setValue(aVec[i].getX()-aVec[b].getX(),aVec[i].getY()-aVec[b].getY());

          int c = i+1; 
          if(c==num){
              c=0;
          }

          
          u.setValue(aVec[i].getX()-aVec[c].getX(),aVec[i].getY()-aVec[c].getY());

          float angle = ((u.getX()*v.getX())+(u.getY()*v.getY()))/(sqrt(pow(u.getX(),2)+pow(u.getY(),2))*sqrt(pow(v.getX(),2)+pow(v.getY(),2)));    
          angles[i].setValue(acos(angle));
      }
  }       

  void getSizeSides(esrlabs::estd::vector<MyClass>& aVec, esrlabs::estd::vector<Num>& sides, int num)
  {
      // use operator[] to scale the values in the vector
      for(int i = 0; i < num; ++i)
      {
          int b=i+1;
          if(i==(num-1)){
              b=0;
          }
          //|aVec|= sqrt( (x1-x2)^2 + (y1-y2)^2 )
          sides[i].setValue(sqrt(pow((aVec[i].getX()-aVec[b].getX()),2)+pow((aVec[i].getY()-aVec[b].getY()),2)));
      }
  }

  int main()
  {
      // declare a vector of 10 MyClass objects
      int num=0;
      printf("%s","Number of vertex (max 10): " );
      scanf("%d", &num);
     
      esrlabs::estd::declare::vector<MyClass, 10> vec;
      esrlabs::estd::declare::vector<Num, 10> aux;
      fillVecInit(aux,num);
      //MyClass mc;
      
      // fill the vector with 20 items. It will only add
      // 10 because that is the size of our vector
      fillVec(vec,num);
      printf("%s","Sides Length: " );
      getSizeSides(vec,aux,num);
      printVec(aux);
      printf("%s","grades of angles: " );
      getAngels(vec,aux,num);
      printVec(aux);

      return 0;
  }



Find your dependency to check if you have everything to build our project and build it:

.. code-block:: bash

  ~/estl-teaser$ bii find
  ~/estl-teaser$ bii cpp:build

Execute the binary and this is how the output looks like:

.. code-block:: bash

  ~/estl-teaser$ bin/myuser_estl-teaser_examples_estd_polygon
  Number of vertex (max 10):

There we selected the number of vertex that our polygon will be!

After that, it will ask for the Axis variables for each vertix.

.. code-block:: bash

  ~/estl-teaser$ bin/myuser_estl-teaser_examples_estd_polygon
  Number of vertex (max 10):
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 

Finnally we get out vector of polygon Angels and Polygon sides length:

.. code-block:: bash

  ~/estl-teaser$ bin/myuser_estl-teaser_examples_estd_polygon
  Number of vertex (max 10):
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 
  Axis Y: 
  Axis X: 
  Vector contains:
  Sides Length: Vector contains:
  grades of angles: Vector contains: 


Didn't work? No problem, read or contact us in |biicode_forum_link|

.. |biicode_forum_link| raw:: html

   <a href="http://forum.biicode.com" target="_blank">the biicode forum</a>



Any suggestion or feedback? |biicode_write_us| It is very welcomed :)

.. |biicode_write_us| raw:: html

   <a href="mailto:info@biicode.com" target="_blank">Write us!</a>

.. |estl-teaser_homepage| raw:: html

   <a href="https://esrlabs.com/blog/estl-for-embedded-developers/" target="_blank">estl-teaser</a>

.. |bii_estl-teaser| raw:: html

   <a href="https://www.biicode.com/examples/estl-teaser" target="_blank">here</a>

.. |fork_estl-teaser| raw:: html

   <a href="https://github.com/esrlabs/estl-teaser" target="_blank">github repo</a>
.. _estl-teaser: