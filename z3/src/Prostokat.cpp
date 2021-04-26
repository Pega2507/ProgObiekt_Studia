#include "Prostokat.hh"

Prostokat::Prostokat(Wektor2D LG, Wektor2D PG, Wektor2D LD, Wektor2D PD)
{
    w.resize(2);
    for (int i = 0; i < 2; i++)
    {
        w[i].resize(2);
    }
    w[0][0] = LG;
    w[0][1] = PG;
    w[1][0] = PD;
    w[1][1] = LD;

    //sprawdzenie czy boki sa || i il.skalarny = 0 (kat 90)
    /* if(LG*PG==0 && LD*PD==0 ){
   w[0][0] = LG;
    w[0][1] = PG;
    w[1][0] = PD;
    w[1][1] = LD;

    }
    else
    {
        std::cerr<<"to nie prostokat"<<std::endl;
        exit(0);
    }*/
}

void Prostokat::przesun(Wektor2D &P)
{
    w[0][0] = P + w[0][0];
    w[0][1] = P + w[0][1];
    w[1][0] = P + w[1][0];
    w[1][1] = P + w[1][1];
}

void Prostokat::obroc(double kat_stopnie)
{
    MacierzRot2D m(kat_stopnie);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            w[i][j] = m * w[i][j];
}

const Wektor2D &Prostokat::operator()(int ind_x, int ind_y) const
{
    return w[ind_x][ind_y];
}
Wektor2D &Prostokat::operator()(int ind_x, int ind_y)
{
    return w[ind_x][ind_y];
}

void Prostokat::WysWierzcholki()
{
    std::cout << w[0][0] << "   " << w[0][1] << std::endl;
    std::cout << w[1][1] << "   " << w[1][0] << std::endl;
}

bool Prostokat::BokiRowne()
{
    double dlugoscA1, dlugoscA2, dlugoscB1, dlugoscB2;
    dlugoscA1 = sqrt(pow(w[0][0][0] - w[0][1][0], 2) + pow(w[0][0][1] - w[0][1][1], 2));
    dlugoscA2 = sqrt(pow(w[1][0][0] - w[1][1][0], 2) + pow(w[1][0][1] - w[1][1][1], 2));
    dlugoscB1 = sqrt(pow(w[0][0][0] - w[1][1][0], 2) + pow(w[0][0][1] - w[1][1][1], 2));
    dlugoscB2 = sqrt(pow(w[0][1][0] - w[1][0][0], 2) + pow(w[0][1][1] - w[1][0][1], 2));
    if ((dlugoscA1 == dlugoscA2) && (dlugoscB1 == dlugoscB2))
        return 1;
    else
        return 0;
    
}

std::ostream &operator<<(std::ostream &Strm, const Prostokat &Pr)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            Strm << Pr(i, j) << std::endl;
    }
    return Strm;
}