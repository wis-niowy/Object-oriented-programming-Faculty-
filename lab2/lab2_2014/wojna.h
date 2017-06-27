
#include "karta.h"
//-------------------------------------------------------
const int N=52;					// maksymalna ilość kart
const int ILE_W_KOLORZE=13;		// ilość kart w kolorze
//-------------------------------------------------------
class wojna {
	karta t[N];
	int start;		//pozycja pierwszej karty
	int koniec;
	int ile;		//liczba kart
	
public:
	wojna(){ile=0;start=0;koniec=0;}

	// generuje nową talię kart: kiery, kara, trefle i piki
	void nowa_talia();

	// wypisuje karty tablicy g; parametr opis jest dodatkowo wypisywany przed tablicą
	void wypisz(const char* opis="") const;

	// tasujemy karty; operacja wykonywana tylko dla nowej talii
	void potasuj();

	// kartę kładziemy na górę (na koniec)
	void dodaj_na_gore(const karta& k);

	// a zdejmujemy z dołu (z pozycji start)
	karta zdejmij_z_dolu();
		
	bool pusty() const {return ile==0;};

	// wartość punktowa kart w tablicy t
	int punkty() const;

};
