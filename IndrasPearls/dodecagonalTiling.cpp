// inkscape dodecagonalTiling.svg --export-type=png --export-width=2048 --export-background-opacity=0 --export-filename=dodecagonalTiling.png

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;
using Vec2 = array<double, 2>;

template <size_t N>
array<double, N> operator*(double c, const array<double, N>& a)
{
    array<double, N> result;

    for (size_t i = 0; i < N; ++i)
        result[i] = c * a[i];

    return result;
}
template <size_t N>
array<double, N> operator+(const array<double, N>& a,
                           const array<double, N>& b)
{
    array<double, N> result;

    for (size_t i = 0; i < N; ++i)
        result[i] = a[i] + b[i];

    return result;
}

template <size_t N>
array<double, N> operator+(const array<double, N>& a, double c)
{
    array<double, N> result;

    for (size_t i = 0; i < N; ++i)
        result[i] = a[i] + c;

    return result;
}
int main()
{
    int width=1024;
    int height=1182;

    double imageHeight = 1.0;
    double imageWidth = imageHeight * width / height;
    double x = 0.0;
    double y = -imageHeight/2;
    double newx;
    double newy;

    int iter = 13;
    double angle = 60 * M_PI / 180.0;
    double opacity = 1;    

    Vec2 base = {0, -imageHeight/2};
    Vec2 genT = {2*imageWidth, 0};
    Vec2 genS = {imageWidth, sqrt(3) * imageWidth};

    Vec2 trans;
    int kmax = 5;
    int lmax = 5;

    ofstream file("dodecagonalTiling.svg");
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-4 -4 8 8 \">\n";

    file << "<g transform=\"scale(1,-1)\">\n";

    for (int k = -kmax; k <= kmax; k++)
    {
        for (int l = -lmax; l <= lmax; l++)
        {
            trans = k * genT + l * genS;
            newx = base[0] + trans [0];
            newy = base[1] + trans [1];
            for (int i = 0; i < 6; i ++){
                file << "<image href=\"dodecagonal-fr.png\" "
                << "x=\"" << newx << "\" "
                << "y=\"" << newy << "\" "
                << "width=\"" << imageWidth << "\" "
                << "height=\"" << imageHeight << "\" "
                << "opacity=\"" << opacity << "\" "
                << "transform=\"rotate(" << i * angle * 180 / M_PI << ")\"/>\n";
            }

        }
    }
    
 

    file << "</g>\n";
    file << "</svg>\n";
    file.close();
}