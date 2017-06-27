#include <windows.h>
#include <iostream>
using namespace std;
#include "karta.h"

// TUTAJ zaimplementuj brakuj¹ce sk³adowe i funkcje dla klasy karta


//----------------------------------------------
void karta::wypisz() const
{
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_new;

	if (kolor == KIER || kolor == KARO)	color_new = 12 + (7 << 4);	//czerwony na szarym tle
	else  color_new = 7 << 4;								//czarny na szarym tle

	SetConsoleTextAttribute(hconsole, color_new);

	char znak;
	if (figura > 8)
	{
		switch (figura)
		{
		case 9: znak = 'J';		break;
		case 10: znak = 'Q';	break;
		case 11: znak = 'K';	break;
		case 12: znak = 'A';	break;
		default: znak = static_cast<char>(figura + 50); break;
		}

		cout << znak << static_cast<char>(kolor) << " ";
	}
	else
		cout << figura + 2 << static_cast<char>(kolor) << " ";

	SetConsoleTextAttribute(hconsole, 15);
	cout << " ";
} //-------------------------------------------------
karta::karta(KOLOR _kolor, FIGURA _figura)
{
	kolor = _kolor;
	figura = _figura;
}
int karta::punkty() const
{
	if (figura > 8) return 10;
	else return 1;
}
bool operator>(const karta& k1, const karta& k2)
{
	if ((k1.getkolor() == 3 || k1.getkolor() == 4) && (k2.getkolor() == 5 || k2.getkolor() == 6))
		return true;
	else return false;
}
bool operator<(const karta& k1, const karta& k2)
{
	if ((k1.getkolor() == 5 || k1.getkolor() == 6) && (k2.getkolor() == 3 || k2.getkolor() == 4))
		return true;
	else return false;
}
bool operator==(const karta& k1, const karta& k2)
{
	if (k1.getkolor() == k2.getkolor()) return true;
	else if ((k1.getkolor() == 5 && k2.getkolor() == 6) || (k1.getkolor() == 6 && k2.getkolor() == 5))
		return true;
	else if ((k1.getkolor() == 3 && k2.getkolor() == 4) || (k1.getkolor() == 4 && k2.getkolor() == 3))
		return true;
	else return false;
}