#include "Klinika.h"

#if TEST_02 == 1
void Klinika::print() {
	cout << "Wypisywanie stanu kliniki:" << endl;
	for (int i = 0; i < Klinika::ILOSC_LEKARZY; ++i) {
		lekarze[i].print();
	}
}
#endif

Pacjent::StatusPacjenta Pacjent::print() {
	if (status == BRAK) {
		cout << "Pacjent nieobecny!" << endl;
	}
	else {
		cout << "Pacjent nr: " << id << " status: " << (status == OCZEKUJACY ? "oczekujacy" : status == W_GABINECIE ? "w gabinecie" : "obsluzony") << endl;
	}
	return status;
}

void Lekarz::print() {
	cout << "Lekarz " << id << " sprobuje obsluzyc dzis " << iloscPacjentow << " pacjentow" << endl;
}
////////////////////////////////////////
Lekarz::Lekarz()
{
	iloscPacjentow = 0;
	for (int i = 0; i < MAX_PACJENTOW_U_LEKARZA; i++)
	{
		pacjenci[i] = NULL;
	}
	id = numerid;
	numerid++;
}
Pacjent Pacjent::nowyPacjent()
{
	Pacjent nowy;
	nowy.id = numerid;
	numerid++;
	nowy.status = OCZEKUJACY;
	return nowy;
}
///////////////////////////////////////
bool Poczekalnia::zarejestruj(const Pacjent & pacjent)
{
	if (iloscPacjentow < DZIENNY_LIMIT_PACJENTOW)
	{
		if (pacjent.obecny())
		{
			kolejka[iloscPacjentow] = pacjent;
			iloscPacjentow++;
			return true;
		}
	}
	else return false;
}
bool Pacjent::obecny() const
{
	if (status != BRAK) { return true; }
	else return false;
}
bool Klinika::przyjmijPacjenta(Pacjent pacjent)
{
	if (pacjent.obecny())
	{
		if(poczekalnia.zarejestruj(pacjent)) return true;
	}
	else return false;
}
///////////////////////////////////////////////////////////
bool Lekarz::diagnozuj(Pacjent & pacjent)
{
	if (iloscPacjentow < MAX_PACJENTOW_U_LEKARZA)
	{
		pacjenci[iloscPacjentow] = &pacjent;
		iloscPacjentow++;
		pacjent.status = (Pacjent::StatusPacjenta)2;
		return true;
	}
	else return false;
}
int Klinika::rozpocznijPrace()
{
	for (int i = 0; i < poczekalnia.iloscPacjentow; i++)
	{
		lekarze[i % ILOSC_LEKARZY].diagnozuj(poczekalnia.kolejka[i]);
	}
	return 0;
}
int Lekarz::zdajRaport()
{
	int licznik = 0;
	for (int i = 0; i < iloscPacjentow; i++)
	{
		if (pacjenci[i]->status == (Pacjent::StatusPacjenta) 2)
		{
			pacjenci[i]->status == (Pacjent::StatusPacjenta) 3;
			licznik++;
		}
	}
	return licznik;
}
int Klinika::zakonczPrace()
{
	int suma = 0;
	for (int i = 0; i < ILOSC_LEKARZY; i++)
	{
		suma = suma + lekarze[i].zdajRaport();
	}
	return suma;
}