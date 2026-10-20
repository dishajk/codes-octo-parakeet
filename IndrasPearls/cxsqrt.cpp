#include <iostream>

#include <complex>
using namespace std;

int main()
{
    // defines the complex number: (10 + 2i)
    complex<double> mycomplex(10.0, 2.0);

    // prints the real part using the real function
    cout << "Real part: " << real(mycomplex) << endl;
    cout << "Imaginary part: " << imag(mycomplex) << endl;

    // prints the absolute value of the complex number
    cout << "The absolute value of " << mycomplex << " is: ";
    cout << abs(mycomplex) << endl;

    // prints the argument of the complex number
    cout << "The argument of " << mycomplex << " is: ";
    cout << arg(mycomplex) << endl;

    cout << "The complex whose magnitude is " << abs(mycomplex);
    cout << " and phase angle is " << arg(mycomplex);
    // use of polar()
    cout << " is " << polar(abs(mycomplex), arg(mycomplex)) << endl;

    // use of norm()
    cout << "The norm of " << mycomplex << " is "
         << norm(mycomplex) << endl;

    cout << "The conjugate of " << mycomplex << " is: ";

    // use of conj()
    cout << conj(mycomplex) << endl;

    cout << "The sqrt of " << mycomplex << " is: ";
    cout << sqrt(mycomplex) << endl;

    return 0;
}