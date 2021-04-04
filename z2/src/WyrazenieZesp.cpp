#include "WyrazenieZesp.hh"

WyrazenieZesp::WyrazenieZesp()
{
    Arg1 = 0;
    Arg2 = 0;
}

void WyrazenieZesp::Wyswietl()
{
    char znak;

    switch (Op)
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
    std::cout << Arg1 << znak << Arg2 << std::endl;
}

LZespolona WyrazenieZesp::Oblicz()
{
    switch (Op)
    {
    case Op_Dodaj:
        return Arg1 + Arg2;
        break;

    case Op_Odejmij:
        return Arg1 - Arg2;
        break;

    case Op_Mnoz:
        return Arg1 * Arg2;
        break;

    case Op_Dziel:
        return Arg1 / Arg2;
        break;
    }
}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & W)
{
    char znak;
    Operator _Op;
    LZespolona _Arg1, _Arg2;
    _Op = W.get_Op();
    _Arg1 = W.get_Arg1();
    _Arg2 = W.get_Arg2();
    switch (_Op)
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
    std::cout << _Arg1 << znak << _Arg2 << std::endl;
    return strm;
}

std::istream & operator >> (std::istream & strm, WyrazenieZesp & W)
{
    Operator _Op;
    LZespolona _Arg1, _Arg2;
    char znak;
    strm>>_Arg1;
    W.set_Arg1(_Arg1);
    strm>>znak;
    switch (znak)
    {
    case '+':
        _Op = Op_Dodaj;
        break;

    case '-':
        _Op = Op_Odejmij;
        break;

    case '*':
        _Op = Op_Mnoz;
        break;

    case '/':
        _Op = Op_Dziel;
        break;
    default:
        strm.setstate(std::ios::failbit);
    }
    W.set_Op(_Op);
    strm>>_Arg2;
    W.set_Arg2(_Arg2);
    return strm;
}
