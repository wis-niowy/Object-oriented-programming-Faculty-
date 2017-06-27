#include "samolot.h"

samolot::samolot(double il_pal, int il_zal, string m_odl, int* cz_prz): ilosc_paliwa(il_pal), ilosc_zalogi(il_zal), miejsce_odlotu(m_odl)
{
	for (int i = 0; i < 2; i++)
	{
		czas_przylotu[i] = cz_prz[i];
	}
	if (ilosc_paliwa < 100) throw wyjatek_transportu("Zbyt malo paliwa.");
	if (il_zal < 3) throw wyjatek_transportu("Za mala zaloga.");
}

double samolot::sprawdz_ilosc_paliwa()
{
	if (ilosc_paliwa < 20) throw wyjatek_braku_paliwa("Samolot zostaje skierowany na najblizsze lotnisko.", ilosc_paliwa);
}

void samolot::zuzycie_paliwa(double ile)
{
	ilosc_paliwa = ilosc_paliwa - ile;
}

samolot_pasazerski::samolot_pasazerski(double il_pal, int il_zal, string m_odl, int* cz_prz, int max_miejsc, int il_pas): samolot(il_pal, il_zal, m_odl, cz_prz), max_liczba_miejsc(max_miejsc), ilosc_pasazerow(il_pas)
{
	double udzial = (double)ilosc_pasazerow / (double)max_liczba_miejsc;
	if (udzial < 0.51) throw wyjatek_oplacalnosci(udzial);
}

void samolot_pasazerski::info()
{
	cout << "Samolot pasazerski z " << miejsce_odlotu << ", z " << ilosc_pasazerow << " pasazerami oraz " << ilosc_zalogi << " czlonakmi zalogi wyladowal o godz. " << czas_przylotu[0] << ":" << czas_przylotu[1] << endl;
}

samolot_transportowy::samolot_transportowy(double il_pal, int il_zal, string m_odl, int* cz_prz, double max_l, double tow): samolot(il_pal, il_zal, m_odl, cz_prz), max_ladownosc(max_l), towar(tow)
{
	double udzial = towar / max_ladownosc;
	if (udzial < 0.51) throw wyjatek_oplacalnosci(udzial);
}

void samolot_transportowy::oproznij_ladownie()
{
	towar = 0;
}

void samolot_transportowy::info()
{
	cout << "Samolot transporotwy z " << miejsce_odlotu << ", z ";
	cout << fixed << setprecision(1) << towar << " tonami towaru oraz ";
	cout << ilosc_zalogi << " czlonkami zalogi wyladowal o godz. " << czas_przylotu[0] << ":" << czas_przylotu[1] << endl;
}