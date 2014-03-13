Eigen matrix library
====================

`Eigen <http://eigen.tuxfamily.org>`_ is a great matrix library, clear, powerful and very easy to use.

To use it, all you have to do it is to #include the appropiate header and execute ``bii find``

.. code-block:: cpp

   #include <iostream>
   #include <eigen/eigen/dense>
   using namespace std;
   using namespace Eigen;

   int main() {
      int size=3;
      MatrixXd A=MatrixXd(size,size);
      A<<1, 2, 3, 45, 4, 2, 2, 2, 3;
      VectorXd b(size);
      b<< 1, 2, 3;

      VectorXd sol=A.colPivHouseholderQr().solve(b);
      cout<<sol<<endl;
      cout<<A*sol<<endl;

      return 0;
   }
