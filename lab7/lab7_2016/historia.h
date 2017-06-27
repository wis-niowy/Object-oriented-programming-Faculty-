#pragma once
#include "obraz.h"


class historia
{
	static const int N=4;	//maksymalna iloœæ przechowywanych obrazków
	obraz P[N];				//tablica przechowywanych obrazków
		
	int ile;				// 1<=ile<=N
							// zawsze w historii pozostaje co najmniej 1 obrazek
		
public:
	
	historia(const obraz& _P);	//od razu na pocz¹tku do historii wpisujemy bie¿¹cy obrazek

	void zapisz(const obraz& _P);		//wstawiamy bie¿¹cy obrazek na pierwsze wolne miejsce 
										//gdy tablica jest pe³na, to robimy miejsce na dopisanie na koniec

							
	obraz undo();		//jeœli P przechowuje wiêcej ni¿ 1 obrazek, to zwraca przedostatni obrazek listy
						//zawsze w historii pozostaje co najmniej 1 obrazek
	~historia();
};
