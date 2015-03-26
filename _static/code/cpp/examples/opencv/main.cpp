#include "opencv/cv.h"      // include it to used Main OpenCV functions.
#include "opencv/highgui.h" //include it to use GUI functions.
 
int main(int argc, char** argv)
{
    IplImage* img = cvLoadImage( "examples/opencv_sample/bii.png" ); //NOTE "examples" should be your user
    cvNamedWindow( "Example1", CV_WINDOW_AUTOSIZE );

    cvShowImage("Example1", img);
    cvMoveWindow("Example1", 0, 0);
    cvWaitKey(0);
    cvReleaseImage( &img );
    cvDestroyWindow( "Example1" );
    return 0;
}