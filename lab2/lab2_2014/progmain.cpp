#include <iostream>
using namespace std;

#include "wojna.h"
//----------------------------------------------------------------
const int ILE_ROZGRYWEK=10;	
//----------------------------------------------------------------
// TUTAJ zaimplementuj funkcjê starcie (wywo³ywana w f.main)
void starcie(wojna g1, wojna g2)
{
	wojna stosg1, stosg2;
	karta k1, k2;
	k1 = g1.zdejmij_z_dolu(); k2 = g2.zdejmij_z_dolu();

	while (!g1.pusty() && !g2.pusty())
	{
		if (k1 > k2) stosg1.dodaj_na_gore(k2);
		else if (k1 < k2) stosg2.dodaj_na_gore(k1);


	}
}

//----------------------------------------------------------------
int main()
{
	wojna w;
		
	//--------------------------------------------------
	w.nowa_talia();
	w.wypisz("TALIA KART:");
	
	//--------------------------------------------------
	w.potasuj();
	w.wypisz("Potasowana TALIA KART :");

	//--------------------------------------------------
	wojna gracz1,gracz2;
	
	while (!w.pusty())
	{
		gracz1.dodaj_na_gore(w.zdejmij_z_dolu());
		if (!w.pusty()) 
			gracz2.dodaj_na_gore(w.zdejmij_z_dolu());
	}

	gracz1.wypisz("GRACZ 1:");
	gracz2.wypisz("GRACZ 2:");
	
	////--------------------------------------------------
	//cout<<"WALKA:"<<endl;
	//for (int i=0; i<ILE_ROZGRYWEK && !gracz1.pusty() && !gracz2.pusty(); ++i)		
	//{
	//	starcie(gracz1,gracz2);
	//	gracz1.wypisz("GRACZ 1:");
	//	gracz2.wypisz("GRACZ 2:");
	//	//cin.get();
	//}
	//
	////--------------------------------------------------
	//cout<<"Punkty gracza 1 :"<<gracz1.punkty()<<endl<<"Punkty gracza 2 :"<<gracz2.punkty()<<endl;
	//	
	system("PAUSE");
}//----------------------------------------------------------------