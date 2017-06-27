#include <algorithm>
#include <list>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;


//bool greater75(int n) { return n>75; }


vector<int> spirala(int L, vector<int> U)
{
	unsigned wymiar = sqrt(L);
	unsigned ilosc_liczb = wymiar * wymiar;
	unsigned stp = 1, n = 1, posX = wymiar >> 1, posY = posX, stC = 0;
	int dx = 1, dy = 0, s = 0;
	vector<int> spirala_Ulama(ilosc_liczb);

	while (posX < wymiar && posY < wymiar) {
		spirala_Ulama.at(posX + posY * wymiar) = U[s];
		s++;

		if (dx) {
			posX += dx;
			if (++stC == stp) {
				dy = -dx;
				dx = stC = 0;
			}
		}
		else {
			posY += dy;
			if (++stC == stp) {
				dx = dy;
				dy = stC = 0;
				stp++;
			}
		}
	}
	return spirala_Ulama;
}


//Etap 1
//Funkcja wyœwietlaj¹ca kontener
template <class T>
void wypisz_kontener(T kont, char* text1, char* text2)
{
	cout << text1;
	for_each(kont.begin(), kont.end(), [&text2](auto& el) {
		cout << el << text2;
	});
	cout << endl;
}

//Etap 2
//Funktor sprawdzaj¹cy czy liczba jest pierwsza, mo¿na u¿yæ pêtli
class czyPierwsza
{
public:
	int operator()(int do_sprawdzenia)
	{
		int dlugosc = sqrt(do_sprawdzenia);
		dlugosc--;
		for (int i = 0; i < dlugosc; ++i)
		{
			if (do_sprawdzenia % (i + 2) == 0) return 0; // nie jest pierwsza
		}
		return 1;
	}
};

//Funkcja wyœwietlaj¹ca spiralê
void wyswietlSpirale(char c, unsigned wymiar, vector<int> U)
{
	unsigned licznik = 0;
	for_each(U.begin(), U.end(), [c, wymiar, &licznik](auto& el) {
		if (el == 1) cout << c;
		else cout << " ";
		++licznik;
		if (licznik % wymiar == 0) cout << endl;
	});
}

//Etap 3
//Funkcja sprawdza, czy liczba nie jest pierwsza


//Funkcje obliczaj¹ce sumê oraz iloczyn kolejnych wyra¿eñ
class liczSzereg
{
public:
	double operator()(double a, double b)
	{
		return a + (1 / pow(b, 2));
	}
};
class liczIloczyn
{
public:
	double operator()(double a, double b)
	{
		return a * (pow(b,2) / (pow(b,2) - 1));
	}
};

//Etap 4
//Funkcja kopiuj¹ca elementy zaczynaj¹c od spe³niaj¹cego predykat, 
//mo¿na u¿yæ pêtli, ale nie do kopiowania


//Liczby losowe z zakresu 1-100


void main()
{
	srand(100);
	const int N = 100;


	cout << "___________ETAP 1___________1p" << endl << endl;
	//Przygotuj kontener (lista) wype³niony liczbami ca³kowitymi od 1 do N, bez pêtli
	list<int> liczby(N, 1);
	partial_sum(liczby.begin(), liczby.end(), liczby.begin());
	//Wypisz kontener - metoda generyczna
	wypisz_kontener(liczby, "Lista:", ",");

	//Skopiuj kontener z liczbami do wektora, wypisz
	//bêdzie potrzebny dalej
	vector<int> liczby123(N);
	copy(liczby.begin(), liczby.end(), liczby123.begin());
	wypisz_kontener(liczby123, "Vector:", ",");

	cout << endl << "___________ETAP 2___________2p" << endl << endl;
	//Spirala Ulama
	//W wektorze z liczbami szukamy liczb pierwszych
	//Liczby pierwsze zamieniamy na 1, pozosta³e - 0
	//Wypisujemy
	transform(liczby123.begin(), liczby123.end(), liczby123.begin(), czyPierwsza());
	wypisz_kontener(liczby123, "Pozycja liczb pierwszych:", " ");

	//Utworzenie kontenera ze spiral¹ i wyœwietlenie go
	vector<int> spirala_Ulama = spirala(N, liczby123);
	wypisz_kontener(spirala_Ulama, "Spirala Ulama:", " ");

	//Wyœwietlenie spirali
	cout << endl << endl << "Spirala Ulama" << endl;
	wyswietlSpirale('*', sqrt(N), spirala_Ulama);


	cout << "___________ETAP 3___________3p" << endl << endl;
	//Hipoteza Riemana... czas j¹ udowodniæ ;)
	//Utwórz listê zawieraj¹c¹ liczby pierwsze z zakresu 1-N
	vector<int> pierwsze(liczby.begin(), liczby.end());
	vector<int>::iterator koniec = remove_if(pierwsze.begin(), pierwsze.end(), [](auto& el) {
		if (czyPierwsza()(el) == 1) return 0; // zostaw
		else if (czyPierwsza()(el) == 0) return 1; // usun, bo nie pierwsza
	});
	pierwsze.erase(koniec, pierwsze.end()); // usun smieci z konca wektora (remove_if nie zmienia rozmiaru wektora)
	//Oblicz sumê nieskoñczonych ci¹gów
	double suma = accumulate(liczby.begin(), liczby.end(), 0.0, liczSzereg());
	double iloczyn = accumulate(pierwsze.begin() + 1, pierwsze.end(), 1.0, liczIloczyn());

	wypisz_kontener(pierwsze, "liczby pierwsze:", ",");
	cout << endl;

	cout << "Dzeta Riemana" << endl << endl;
	cout << "         Suma(1/x^2) = ";
	cout << suma << endl;
	cout << "Iloczyn(p^2/(p^2-1)) = ";
	cout << iloczyn << endl;
	const double PI = atan(1.0) * 4;
	cout << "              PI^2/6 = " << PI*PI / 6 << endl << endl;


/*	cout << "___________ETAP 4___________2p" << endl << endl;
	//Utwórz w³asn¹ funkcjê kopiuj¹c¹
	//Przetestuj j¹ na wektorze 100 elementowym o losowych wartoœciach z przedzia³u 1-100
	//i posortuj malej¹co

	wypisz_kontener(los, "liczby losowe:", ",");

	wypisz_kontener(los, "liczby skopiowane:", ",");

	wypisz_kontener(los, "liczby posortowane:", ",");
*/

	cout << endl;
	system("pause");
}
