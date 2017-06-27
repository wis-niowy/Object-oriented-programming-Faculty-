#include "Kurierzy.h"

using namespace std;

int main()
{
	// ETAP 1 - nalezy ustawic #define TEST_01 na true w pliku Kurierzy.h
	// analogicznie dla pozostalych etapow
#if TEST_01 == 1
	const int t01Size = 20;
	Kurier k01[t01Size];
	Paczka p01[t01Size];
	for (int i = 0; i < t01Size; ++i) {
		p01[i] = Paczka::przygotujPaczke();
		for (int j = 0; j < i; ++j) {
			if (k01[i].getId() == k01[j].getId()) {
				cout << "Id kurierow powinno byc unikalne!" << endl;
				exit(1);
			}
			if (p01[i].getId() == p01[j].getId()) {
				cout << "Id paczek powinno byc unikalne!" << endl;
				exit(1);
			}
		}
	}
	cout << "ETAP 1 - OK" << endl;
#endif

#if TEST_02 == 1
	Sortownia s02;
	bool przyjeta = MAX_PACZEK_W_SORTOWNI > 0;
	for (int i = 0; i < MAX_PACZEK_W_SORTOWNI; ++i) {
		przyjeta &= s02.przyjmijPaczke(p01[i]);
	}
	if (!przyjeta) {
		cout << MAX_PACZEK_W_SORTOWNI << " paczek powinno zostac przyjetych w sortowni!" << endl;
		exit(2);
	}
	if (s02.przyjmijPaczke(p01[MAX_PACZEK_W_SORTOWNI])) {
		cout << "Paczka przekraczajaca pojemnosc sortowni powinna zostac odrzucona!" << endl;
		exit(2);
	}
	cout << "ETAP 2 - OK" << endl;
#endif

#if TEST_03 == 1
	FirmaKurierska f1;
	if (f1.odbierzPaczke(Paczka())) {
		cout << "Przyjeto niepoprawna paczke!" << endl;
		exit(3);
	}
	int i = 0;
	for (; i < MAX_PACZEK_W_SORTOWNI; ++i) {
		if (!f1.odbierzPaczke(Paczka::przygotujPaczke())) {
			break;
		}
	}
	if (i != MAX_PACZEK_W_SORTOWNI) {
		cout << "Przyjeto zbyt malo paczek!" << endl;
		exit(3);
	}
	if (f1.odbierzPaczke(Paczka::przygotujPaczke())) {
		cout << "Limit paczek osi¹gniety" << endl;
		exit(3);
	}
	f1.rozpocznijDzien(); // firma rozdaje paczki kurierom do doreczenia

	f1.print();
	int wynik = f1.zamknijDzien();
	int min = MAX_PACZEK_U_KURIERA * FirmaKurierska::ILOSC_KURIEROW;
	if (min > MAX_PACZEK_W_SORTOWNI) {
		min = MAX_PACZEK_W_SORTOWNI;
	}
	if (wynik != min) {
		cout << "Niepoprawna ilosc doreczonych paczek! (" << wynik << ")" << endl;
		exit(3);
	}
	if (f1.zamknijDzien()) {
		cout << "Na koniec dnia, wszystkie paczki powinny zostac oznaczone jako doreczone!" << endl;
		exit(3);
	}
	FirmaKurierska f2;
	while (f2.odbierzPaczke(Paczka::przygotujPaczke()));
	f2.rozpocznijDzien();
	int mod = MAX_PACZEK_W_SORTOWNI % FirmaKurierska::ILOSC_KURIEROW;
	int c = (int)(MAX_PACZEK_W_SORTOWNI / FirmaKurierska::ILOSC_KURIEROW);
	for (int i = 0; i < FirmaKurierska::ILOSC_KURIEROW; ++i) {
		int target = c + (mod > i ? 1 : 0);
		if (f2.kurierzy[i].rozliczPaczki() != target) {
			cout << "Liczba paczek doreczonych przez kuriera nie zgadza sie! (" << target << ")" << endl;
			exit(3);
		}
	}
	cout << "ETAP 3 - OK" << endl;
#endif

#if TEST_04 == 1
	Kurier k04;
	bool error = false;
	if (!(k04 += Paczka::przygotujPaczke())) {
		cout << "operator += w klasie Kurier niepoprawny!" << endl;
		error = true;
	}
	Sortownia s04;
	if (!(s04 += Paczka::przygotujPaczke())) {
		cout << "operator += w klasie Sortownia niepoprawny!" << endl;
		error = true;
	}
	FirmaKurierska f04;
	if (!(f04 += Paczka::przygotujPaczke())) {
		cout << "operator += w klasie FirmaKurierska niepoprawny!" << endl;
		error = true;
	}
	if (error) {
		exit(4);
	}
	cout << "ETAP 4 - OK" << endl;
#endif
	system("PAUSE");
}
