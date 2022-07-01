#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"
#include <math.h>

using namespace std;

/*Klasa modeluje pojęcie układu równań liniowych - zaiwra macierz współczynników, 
  wektor rozwiązań i wektor wyrazów wolnych oraz miejsce do przechowywania błędów przyobliczeniach.*/
template<typename Typ, int rozmiar>
class UkladRownan {
private:
  Macierz<Typ, rozmiar> _wspolczynniki;
  Wektor<Typ, rozmiar> _wyniki;
  Wektor<Typ, rozmiar> _rozwiazania;
public:
  Macierz<Typ, rozmiar>& wspolczynniki(){
    return _wspolczynniki;
  }
  Macierz<Typ, rozmiar> wspolczynniki() const{
    return _wspolczynniki;
  }
  Wektor<Typ, rozmiar>& wyniki(){
    return _wyniki;
  }
  Wektor<Typ, rozmiar> wyniki() const{
    return _wyniki;
  }
  Wektor<Typ, rozmiar> rozwiazania()const{
    return _rozwiazania;
  }
  int WyznaczWyniki();
};

/*Odczytuje z terminala Układ równań*/
template<typename Typ, int rozmiar>
istream& operator >> (istream &Strm, UkladRownan<Typ, rozmiar> &UklRown)
{
  Strm >> UklRown.wspolczynniki();
  Strm >> UklRown.wyniki();
  return Strm;
}

/*Realizuje wyświtlanie na ekranie układu równań w formie macierzy współczynników oraz wektora wyrazów wolnych*/
template<typename Typ, int rozmiar>
ostream& operator << (ostream &Strm, const UkladRownan<Typ, rozmiar> &UklRown)
{
  Strm << UklRown.wspolczynniki();
  Strm << UklRown.wyniki();
  return Strm << endl;
}

/*Na podstawie wyznaczników macierzy z podstawioną kolumną wyrazów wolnych, ze wzorów Cramera oblicza rozwiązania oraz błąd obliczeń.*/
template<typename Typ, int rozmiar>
int UkladRownan<Typ, rozmiar>::WyznaczWyniki()
{
  Typ wyznacznik = _wspolczynniki.wyznacznik();
  
  if(wyznacznik == 0){
    for (int i = 0; i < rozmiar; i++){
      Macierz<Typ, rozmiar>* temp = new Macierz<Typ, rozmiar>(this->_wspolczynniki);
      temp->Wstaw(i, this->_wyniki);

      if(!(temp->wyznacznik() == 0)){
	return 2;
      }
      return 1;
    }
  }
  for(int i = 0; i < rozmiar; i++){
    Macierz<Typ, rozmiar>* temp = new Macierz<Typ, rozmiar>(this->_wspolczynniki);
    temp->Wstaw(i, this->_wyniki);
    this->_rozwiazania[i] = temp->wyznacznik() / wyznacznik;
    delete temp;
  }
  

  return 0;
}


#endif
