#include <iostream>
using namespace std;
const int Max_M = 10;
const int Max_N = 10;

class obraz
{
		const int N; // liczba wierszy
		const int M; // liczba kolumn
		const int Q; // liczba odcieni szarosci
		int pixelVal[Max_N * Max_M]; // tablica pikseli

	public:
		// sk≥adowe i funkcje zaprzyjaünione
		friend ostream& operator<<(ostream& out, const obraz& im);
		friend void operator>>=(obraz& im, int i);
		obraz& operator=(const int* );
		void getObrazInfo (int&, int&, int&) const;
		obraz(int =0, int =0, int =0, int* = nullptr);
		obraz(const obraz&); // konstruktor kopiujacy
		int& operator()(const int x, const int y);
		int operator()(const int x, const int y) const;
		void negacjaObrazu();
		int* odbiciePionoweObrazu();
};

