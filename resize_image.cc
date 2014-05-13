#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

void Usage() {
  cout << "resize_image input output newwidth newheight\n";
}
int main (int argc, const char* argv[]) {
  IplImage* inimage = cvLoadImage(argv[1]);
  IplImage* outimage = cvCreateImage(cvSize(atoi(argv[3]),atoi(argv[4])),
                                     inimage->depth,
				     inimage->nChannels);
  cvResize(inimage, outimage);
  cvSaveImage(argv[2],outimage);
  return 0;
}

