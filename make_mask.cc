#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc, const char* argv[]) {
  if(argc != 4) {
    cout << "Descripton: This program will binary a image to make it as the mask.\n";
    cout << "makeMask input output threshold\n";
    cout << "\t input: the path for the input image\n";
    cout << "\t output: the path for the output image\n";
    cout << "\t threshold: threshold when binarying the image\n";
    cout << "\t \t if the pixel value less than threshold, it will be set to zero\n";
    return 0;
  }
  IplImage* inimage = cvLoadImage(argv[1]);
  int threshold = atoi(argv[3]);
  IplImage* outimage = cvCreateImage(cvGetSize(inimage), IPL_DEPTH_8U, 1);
  cvNamedWindow("InImage");
  cvNamedWindow("OutImage");
  cvSplit(inimage, outimage, NULL, NULL, NULL);
  cvThreshold(outimage, outimage, threshold, 255, 0); 
  uchar* ptr = (uchar*) (outimage->imageData);
  for(int i=0; i<outimage->width; ++i) {
    if(ptr[i] > 0) {
      ptr[i] = 0;
    }
  }
  ptr = (uchar*) (outimage->imageData + (outimage->height - 1) * outimage->widthStep);
  for(int i=0; i<outimage->width; ++i) {
    if(ptr[i] > 0) { 
      ptr[i] = 0;
    }
  }
  for(int i=0; i<outimage->height; ++i) {
    ptr = (uchar*) (outimage->imageData + i * outimage->widthStep);
    if(ptr[0] > 0) {
      ptr[0] = 0;
    }
    ptr = ptr + outimage->widthStep - 1;
    if(ptr[0] > 0) {
      ptr[0] = 0;
    }
  }
  cvShowImage("OutImage", outimage);
  cvSaveImage(argv[2], outimage);
  cout << "Press ESC to escape\n";
  int c=cvWaitKey(3000);
  cout << c << endl;
  cvDestroyWindow("OutImage");
  cvReleaseImage(&inimage);
  cvReleaseImage(&outimage);
}
