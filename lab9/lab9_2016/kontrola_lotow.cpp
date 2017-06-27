#include <iostream> 
#include <string> 
#include <ctime>
#include "wyjatki.h"
#include "samolot.h"
#include "lista.h"
using namespace std;

void main()
{
	srand(time(NULL));
	//___________________________1__________________________
	cout << endl << "__________________TEST WYJATKOW__________________" << endl << endl;
	try 
	{
		throw wyjatek_transportu();
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
	}
	try
	{
		throw wyjatek_braku_paliwa("Ladujemy!",5.3);
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
	}
	try
	{
		throw wyjatek_oplacalnosci(0.33);
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
	}

	//___________________________2__________________________
	cout << endl << "__________________TEST SAMOLOTOW_________________" << endl << endl;
	int czas[] = { 10,37 };
	samolot *AT367;
	try
	{
		AT367 = new samolot_pasazerski(40.0, 5, "Modlin", czas, 300, 178);
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
		AT367 = new samolot_pasazerski(200.0, 5, "Modlin", czas, 300, 178);
		AT367->info();
	}
	try
	{
		AT367->zuzycie_paliwa(195.1);
		AT367->sprawdz_ilosc_paliwa();
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
	}
	cout << endl;
	czas[0] = 12; czas[1] = 30;
	samolot *GHT871W;
	try
	{
		GHT871W = new samolot_transportowy(200.0, 5, "Okecie", czas, 600, 178);
	}
	catch (const wyjatek_transportu &e)
	{
		e.info();
		GHT871W = new samolot_transportowy(200.0, 5, "Okecie", czas, 600, 578);
		GHT871W->info();
	}
	
	//___________________________3__________________________
	cout << endl << "__________________STARTUJEMY____________________" << endl << endl;
	double const MAX_PALIWO = 200.0;
	int const MAX_ZALOGA = 10;
	int const PORTY = 7;
	int const MIN_MIEJSC = 100;
	int const MAX_MIEJSC = 300;
	double const MIN_LADOWNOSC = 200;
	double const MAX_LADOWNOSC = 500;
	int const SAMOLOTY = 10;
	string porty[] = { "Warszawa","Modlin","Krakow","Gdansk","Katowice","Poznan","Lodz" };
	int zaloga, lotnisko, miejsca, pasazerowie;
	double paliwo, ladownosc, towar;
	lista w_powietrzu;
	while (w_powietrzu.size() < SAMOLOTY / 2)
	{
		try
		{
			paliwo = ((double)rand()*MAX_PALIWO / RAND_MAX);
			zaloga = rand() % MAX_ZALOGA + 1;
			lotnisko = rand() % PORTY;
			czas[0] = rand() % 24;
			czas[1] = rand() % 60;
			miejsca = rand() % (MAX_MIEJSC - MIN_MIEJSC) + MIN_MIEJSC;
			pasazerowie = rand() % miejsca;
			samolot *sp = new samolot_pasazerski(paliwo, zaloga, porty[lotnisko], czas, miejsca, pasazerowie);
			w_powietrzu.push_back(sp);
		}
		catch(const wyjatek_transportu &e)
		{
			e.info();
		}
	}
	cout << endl << "Wylecialo " << w_powietrzu.size() << " samolotow pasazerskich." << endl << endl;

	while (w_powietrzu.size() < SAMOLOTY)
	{
		try
		{
			paliwo = ((double)rand()*MAX_PALIWO / RAND_MAX);
			zaloga = rand() % MAX_ZALOGA + 1;
			lotnisko = rand() % PORTY;
			czas[0] = rand() % 24;
			czas[1] = rand() % 60;
			ladownosc = ((double)rand() / RAND_MAX)*(MAX_LADOWNOSC - MIN_LADOWNOSC) + MIN_LADOWNOSC;
			towar = ((double)rand()*ladownosc / RAND_MAX);
			samolot *sp = new samolot_transportowy(paliwo, zaloga, porty[lotnisko], czas, ladownosc, towar);
			w_powietrzu.push_back(sp);
		}
		catch (const wyjatek_transportu &e)
		{
			e.info();
		}
	}
	cout << endl << "Obecnie w powietrzu " << w_powietrzu.size() << " samolotow." << endl << endl;
	
	//___________________________4__________________________
	cout << endl << "__________________KONTROLA LOTOW_________________" << endl;
	cout << endl << "__________________LADOWANIA AWARYJNE_____________" << endl << endl;
	for (int j = 0; j < 10; j++) //10 godz. w powietrzu
	{
			for (int k = 1; k <= w_powietrzu.size(); k++)
			{
				try
				{
					w_powietrzu.get(k)->ufo->zuzycie_paliwa(rand() % 20); // zmniejszanie ilosci paliwa kazdemu z samlotow
					w_powietrzu.get(k)->ufo->sprawdz_ilosc_paliwa(); // wyrzuci ewentualny wyjatek
				}
			catch (wyjatek_transportu &e)
			{
				e.info();
				if (dynamic_cast<samolot_transportowy*>(w_powietrzu.get(k)->ufo))
				{ // jesli transporotwy, to wyrzucamy ladunek
					samolot_transportowy *temp = dynamic_cast<samolot_transportowy*>(w_powietrzu.get(k)->ufo);
					temp->oproznij_ladownie();
				}
				w_powietrzu.get(k)->ufo->info(); // kierujemy na lotnisko
				w_powietrzu.remove(w_powietrzu.get(k)); // usun z listy
			}
			} // for
		
	}

	cout << endl << "__________________LADOWANIA PLANOWE______________" << endl << endl;

	for (int i = 0; i < w_powietrzu.size(); i++)
	{
		w_powietrzu.get(i + 1)->ufo->info();
	}

	
	cout<<endl;
	system("pause");
}