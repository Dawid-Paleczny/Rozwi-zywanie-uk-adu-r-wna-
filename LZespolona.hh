#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  void operator =(int Skl2){
    re = Skl2;
    im = 0;
    }
};

void Wyswietl(LZespolona);
/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  double Skl2);
bool operator == (LZespolona Skl1, LZespolona Skl2);
bool operator == (LZespolona Skl1, int Skl2);

ostream & operator << (ostream &StrmWej, LZespolona Arg);
istream & operator >> (istream &StrmWyj, LZespolona &Arg);
#endif
