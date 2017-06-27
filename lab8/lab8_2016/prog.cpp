#include <iostream>
using namespace std;
#include "produkt.h"
#include "owoc.h"
const int N=10;

//---------------------------------------------
void sortuj( int* tab,  int n)	//przyk³adowe sortowanie, np b¹belkowe
{
	for( int i=0; i<n; i++ ) 
        for( int j=0; j<n-1; j++ )
			if( tab[j]>tab[j+1] ) 
				swap( tab[ j ], tab[ j + 1 ] );
}
//---------------------------------------------
bool porownaj_nazwa(const produkt* os1, const produkt* os2)
{
	if (os1->getnazwa() > os2->getnazwa()) return true;
	else return false;
}

bool porownaj_kraj_nazwa(const produkt* os1, const produkt* os2)
{
	if (os1->getkraj() > os2->getkraj())
		return true;
	else if (os1->getkraj() == os2->getkraj())
	{
		if (porownaj_nazwa(os1, os2))
			return true;
	}
	else return false;
			
}

void sortuj(produkt **produkty, const int ile, bool (*kryterium)(const produkt*, const produkt*))
{
	for (int i = 0; i < ile - 1; i++)
		for (int j = 0; j < ile - i - 1 ; j++)
			if (kryterium(produkty[j], produkty[j + 1]))
				swap(produkty[j], produkty[j + 1]);
}

//-------------------------------------------

owoc* najdrozszy(produkt** produkty, const int ile)
{
	double srednia_zwrot = 0;
	owoc* do_zwrocenia = dynamic_cast<owoc*>(produkty[0]);
	for (int i = 0; i < ile; i++)
	{
		if (do_zwrocenia = dynamic_cast<owoc*>(produkty[i]))
			if (do_zwrocenia->srednia_cena() > srednia_zwrot)
				srednia_zwrot = do_zwrocenia->srednia_cena();
	}
	if (srednia_zwrot == 0) return nullptr;

	return do_zwrocenia;

}

//-------------------------------------------
void main()
{
	cout<<"ETAP 1 - test klasy produkt"<<endl<<endl;
	{
		produkt pr1("cos","Brazylia"), pr2(pr1), pr3;

		pr3=pr2;

		cout<<"PRODUKTY:"<<endl;
		cout<<"pr1: "<<pr1<<endl<<"pr2: "<<pr2<<endl<<"pr3: "<<pr3<<endl;
	}
	cout<<"koniec ETAPu 1"<<endl<<endl<<endl;
	//--------------------------------------------------------------
	
	cout<<"ETAP 2 - test klasy owoc"<<endl<<endl;
	{
		owoc ow1("gruszka","Polska","5/3.5/4.5/3.5/4/2"), ow2(ow1), ow3("malina","Niemcy","2/5/5/4/5/3.5/4/2");

		ow3=ow2;

		cout<<"OWOCE:"<<endl;
		cout<<"ow1: "<<ow1<<endl<<"ow2: "<<ow2<<endl<<"ow3: "<<ow3<<endl;
	}
	cout<<"koniec ETAPu 2"<<endl<<endl<<endl;
	
	
	//--------------------------------------------------------------
	
	cout<<endl<<"ETAP 3"<<endl<<endl;

	produkt* produkty[N]={
			 new owoc("ananas","Brazylia","5/5/5/4.5/5/4/3/5"),
			 new owoc("gruszka","Niemcy","3.5/4/2"),
			 new produkt("figa","Argentyna"),
			 new owoc("mango","Hiszpania","5/3.5/4.5/3.5/4/2"),
			 new owoc("porzeczka","Czechy"),
			 new produkt("agrest","Polska"),
			 new owoc("malina","Polska","2/5/5/4/5/3.5/4/2"),
			 new produkt("mandarynka","Francja"),
			 new owoc("banan","Kuba","3.5/4/5/2/2/2.5"),
			 new owoc("truskawka","Polska","3/8/6/4/7.5")
	};

	cout<<endl<<"PRODUKTY:";
	for (int i=0;i<N;i++) cout<<*produkty[i];
	
	
	//---------------------------------------------------------------
	cout<<endl<<"ETAP 4 - sortowanie"<<endl<<endl;

	cout<<endl<<endl<<"PRODUKTY posortowane wg nazwy:";
	sortuj(produkty,N,porownaj_nazwa);
	for (int i=0;i<N;i++) cout<<*produkty[i];


	cout<<endl<<endl<<"PRODUKTY posortowane wg kraju, nazwy:";
	sortuj(produkty,N,porownaj_kraj_nazwa);
	for (int i=0;i<N;i++) cout<<*produkty[i];
	
	
	//---------------------------------------------------------------
	cout<<endl<<"ETAP 5 - Najdrozszy owoc"<<endl<<endl;

	owoc* s=najdrozszy(produkty,N);
	if (!s)
		cout<<endl<<"Brak owocu w grupie produktow..."<<endl;
	else
		cout<<endl<<"Maksymalna srednia cena owocu:"<<s->srednia_cena()<<endl;
	
	
	cout<<endl;
	

	
	//-------------------------------------------------------------
	cout<<endl<<"USUWAM PRODUKTY"<<endl;
	for (int i=0;i<N;i++) delete produkty[i];
	
	system("PAUSE");
}