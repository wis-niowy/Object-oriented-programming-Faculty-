
#pragma once
#include <iostream>
using namespace std;


class wektor
{
	char*	t;		//dynamiczna kwadratowa wektor o wymiarze ( m*m)
	int		m;		//wymiar tablicy

protected:
	void    init(int _m, char* _t=nullptr);
						//TYLKO tutaj wolno u¿yæ operatora new
						//jeœli _t jest nullptr, to wyzeruj tablicê
	void	zwolnij();
						//TYLKO tutaj wolno u¿yæ operatora delete
public:
	wektor(int m=0);
	wektor(const wektor& P);
	~wektor();

	wektor& operator=(const wektor& P);
	
	int wymiar()  const { return m; }
	char& operator()(int i,int j){return t[i*m+j];}
	char operator()(int i,int j) const {return t[i*m+j];}

};
