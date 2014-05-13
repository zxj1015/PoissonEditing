#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int main(int argc, const char* argv[]) {
  IplImage* srcimage = cvLoadImage(argv[1]);
  IplImage* dstimage = cvLoadImage(argv[2]);
  IplImage* maskimage = cvLoadImage(argv[3]);  
  for(int i=0; i<maskimage->height; ++i) {
    uchar* ptr = (uchar*) (maskimage->imageData + i * maskimage->widthStep);
    for(int j=0; j<maskimage->width; ++j) {
      cout << static_cast<int>(ptr[3*j]) <<" "<< static_cast<int>(ptr[3*j+1]) <<" "<< static_cast<int>(ptr[3*j+2]) << endl;
    }
  }
  cout << maskimage->nChannels <<endl;
  //cvNamedWindow("Example");
  //cvShowImage("Example", maskimage);
  //cvWaitKey(0);
  cvReleaseImage(&srcimage);
  cvReleaseImage(&dstimage);
  cvReleaseImage(&maskimage);
  //cvDestroyWindow("Example");
  cout<<"hello"<<endl;
}
