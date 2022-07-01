#ifndef SWEKTOR_HH
#define SWEKTOR_HH

#include "rozmiar.h"
#include <iostream>
using namespace std;


template <typename STyp, int SWymiar>
class Wektor {
    STyp  _Wsp[SWymiar];
  public:
    Wektor() { for (STyp &Wsp: _Wsp) Wsp = 0; }
  
    STyp  operator [] (unsigned int Ind) const { return _Wsp[Ind]; }
    STyp &operator [] (unsigned int Ind)       { return _Wsp[Ind]; }

    Wektor<STyp,SWymiar> operator - (const Wektor<STyp,SWymiar> &Odjemnik) const;
    Wektor<STyp,SWymiar> operator * (double Mnoznik) const;
};




template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator - (const Wektor<STyp,SWymiar> &Odjemnik) const
{
  Wektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
  return Wynik;
}


template <typename STyp, int SWymiar>
Wektor<STyp,SWymiar> Wektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
  Wektor<STyp,SWymiar>  Wynik;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) Wynik[Ind] = (*this)[Ind]*Mnoznik;
  return Wynik;  
}


template <typename STyp, int SWymiar>
ostream& operator << (ostream &StrmWyj, const Wektor<STyp,SWymiar>& W)
{

  StrmWyj << endl;

  for (unsigned int Ind = 0; Ind < SWymiar; ++Ind) {
    cout.width(6);
    StrmWyj << left << W[Ind] << ' ';
  }  
  return StrmWyj << endl;
}

template <typename Typ, int wymiar>
istream& operator >> (istream &Strm, Wektor<Typ,wymiar> &Wek)
{
  for(int i = 0; i < ROZMIAR; i++){
    Strm >> Wek[i];
  }
  return Strm;
}

#endif
