#include <iostream>
#include "obraz.h"
using namespace std;
const int MAX = 256; 

class hist
{
		bool wykonano;
		obraz hist_im;		 // obraz
		int hist_tab[MAX];	 // tablica histogramu

	public:

		hist( const obraz& im); 
 
		bool czy_wykonano_hist();
		
		void wykonaj_hist();

		obraz wyrownaj_hist();

		friend ostream& operator<<(ostream&, const hist& h);
};