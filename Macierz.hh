#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>

using namespace std;

template <typename Typ, int rozmiar>
class Macierz {
private:
  Wektor<Typ, rozmiar> _kolumny[rozmiar];//Przechowuje liczby zorganizowane jako ciało macierzy
public:
  //  double operator *(Wektor<Typ, rozmiar>)const;
  /*Zwraca kopię wektora będącego daną kolumną*/
  Wektor<Typ, rozmiar> operator[](int index)const{
    return _kolumny[index];
  }
  /*Zwraca referencję do wektora będącego daną kolumną*/
  Wektor<Typ, rozmiar>& operator[](int index){
    return _kolumny[index];
  }
  /*Zwraca liczbę będącą w danym położeniu w macierzy*/
  Typ operator ()(int rzad, int kolumna)const{
    return _kolumny[kolumna][rzad];
  }
  /*Zwraca referencję do liczby będącej w danym położeniu macierzy*/
  Typ& operator ()(int rzad, int kolumna){
    return _kolumny[kolumna][rzad];
  }
  void eye();
  void Wstaw(int, Wektor<Typ, rozmiar>);
  Typ wyznacznik();
};



/*Realizuje wypisanie zadanego układu równań na ekranie*/
template <typename Typ, int rozmiar>
ostream& operator << (ostream &Strm, const Macierz<Typ, rozmiar> &Mac)
{
  for (int i = 0; i < ROZMIAR; i++){
    Strm << Mac[i];
  }
  return Strm << endl;
}

/*Odczytuje z ekranu do zadanej zmiennej i od razu oblicza wyznacznik*/
template <typename Typ, int rozmiar>
istream& operator >> (istream &Strm, Macierz<Typ, rozmiar> &Mac)
{
  for (int i = 0; i < rozmiar; i++){
    Strm >> Mac[i];
  }
  return Strm;
}

/*Oblicz wyznacznik metodą Gaussa. Macierz musi być wyznacznikowalna.*/
template <typename Typ, int rozmiar>
Typ Macierz<Typ, rozmiar>::wyznacznik()
{
  Typ wyznacznik;
  wyznacznik = 1;
    
  Macierz<Typ, rozmiar> kopia(*this);//funkcja działa na kopii
  for (int i = 0; i < (rozmiar - 1); i++){
    for (int j = i + 1; j < rozmiar; j++){
      Typ dzielnik = kopia(j,i) / kopia(i,i);
      for(int k = 0; k < rozmiar; k++){
	kopia(j,k) = kopia(j,k) - (dzielnik * kopia(i,k));
      }
    }
  }
  /*Po doprowadzeniu do postaci diagonalnej pozostaje tylko pomnożyć liczby z przekątnej*/
  for (int i = 0; i < ROZMIAR; i++){
    wyznacznik = wyznacznik * kopia(i,i);
  }
  return wyznacznik;
}

/*Wstawia w zadaną kolumne macierzy inną kolumnę, przekazywaną jako wektor wstawiony*/
template <typename Typ, int rozmiar>
void Macierz<Typ, rozmiar>::Wstaw(int miejsce, Wektor<Typ, rozmiar> wstawiany)
{
  this->_kolumny[miejsce] = wstawiany;
}

/*Realizuje mnożenie macierzy przez wektor*/
/*template <typename Typ, int rozmiar>
Wektor<Typ, rozmiar> Macierz<Typ, rozmiar>::operator *(Wektor<Typ, rozmiar> wek)const
{
  Wektor<Typ, rozmiar> wynik;
  for(int i = 0; i < rozmiar; i++){
    for(int j = 0; j < rozmiar; j++){
      wynik[j] += _kolumny[j][i] * wek[i];
    }
  }
  return wynik;
  }*/



#endif
