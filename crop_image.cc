#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;
void Usage() {
  cout << "Description: Crop the image given the rectangle\n";
  cout << "crop_image: input output start_x start_y width height\n";
  cout << "\t input: the path for the input image\n";
  cout << "\t output: the path for the output image\n";
  cout << "\t start_x: the start point of the rectangle\n";
  cout << "\t start_y: the start point of the rectangle\n";
  cout << "\t width: the width of the rectangle\n";
  cout << "\t height: the height of the rectangle\n";
}
bool checkvalid(const char* argv[],int width, int height) {
  int sx = atoi(argv[3]);
  int sy = atoi(argv[4]);
  int w = atoi(argv[5]);
  int h = atoi(argv[6]);
  if (sx < 0 || sy < 0 || w < 0 || h < 0) {
    cout << "Size and position par can't be negative\n";
    return false;
  }
  if (sx + w > width || sy + h > height) {
    cout << "Size is bigger than the image\n";
    return false;
  }
  return true;
}
int main(int argc, const char* argv[]) {
  if(argc != 7) {
    Usage();
    return 0;
  }
  IplImage* inimage = cvLoadImage(argv[1]);
  if ( !checkvalid(argv, inimage->width, inimage->height)) {
	return 0;
  }
  cvSetImageROI(inimage, Rect(atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6])));
  IplImage* outimage = cvCreateImage(cvSize(atoi(argv[5]), atoi(argv[6])),
                                     IPL_DEPTH_8U,
				     inimage->nChannels);
  cvCopy(inimage, outimage, NULL);
  cvNamedWindow("Outimage");
  cvShowImage("Outimage",outimage);
  cvWaitKey(4000);
  cvReleaseImage(&outimage);
  cvReleaseImage(&inimage);
  cvDestroyWindow("Outimage");
  return 0;
}
