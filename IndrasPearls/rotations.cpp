// inkscape rotations.svg --export-type=png --export-width=2048 --export-background-opacity=0 --export-filename=rotations.png

#include <array>
#include <cmath>
#include <fstream>
#include <random>

using namespace std;

int main()
{
    double x = 1.5;
    double y = 0.0;
    double newx;
    double newy;
    double imageWidth = 2.0;
    double imageHeight = 2.0;
    int iter = 23;
    double angle = 100 * sqrt(2) * M_PI / 180.0;
    double opacity = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(0.0, 45.0);
    
    ofstream file("rotations.svg");
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-3 -3 6 6 \">\n";

    file << "<g transform=\"scale(1,-1)\">\n";

    for (int i = 0; i < iter; i ++){
        newx = x * cos(i* angle) - y * sin(i* angle); 
        newy = x * sin(i* angle) + y * cos(i* angle);
        file << "<image href=\"image.png\" "
             << "x=\"" << newx -imageWidth/2<< "\" "
             << "y=\"" << newy -imageHeight/2<< "\" "
             << "width=\"" << imageWidth << "\" "
             << "height=\"" << imageHeight << "\" "
             << "opacity=\"" << opacity << "\" "
             << "transform=\"rotate(" << i * angle * 180 / M_PI + dist(gen) << " " << newx << " " << newy << ")\"/>\n";
    }

    file << "</g>\n";
    file << "</svg>\n";
    file.close();
}