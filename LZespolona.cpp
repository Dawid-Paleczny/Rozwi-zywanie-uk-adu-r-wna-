#include "LZespolona.hh"
#include <cmath>


using namespace std;

const double Epsilon = 0.0001;
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - odjemna,
 *    Skl2 - odjemnik.
 * Zwraca:
 *    Różnicę dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnożenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy czynnik mnożenia,
 *    Skl2 - drugi czynik mnożenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re * Skl2.re) - (Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im) + (Skl2.re * Skl1.im);
  return Wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbę rzeczywistą.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 * Uwaga:
 * Dzielnik nie może być równy 0!
 */
LZespolona operator / (LZespolona Skl1, double Skl2)
{
  if (Skl2 == 0) {
    cerr << "Dzielnik nie moze byc zerem";
    return {0,0};
  }

  LZespolona Wynik;

  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - dzielna,
 *    Skl2 - dzielnik.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 * Uwaga:
 * Dzielnik nie może być równy 0, jednak obsługa tego błedu jest zawarta w funkcji
 * dzielenia liczby zespolonej przez rzeczywistą.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  LZespolona SprzezenieSkl2 = {Skl2.re, -Skl2.im};
  double ModulSkl2 = sqrt(pow(Skl2.re, 2) + pow(Skl2.im, 2));

  Wynik = Skl1 * SprzezenieSkl2 / pow(ModulSkl2, 2);
  return Wynik;
}


/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza liczba do porównania,
 *    Skl2 - druga liczba do porównania.
 * Zwraca:
 *    True, jeśli są identyczne i false, jeśli nie.
 * Uwaga:
 * Operator działa z dokładnością do Epsilon.
 */
bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if (abs(Skl1.re - Skl2.re) < Epsilon && abs(Skl1.im - Skl2.im) < Epsilon) {
    return true;
  }
  else {
    return false;
  }
}

/*!
 * Realizuje wyświetlanie liczby zespolonej w formacie (re+imi)
 */
ostream & operator << (ostream &StrmWyj, LZespolona Arg)
{
  StrmWyj << '(' << Arg.re << showpos << Arg.im << 'i' << noshowpos << ')';
  return StrmWyj;
}

/*!
 * Realizuje pobranie ze strumienia wejściowego liczby zespolonej w formacie (re+imi).
 * Uwaga:
 * W wypadku pomyłki w formacie liczby nie zostane ona wczytana do końca, a obiekt cin zostanie ustawiony w stan błędu.
 */
istream & operator >> (istream &StrmWej, LZespolona &Arg)
{
  char tmp;
  StrmWej.get(tmp);
  if (tmp != '(') {
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej >> Arg.re;
  StrmWej >> Arg.im;
  StrmWej.get(tmp);
  if (tmp != 'i'){
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej.get(tmp);
  if (tmp != ')'){
    StrmWej.setstate(ios::failbit);
    return StrmWej;
  }
  StrmWej.ignore();
  return StrmWej;
}

bool operator == (LZespolona Skl1, int Skl2)
{
  if(Skl1.re == Skl2 && Skl1.im == Skl2){
    return 1;
  }
  return 0;
}
