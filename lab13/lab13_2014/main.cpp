#include <iostream>
#include <ctime>
#include "Talia.h"
#include "Gra.h"

using namespace std;


int main()
{
	srand(time(NULL));
	// postacie na kartach, ostatnia postac (Profesor) to piotrus
	const char* postacie[] = {"Smerfetka","Lalus","Wazniak","Osilek","Pracus","Maruda","Maryciel","Ciamajda","Lasuch","Spioch","Zgrywus","Harmoniusz","Gargamel"};


	/* *********************** ETAP 1 (1 pkt) *********************** */

	Talia smerfy(postacie);

	cout << "NOWA TALIA: " << endl;
	cout << smerfy << endl;

	/* *********************** ETAP 2 (1 pkt) *********************** */

	smerfy.potasuj();
	cout << "NOWA TALIA POTASOWANA: " << endl;
	cout << smerfy << endl;

	/* *********************** ETAP 3 (1.5 pkt) *********************** */

	Gra piotrus(smerfy);

	piotrus.rozdaj();
	cout << "ROZDANIE: " << endl;
	piotrus.wyswietl_karty();

	/* *********************** ETAP 4 (1.5 pkt) *********************** */

	piotrus.odrzuc_pary();
	cout << "ODRZUCENIE PAR: " << endl;
	piotrus.wyswietl_karty();

	/* *********************** ETAP 5 (1 pkt) *********************** */

	char ch;
	cout << "ULOZENIE KART: " << endl;
	cout << "Jak poukladac karty (domyslnie loswo)? (a - alfabetycznie, d - dlugosc napisu, o - odwrocenie)?" << endl;
	ch = getchar();
	fflush(stdin);
	piotrus.ukladaj(ch);
	piotrus.wyswietl_karty();

	/* *********************** ETAP 6 (2 pkt) *********************** */

	cout << "ROZGRYWKA: " << endl;
	piotrus.rozgrywka();
	
	system("PAUSE");
}

