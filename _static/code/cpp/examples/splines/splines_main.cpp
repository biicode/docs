#include <iostream>
#include "lasote/splines/include/datatable.h"
#include "lasote/splines/include/bspline.h"
#include "lasote/splines/include/pspline.h"
#include "lasote/splines/include/rbfspline.h"

using std::cout;
using std::endl;

using namespace MultivariateSplines;

// Six-hump camelback function
double f(DenseVector x)
{
    assert(x.rows() == 2);
    return (4 - 2.1*x(0)*x(0)
    + (1/3.)*x(0)*x(0)*x(0)*x(0))*x(0)*x(0)
    + x(0)*x(1)
    + (-4 + 4*x(1)*x(1))*x(1)*x(1);
}

int main(int argc, char *argv[])
{
    // Create new DataTable to manage samples
    DataTable samples;

    // Sample function
    DenseVector x(2);
    double y;
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            // Sample function at x
            x(0) = i*0.1;
            x(1) = j*0.1;
            y = f(x);

            // Store sample
            samples.addSample(x,y);
        }
    }

    // Build B-splines that interpolate the samples
    BSpline bspline1(samples, BSplineType::LINEAR);
    BSpline bspline3(samples, BSplineType::CUBIC_FREE);

    // Build penalized B-spline (P-spline) that smooths the samples
    PSpline pspline(samples, 0.03);

    // Build radial basis function spline that interpolate the samples
    RBFSpline rbfspline(samples, RadialBasisFunctionType::THIN_PLATE_SPLINE);

    // Evaluate the splines at x = (1,1)
    x(0) = 1; x(1) = 1;
    cout << "-------------------------------------------------"     << endl;
    cout << "Function at x: \t\t\t"         << f(x)                 << endl;
    cout << "Linear B-spline at x: \t\t"    << bspline1.eval(x)     << endl;
    cout << "Cubic B-spline at x: \t\t"     << bspline3.eval(x)     << endl;
    cout << "P-spline at x: \t\t\t"         << pspline.eval(x)      << endl;
    cout << "Thin-plate spline at x:\t\t"   << rbfspline.eval(x)    << endl;
    cout << "-------------------------------------------------"     << endl;

    return 0;
}
