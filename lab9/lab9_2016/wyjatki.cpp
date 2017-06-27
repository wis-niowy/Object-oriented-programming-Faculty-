#include "wyjatki.h"

wyjatek_transportu::wyjatek_transportu(string _wiad): wiadomosc(_wiad)
{

}

void wyjatek_transportu::info() const
{
	cout << "Samolot nie odleci." << endl;
}

wyjatek_braku_paliwa::wyjatek_braku_paliwa(string _wiad, double _pal): wyjatek_transportu(_wiad), paliwo(_pal)
{

}


void wyjatek_braku_paliwa::info() const
{
	cout << "Pozotalo " << paliwo << " ton paliwa. " << wiadomosc << endl;
}

wyjatek_oplacalnosci::wyjatek_oplacalnosci(double _zal): zaladunek(_zal)
{

}

void wyjatek_oplacalnosci::info() const
{
	cout << fixed << setprecision(1) << zaladunek * 100 << " % maksymalnej ladownosci. Samolot nie odleci." << endl;
}