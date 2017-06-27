#include "Kurierzy.h"

#if TEST_02 == 1
void FirmaKurierska::print() {
	cout << "Wypisywanie stanu firmy kurierskiej:" << endl;
	for (int i = 0; i < FirmaKurierska::ILOSC_KURIEROW; ++i) {
		kurierzy[i].print();
	}
}
#endif

Paczka::StatusPaczki Paczka::print() {
	if (status == NIEPRAWIDLOWA) {
		cout << "Paczka nieprawid³owa!" << endl;
	}
	else {
		cout << "Paczka nr: " << id << " status: " << (status == NOWA ? "nowa" : status == W_DORECZENIU ? "w doreczeniu" : "doreczona") << endl;
	}
	return status;
}

void Kurier::print() {
	cout << "Kurier " << id << " sprobuje dostarczyc dzis " << iloscPaczek << " paczek" << endl;
}
/////////////////////// 1 ETAP /////////////////////////////////////
Kurier::Kurier()
{
	iloscPaczek = 0;
	id = idkuriera;
	idkuriera++;
	for (int i = 0; i < MAX_PACZEK_U_KURIERA; i++)
	{
		paczki[i] = nullptr;
	}
}
Paczka Paczka::przygotujPaczke()
{
	Paczka nowa;
	nowa.id = idpaczki;
	idpaczki++;
	nowa.status = NOWA;
	return nowa;
}
//////////////////////////// 2 ETAP /////////////////////////////////
bool Sortownia::przyjmijPaczke(const Paczka & paczka)
{
	if (iloscPaczek < MAX_PACZEK_W_SORTOWNI)
	{
		paczki[iloscPaczek] = paczka;
		iloscPaczek++;
		return true;
	}
	else return false;
}
bool Paczka::prawidlowa() const
{
	if (status != NIEPRAWIDLOWA) return true;
	else return false;
}
bool FirmaKurierska::odbierzPaczke(Paczka paczka)
{
	if (paczka.prawidlowa())
	{
		if (sortownia.przyjmijPaczke(paczka))
			return true;
	}
	else return false;
}
//////////////////////////////// 3 ETAP /////////////////////////
bool Kurier::doreczPaczke(Paczka & paczka)
{
	if (iloscPaczek < MAX_PACZEK_U_KURIERA)
	{
		paczki[iloscPaczek] = &paczka;
		iloscPaczek++;
		paczka.status = (Paczka::StatusPaczki) 2;
		return true;
	}
	else return false;
}
int FirmaKurierska::rozpocznijDzien()
{
	for (int i = 0; i < sortownia.iloscPaczek; i++)
	{
		kurierzy[i % ILOSC_KURIEROW].doreczPaczke(sortownia.paczki[i]);
	}
	return 0;
}
int Kurier::rozliczPaczki()
{
	int licznik = 0;
	for (int i = 0; i < iloscPaczek; i++)
	{
		if (paczki[i]->status == (Paczka::StatusPaczki) 2)
		{
			paczki[i]->status = (Paczka::StatusPaczki) 3;
			licznik++;
		}
	}
	return licznik;
}
int FirmaKurierska::zamknijDzien()
{
	int suma = 0;
	for (int i = 0; i < ILOSC_KURIEROW; i++)
	{
		suma = suma + kurierzy[i].rozliczPaczki();
	}
	return suma;
}
////////////////////////////// 4 ETAP ////////////////////////////
bool Sortownia::operator+=(const Paczka& paczka)
{
	if (paczka.prawidlowa())
	{
		paczki[iloscPaczek] = paczka;
		iloscPaczek++;
		return true;
	}
	else return false;
}
bool Kurier::operator+=(Paczka& paczka)
{
	if (paczka.prawidlowa())
	{
		paczki[iloscPaczek] = &paczka;
		iloscPaczek++;
		return true;
	}
	else return false;
}
bool FirmaKurierska::operator+=(const Paczka& paczka)
{
	if (paczka.prawidlowa())
	{
		sortownia += paczka;
		return true;
	}
	else return false;
}