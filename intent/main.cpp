#include "mainwindow.h"
#include <QApplication>
#include <opencv2/core.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;


int main(int argc, char *argv[])
{
    String imageName( "/home/ferran/Escriptori/intent.jpg"); // by default


    Mat image;
    image = imread( imageName, IMREAD_COLOR ); // Read the file
    if( image.empty() )                      // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    cv::namedWindow("Display",WINDOW_AUTOSIZE);
    cv::imshow("Display",image);
    cv::waitKey(0);
    return 0;
}
