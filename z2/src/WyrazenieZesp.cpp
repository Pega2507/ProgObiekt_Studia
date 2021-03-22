#include "WyrazenieZesp.hh"

void Wyswietl(WyrazenieZesp WyrZ)
{
    char znak;

    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        znak = '+';
        break;

    case Op_Odejmij:
        znak = '-';
        break;

    case Op_Mnoz:
        znak = '*';
        break;

    case Op_Dziel:
        znak = '/';
        break;
    }
    std::cout << WyrZ.Arg1 << znak << WyrZ.Arg2 << std::endl;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        return WyrZ.Arg1 + WyrZ.Arg2;
        break;

    case Op_Odejmij:
        return WyrZ.Arg1 - WyrZ.Arg2;
        break;

    case Op_Mnoz:
        return WyrZ.Arg1 * WyrZ.Arg2;
        break;

    case Op_Dziel:
        return WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & W)
{
    char znak;

    switch (W.Op)
    {
    case Op_Dodaj:
        znak = '+';
        break;

    case Op_Odejmij:
        znak = '-';
        break;

    case Op_Mnoz:
        znak = '*';
        break;

    case Op_Dziel:
        znak = '/';
        break;
    }
    std::cout << W.Arg1 << znak << W.Arg2 << std::endl;
}