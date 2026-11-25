// inkscape spiralNaru.svg --export-type=png --export-width=2048 --export-background-opacity=0 --export-filename=spiralNaru.png

#include <iostream>

#include <complex>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
int main(){
    int width=3586;
    int height=3589;

    double opacity = 1; 
    complex<double> a(0.5*sqrt(3)/2, 0.5/2.0);
    complex<double> z(2.5/sqrt(2), 0.0);

    ofstream file("spiralNaru.svg");
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-500 -2800 2450 2900 \">\n";
    file << "<g transform=\"scale(1,-1)\">\n";
    for (int k = 0; k < 11; k++)
    {
        double newx = z.real();
        double newy = z.imag();
        double imageHeight = abs(z);

        double imageWidth = imageHeight * width / height;
        // cout << imageHeight << "\t" << imageWidth << "\n";
        double angle = - arg(z)* 180.0 / M_PI;
        // cout << (newx - imageWidth / 2)  << "\n" << (newx + imageWidth / 2) << "\n";
        // cout << -(newy - imageHeight / 2)<< "\n" << -(newy + imageHeight / 2) << "\n";
        // double angle = arg(z);
        file << "<image href=\"naru.png\" "
        << "x=\"" <<  newx - imageWidth / 2 << "\" "
        << "y=\"" << newy - imageHeight / 2 << "\" "
        << "width=\"" << imageWidth << "\" "
        << "height=\"" << imageHeight << "\" "
        << "opacity=\"" << opacity << "\" "
        << "transform=\"rotate(" << angle << " " << newx << " " << newy << ")\"/>\n";
        z = z / a;
    }
    
    file << "</g>\n";
    file << "</svg>\n";
    file.close();
}