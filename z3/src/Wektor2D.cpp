#include "Wektor2D.hh"

Wektor2D::Wektor2D()
{
    xy.push_back(0);
    xy.push_back(0);
}

Wektor2D::Wektor2D(double x, double y)
{
    xy.push_back(x);
    xy.push_back(y);
}

 Wektor2D Wektor2D::operator+(const Wektor2D &arg2) 
{
    Wektor2D Wynik;
   Wynik[0] = xy[0] + arg2[0];
    Wynik[1] = xy[1] + arg2[1];
    return Wynik;
}

 Wektor2D Wektor2D::operator-(const Wektor2D &arg2) 
{
    Wektor2D Wynik;
    Wynik[0] = xy[0] - arg2[0];
    Wynik[1] = xy[1] - arg2[1];
    return Wynik;
}

Wektor2D Wektor2D::operator*(double arg2)
{
    Wektor2D Wynik;
    Wynik[0] = xy[0] * arg2;
    Wynik[1] = xy[1] * arg2;
    return Wynik;
}

Wektor2D Wektor2D::operator/(double arg2)
{
    Wektor2D Wynik;
    Wynik[0] = xy[0] / arg2;
    Wynik[1] = xy[1] / arg2;
    return Wynik;
}

double Wektor2D::operator*(const Wektor2D &arg2)
{
    return xy[0] * arg2[0] + xy[1] * arg2[1];
}

const double &Wektor2D::operator[](int ind) const
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec!" << std::endl;
    return xy[ind];
}
double &Wektor2D::operator[](int ind)
{
    if (ind < 0 || ind > 1)
        std::cerr << "Odwolanie poza pamiec!" << std::endl;
    return xy[ind];
}

std::istream &operator>>(std::istream &Strm, Wektor2D &Wek)
{
    for (int i = 0; i < 2; i++)
        Strm >> Wek[i];

    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const Wektor2D &Wek)
{
    for (int i = 0; i < 2; i++)
        Strm << Wek[i] << " ";

    return Strm;
}