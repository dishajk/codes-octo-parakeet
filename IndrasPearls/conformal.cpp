// inkscape conformal.svg --export-type=png --export-width=2048 --export-background-opacity=0 --export-filename=conformal.png

#include <iostream>

#include <complex>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

string interpolateColour(double t)
{
    int start[3] = {102, 51, 102};    // #663366
    int end[3]   = {153, 204, 153};   // #99cc99

    int rgb[3];

    for (int i = 0; i < 3; i++)
        rgb[i] = round((1 - t) * start[i] + t * end[i]);

    stringstream colour;
    colour << "#"
           << hex << setfill('0')
           << setw(2) << rgb[0]
           << setw(2) << rgb[1]
           << setw(2) << rgb[2];

    return colour.str();
}

int main()
{
    ofstream file1("conformal.svg");
    ofstream file2("conformalzsquared.svg");
    ofstream file3("conformalzroot.svg");
    ofstream file4("conformalzmap1.svg");

    file1 << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-3 -3 6 6 \">\n";
    file2 << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-9 -9 18 18 \">\n";
    file3 << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-2 -2 4 4 \">\n";
    file4 << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-3 -3 6 6 \">\n";

    file1 << "<g transform=\"scale(1,-1)\">\n";
    file2 << "<g transform=\"scale(1,-1)\">\n";
    file3 << "<g transform=\"scale(1,-1)\">\n";
    file4 << "<g transform=\"scale(1,-1)\">\n";
    double dotRadius = 0.03/2;
    double factor = 100;

    for (int ai = -3*factor; ai < 3*factor; ai++)
    {
        double a = ai/factor;
        for (int bi=-3*factor; bi < 3*factor; bi++)
        {
            double b = bi/factor;
            complex<double> compz(a, b);
            complex<double> compz2 = compz * compz;
            complex<double> compzroot = sqrt(compz);
            complex<double> compzmap1 = compz + polar(1/norm(compz),-arg(compz));
            
            double r = abs(compz);
            if (r > 1.0)
            {
                double t = (r - 1.0) / 2.0;
                string colour = interpolateColour(t);

                file1 << "<circle "
                 << "cx=\"" << compz.real() << "\" "
                 << "cy=\"" << compz.imag() << "\" "
                 << "r=\"" << dotRadius << "\" "
                 << "fill=\"" << colour << "\"/>\n";
                file2 << "<circle "
                 << "cx=\"" << compz2.real() << "\" "
                 << "cy=\"" << compz2.imag() << "\" "
                 << "r=\"" << dotRadius << "\" "
                 << "fill=\"" << colour << "\"/>\n";
                file3 << "<circle "
                 << "cx=\"" << compzroot.real() << "\" "
                 << "cy=\"" << compzroot.imag() << "\" "
                 << "r=\"" << dotRadius << "\" "
                 << "fill=\"" << colour << "\"/>\n";
                file4 << "<circle "
                 << "cx=\"" << compzmap1.real() << "\" "
                 << "cy=\"" << compzmap1.imag() << "\" "
                 << "r=\"" << dotRadius << "\" "
                 << "fill=\"" << colour << "\"/>\n";
            }
            
        }
        
    }
        
    file1 << "</g>\n";
    file1 << "</svg>\n";
    file1.close();
    file2 << "</g>\n";
    file2 << "</svg>\n";
    file2.close();
    file3 << "</g>\n";
    file3 << "</svg>\n";
    file3.close();
    file4 << "</g>\n";
    file4 << "</svg>\n";
    file4.close();
}
    // // prints the real part using the real function
    // cout << "Real part: " << real(mycomplex) << endl;
    // cout << "Imaginary part: " << imag(mycomplex) << endl;

    // // prints the absolute value of the complex number
    // cout << "The absolute value of " << mycomplex << " is: ";
    // cout << abs(mycomplex) << endl;

    // // prints the argument of the complex number
    // cout << "The argument of " << mycomplex << " is: ";
    // cout << arg(mycomplex) << endl;

    // cout << "The complex whose magnitude is " << abs(mycomplex);
    // cout << " and phase angle is " << arg(mycomplex);
    // // use of polar()
    // cout << " is " << polar(abs(mycomplex), arg(mycomplex)) << endl;

    // // use of norm()
    // cout << "The norm of " << mycomplex << " is "
    //      << norm(mycomplex) << endl;

    // cout << "The conjugate of " << mycomplex << " is: ";

    // // use of conj()
    // cout << conj(mycomplex) << endl;

    // cout << "The sqrt of " << mycomplex << " is: ";
    // cout << sqrt(mycomplex) << endl;
