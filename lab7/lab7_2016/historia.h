#pragma once
#include "obraz.h"


class historia
{
	static const int N=4;	//maksymalna ilo�� przechowywanych obrazk�w
	obraz P[N];				//tablica przechowywanych obrazk�w
		
	int ile;				// 1<=ile<=N
							// zawsze w historii pozostaje co najmniej 1 obrazek
		
public:
	
	historia(const obraz& _P);	//od razu na pocz�tku do historii wpisujemy bie��cy obrazek

	void zapisz(const obraz& _P);		//wstawiamy bie��cy obrazek na pierwsze wolne miejsce 
										//gdy tablica jest pe�na, to robimy miejsce na dopisanie na koniec

							
	obraz undo();		//je�li P przechowuje wi�cej ni� 1 obrazek, to zwraca przedostatni obrazek listy
						//zawsze w historii pozostaje co najmniej 1 obrazek
	~historia();
};
