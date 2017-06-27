#include <iostream>
#include <cmath>
using namespace std;
#include "zwierz.h"
//--------------------------------------------
// FUNKCJA MAIN - POZOSTAJE BEZ ZMIAN !
//--------------------------------------------

int main() {

	zwierz zoo[] = { { PIES,"Reksio",5 },{ KOT,"Mruczek",4 },{ KOT,"Bonifacy",3 },{ KOT,"Leniwiec",2 },
	{ PIES,"Pimpek",4 },{ PIES,"Reksio",3 },{ KOT,"Mruczek",2 },{ MYSZ,"Gryzunia",3 },
	{ MYSZ,"Lola",5 },{ KOT,"Filutek",2 },{ MYSZ,"Frania",2 },{ MYSZ,"Gryzunia",1 } };

	int n = sizeof(zoo) / sizeof(zwierz);
	int K;

	do {
		cout << endl << "ZOO:" << endl;
		wypisz(zoo, n);

		cout << "\nMENU:";
		cout << "\n1 - zoo wg wiek";
		cout << "\n2 - zoo wg imie_wiek";
		cout << "\n3 - zoo wg typ_imie_wiek";
		cout << "\n0 - KONIEC";
		cout << "\n*** Podaj numer opcji:  ";

		cin >> K;
		switch (K)
		{
		case 1:	//zoo wg wiek
			sortuj(zoo, n, wiek);
			break;

		case 2:	//zoo wg imie_wiek
			sortuj(zoo, n, imie_wiek);
			break;

		case 3:	//zoo wg typ_imie_wiek
			sortuj(zoo, n, typ_imie_wiek);
			break;
		}//switch


	} while (K != 0);

		system("PAUSE");
}
