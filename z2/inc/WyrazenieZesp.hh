#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
class WyrazenieZesp 
{
private:
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
public:
  WyrazenieZesp();
  void Wyswietl();
  LZespolona Oblicz();
  const LZespolona get_Arg1()const {return Arg1;}
  const LZespolona get_Arg2()const {return Arg2;}
  const Operator get_Op()const {return Op;}
  void set_Arg1(LZespolona a){Arg1=a;}
  void set_Arg2(LZespolona b){Arg2=b;}
  void set_Op(Operator c){Op=c;}
};

  std::ostream & operator << (std::ostream & strm, const WyrazenieZesp & W);
  std::istream & operator >> (std::istream & strm, WyrazenieZesp & W);



#endif
