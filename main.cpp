#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


using namespace cv;

/// Global variables

int threshold_value = 0;
int threshold_type = 3;;
int const max_value = 255;
int const max_type = 4;
int const max_BINARY_value = 255;

Mat src, src_gray, dst;
char* window_name = "Lesson 2 Threshold ";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
char* trackbar_value = "Value";

/// Function headers
void Threshold(int, void *);


int main( int argc, char** argv )
{
    /// Load an image
    src = imread( argv[1], 1 );

    /// Convert the image to Gray
    cvtColor( src, src_gray, CV_BGR2RGBA );

    /// Create a window to display results
    namedWindow( window_name, CV_WINDOW_AUTOSIZE );

    /// Create Trackbar to choose type of Threshold
    createTrackbar(trackbar_type,
                   window_name, &threshold_type,
                   max_type, Threshold);

    createTrackbar(trackbar_value,
                   window_name, &threshold_value,
                   max_value, Threshold);

    /// Call the function to initialize
    Threshold(0, 0);

    /// Wait until user finishes program
    while(true)
    {
        int c;
        c = waitKey( 20 );
        if( (char)c == 27 )
        { break; }
    }

}

void Threshold(int, void *)
{

    threshold( src_gray, dst, threshold_value, max_BINARY_value,threshold_type );

    imshow( window_name, dst );
}