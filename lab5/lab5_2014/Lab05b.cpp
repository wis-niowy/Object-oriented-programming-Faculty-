
#include <iostream>
#include "kolejkaprior.h"

using namespace std;

void main()
    {

    cout << endl << "#####  Etap I  ( 4p )  #####" << endl;

    
    cout << endl << "Tworzenie kolejki k1" << endl;
    KolejkaPrior k1;

    cout << endl << "Wstawianie do kolejki k1" << endl;
    k1.Wstaw(7);
    k1.Wstaw(5);
    k1.Wstaw(12);
    k1.Wstaw(10);
    
    cout << endl << "Tworzenie kolejki k2" << endl;
    KolejkaPrior k2=k1;

    cout << endl << "Wstawianie do kolejki k2" << endl;
    k2.Wstaw(8);
    

    cout << endl << "#####  Etap II  ( 1p )  #####" << endl;

    
    cout << endl << "Wypisywanie kolejki k1" << endl;
    cout << k1 << endl;
    cout << endl << "Wypisywanie kolejki k2" << endl;
    cout << k2 << endl;
    int x;
    cout << endl << "Pobieranie z kolejki k1" << endl;
    x=k1.Pobierz();
    cout << "Pobrano z k1 : " << x << endl;
    x=k1.Pobierz();
    cout << "Pobrano z k1 : " << x << endl;
    x=k1.Pobierz();
    cout << "Pobrano z k1 : " << x << endl;
    x=k1.Pobierz();
    cout << "Pobrano z k1 : " << x << endl;
    x=k1.Pobierz();
    cout << "Pobrano z k1 : " << x << endl;

    cout << endl << "Pobieranie z kolejki k2" << endl;
    x=k2.Pobierz();
    cout << "Pobrano z k2 : " << x << endl;
	cout << endl << "Wypisywanie kolejki k2" << endl; //dodane
	cout << k2 << endl; // dodane

    cout << endl << "#####  Etap III  ( 1p )  #####" << endl;


    cout << endl << "Sprawdzanie czy kolejka jest pusta" << endl;
    cout << "k1 jest pusta:  " << (k1.CzyPusta()?"true":"false") << endl;
    k1.Wstaw(4);
    k1.Wstaw(6);
    cout << "k1 jest pusta:  " << (k1.CzyPusta()?"true":"false") << endl;
    cout << "k2 jest pusta:  " << (k2.CzyPusta()?"true":"false") << endl;

    cout << endl << "Przypisanie k1=k2" << endl;
    k1=k2;

    cout << endl << "Wypisywanie kolejki k1" << endl;
    cout << k1 << endl;
    cout << endl << "Wypisywanie kolejki k2" << endl;
    cout << k2 << endl;

    cout << endl;
    k1.Pobierz();
    k2.Wstaw(2);

    cout << endl << "Wypisywanie kolejki k1" << endl;
    cout << k1 << endl;
    cout << endl << "Wypisywanie kolejki k2" << endl;
    cout << k2 << endl;

    cout << endl << "#####  Koniec  #####" << endl << endl;

    // Tu NIE WOLNO dopisywac niczego co zatrzyma program !!!
	//system("PASUE");
    }
