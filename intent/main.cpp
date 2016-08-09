#include "mainwindow.h"
#include <QApplication>
#include <QLabel>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

using namespace cv;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QImage myImage;
    myImage.load("/home/ferran/Escriptori/lab1/highway/input/in000486.jpg");
    QRgb color;
    QSize sizeImage = myImage.size();
    int width = sizeImage.width(), height = sizeImage.height();
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++){
            color = myImage.pixel(i, j);
            int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
            myImage.setPixel(i, j, qRgb(gray, gray, gray));
        }

    }
    QImage myImage2;
    myImage2.load("/home/ferran/Escriptori/lab1/highway/input/in000159.jpg");
    QRgb color2;
    QSize sizeImage2 = myImage2.size();
    int width2 = sizeImage2.width(), height2 = sizeImage2.height();
    for(int i=0;i<width2;i++)
    {
        for(int j=0;j<height2;j++){
            color2 = myImage2.pixel(i, j);
            int gray = (qRed(color) + qGreen(color) + qBlue(color))/3;
            myImage2.setPixel(i, j, qRgb(gray, gray, gray));
        }

    }

    for(int i=0;i<width2;i++)
    {
        for(int j=0;j<height2;j++){
            color = myImage.pixel(i, j);
            color2 = myImage2.pixel(i, j);
            int gray = color2-color;
            myImage2.setPixel(i, j, qRgb(gray, gray, gray));
        }

    }


    QLabel myLabel;
    myLabel.setPixmap(QPixmap::fromImage(myImage2));
    myLabel.show();

   return a.exec();
}
