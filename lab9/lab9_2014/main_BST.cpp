#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "BST.h"

using namespace std;

void main()
{
	int i;
	BST bst;
	while (true)
	{
		cout << "  \nWybierz operacje" << endl;
		cout << "  1 - wstawienie elementu" << endl;
		cout << "  2 - usuniecie elementu" << endl;
		cout << "  3 - wyszukanie elementu" << endl;
		cout << "  4 - wypisanie calego drzewa" << endl;
		cout << "  0 - koniec" << endl;
		cout << "      ";
		cin >> i;

		// dopisz wylapywanie wyjatkow generowanych przez program
		// po wylapaniu powinien byc wypisany odpowiedni komunikat
		// a program powinien dzialac dalej

		// NIE WOLNO NIC ZMIENIAC W ISTNIEJACYM KODZIE !!!
		// WOLNO JEDYNIE DOPISAC OBSLUGE WYJATKOW !!!
		try
		{
			switch (i)
			{
			case 1:
				cout << endl << "  Podaj wartosc wstawianego elementu:  ";
				int v1;
				cin >> v1;
				bst.Insert(v1);
				cout << endl << "  Wstawiono element " << v1 << endl;
				break;
			case 2:
				cout << endl << "  Podaj wartosc usuwanego elementu:  ";
				int v2;
				cin >> v2;
				bst.Remove(v2);
				cout << endl << "  Usunieto element " << v2 << endl;
				break;
			case 3:
				cout << endl << "  Podaj sciezke do elementu:  ";
				char p[256];
				cin >> p;
				i = bst.Find(p);
				cout << endl << "  Wskazany element jest rowny " << i << endl;
				break;
			case 4:
				cout << endl << "  Wszystkie elementy drzewa" << endl;
				bst.Show();
				cout << endl;
				break;
			case 0:
				return;
			}
		}

		///////////////////////////////////////////////

		catch (const value_exception &e)
		{
			e.komunikat();
		}
		catch (const path_exception &e)
		{
			e.komunikat();
		}
		
	}
}