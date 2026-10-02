// inkscape hexagonalGrid.svg --export-type=png --export-width=2048 --export-filename=hexagonalGrid.png

#include <array>
#include <cmath>
#include <fstream>

using namespace std;

using Vec2 = array<double, 2>;
using Vec7 = array<double, 7>;

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
    Vec7 hexX = {1.5, 0, -1.5, -1.5, 0, 1.5, 1.5};

    Vec7 hexY =
        sqrt(3) * Vec7{0.5, 1, 0.5, -0.5, -1, -0.5, 0.5};

    Vec7 newhexX;
    Vec7 newhexY;

    Vec2 genT = {3, 0};

    Vec2 genS = {1.5, sqrt(3) * 1.5};

    Vec2 trans;

    int kmax = 20;
    int lmax = 20;

    ofstream file("hexagonalGrid.svg");

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
         << "viewBox=\"-25 -25 50 50\">\n";

    file << "<g transform=\"scale(1,-1)\">\n";

    for (int k = -kmax; k <= kmax; k++)
    {
        for (int l = -lmax; l <= lmax; l++)
        {
            trans = k * genT + l * genS;

            newhexX = hexX + trans[0];
            newhexY = hexY + trans[1];

            file << "<polyline points=\"";

            for (int i = 0; i < 7; ++i)
            {
                file << newhexX[i] << "," << newhexY[i];

                if (i < 6)
                    file << " ";
            }

            file << "\" fill=\"#99cc99\" stroke=\"#403340\" stroke-width=\"0.2\"/>\n";
        }
    }

    file << "</g>\n";
    file << "</svg>\n";

    file.close();
}