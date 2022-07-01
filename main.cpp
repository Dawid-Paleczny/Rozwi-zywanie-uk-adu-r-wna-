#include <iostream>
#include <cstring>
#include "LZespolona.hh"
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"
#include <cstdio>

using namespace std;

int main(int argc, char* argv[])
{
  
  cout << endl << " Start programu " << endl;

  if(argc < 2){
    cout << "Nie podales typu rownania. r - rzeczywiste z - zespolone." << endl;
    int zatrzymanie = getchar();
    return 1;
  }

  if(strcmp(argv[1],"r") == 0){
    UkladRownan<double, ROZMIAR> Ukl;

    cin >> Ukl;
    cout << Ukl;

    switch(Ukl.WyznaczWyniki()){
    case 2:
      cout << "Uklad rownan sprzeczny. Do widzenia.";
      break;
    case 1:
      cout << "Uklad rownan tozsamosciowy. Pozdrawiam goraco.";
      break;
    case 0:
      cout << "Rozwiazania:\n" << Ukl.rozwiazania() << endl;
    }
  }
  else if(strcmp(argv[1], "z") == 0){
    UkladRownan<LZespolona, ROZMIAR> Ukl;
    << "    Wpisuj paremetry w postaci ([+lub-]a[+lub-]bi) np (1+2i)"
    cin >> Ukl;
    cout << Ukl;

    switch(Ukl.WyznaczWyniki()){
    case 2:
      cout << "Uklad rownan sprzeczny. Do widzenia.";
      break;
    case 1:
      cout << "Uklad rownan tozsamosciowy. Pozdrawiam goraco.";
      break;
    case 0:
      cout << "Rozwiazania:\n" << Ukl.rozwiazania() << endl;
    }
  }
  else{
    cout << "Podales bledny argument wywolania. r - rzeczywiste z - zespolone" << endl;
    return 2;
  }
}
