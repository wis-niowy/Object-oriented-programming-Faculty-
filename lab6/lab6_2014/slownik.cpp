#define  _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include "slownik.h"

slownik::slownik(int _n, slowo* s): n(_n), nS(_n)
	{
		// UZUPE£NIJ
		// WYKORZYSTAJ metodê wstaw
		S = new slowo*[nS];
		for (int i = 0; i < nS; i++)
		{
			S[i] = nullptr;
		}
		for (int i = 0; i < n; i++)
		{
			wstaw(s[i]);
		}
	}

slownik::~slownik()
	{
		// UZUPE£NIJ
		// oprócz zwalniania pamiêci po tablicy, zwalniamy wczeœniej pamiêæ po danych
		//for (int i = 0; i < nS; i++)
		//{
		//	delete[] S[i];
		//} // tym zajmuje sie destruktor z klasy slowo (chyba)
		delete[] S;
	}

void slownik::wstaw(const slowo& s)
	{
		int indeks = 0;
		if (!S[0])
		{
			S[0] = new slowo(s);
			return;
		}
		for (int i = 0; i < nS; i = indeks)
		{
			if (s == *S[i]) return;
			if (s < *S[i]) indeks = 2 * i + 1;
			else indeks = 2 * i + 2;

			if (indeks > nS - 1)
			{
				slowo** temp = new slowo*[indeks + 1]; // realokacja tablicy wskaznikow S
				for (int k = 0; k < nS; k++)
				{
					temp[k] = S[k];
				}
				delete[]S;
				S = new slowo*[indeks + 1];
				for (int k = 0; k < indeks + 1; k++)
				{
					S[k] = temp[k];
				}
				delete[] temp; // koniec realokacji
				for (int i = nS; i < indeks; i++)
				{
					S[i] = nullptr;
				}
				S[indeks] = new slowo(s);
				nS = indeks + 1;
				return;
			}
			if (indeks > 0 && indeks < nS && !S[indeks])
			{
				S[indeks] = new slowo(s);
				return;
			}
		}
	}


void slownik::test() const
	{
		// UZUPE£NIJ
		int losowa;
		char tab[100];
		srand(time(NULL));
		do
		{
			losowa = rand() % nS;
		} while (!S[losowa]);
		cout << "Podaj polski odpowiednik slowa: " << S[losowa]->get_ang() << endl;
		cin >> tab;
		if (strcmp(S[losowa]->get_pol(), tab) == 0) cout << "Brawo! Swietna robota!" << endl;
		else cout << " Do roboty debilu!" << endl;
	}


void slownik::wypisz(ostream& out, int i) const
	{
		// UZUPE£NIJ
		// ZASTOSUJ rekurencjê do wypisania uporz¹dkowanej tablicy
		// wypisane elementy ponumeruj
		if (!S[i])
		{
			out << "#######\nPOLE PUSTE\n#######\n" << endl;
		}
		else {
			out << "Element #" << i + 1 << endl;
			out << *S[i] << endl;	
		}
		if (i + 1 == nS) return;
		wypisz(out, i + 1);
	}
ostream& operator<<(ostream& out,const slownik& S)
	{
		// GOTOWE! nic nie zmieniamy

		if (S.nS>0) S.wypisz(out, 0);	//0-indeks pierwszego elementu tablicy
		return out;
	}

