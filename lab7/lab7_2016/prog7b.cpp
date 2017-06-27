			
#include <iostream>
using namespace std;
#include "dane.h"

#include "historia.h"
#include "obraz.h"

//-------------------------------------------------------------
dane D[]={
	{2, 0},
	{18, 32}, {1, 64}, {7, 36}, {1, 0}, {18, 32}, {1, 64}, {5, 36}, {1, 0}, 
	{18, 32}, {1, 64}, {10, 36}, {1, 0}, {18, 32}, {1, 64}, {5, 36}, {1, 0}, 
	{18, 32}, {1, 64}, {7, 36}, {1, 0}, {18, 32}, {1, 64}, {1, 0},
	{18, 32}, {1, 64}, {1, 0}, {18, 32}, {1, 64}, {1, 0}, {17, 32}, {1, 120}, {1, 64}, {1, 0},
	{16, 32}, {1, 120}, {1, 32}, {1, 64}, {1, 0}, {16, 32}, {1, 120}, {1, 32}, {1, 64}, {1, 88}, {1, 0},
	{15, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {1, 88}, {1, 0},
	{15, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {2, 88}, {1, 0},
	{14, 32}, {3, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {1, 0},
	{13, 32}, {4, 120}, {1, 32}, {1, 64}, {1, 32}, {4, 88}, {1, 0},
	{13, 32}, {4, 120}, {1, 32}, {1, 64}, {1, 32}, {5, 88}, {1, 0},
	{12, 32}, {5, 120}, {1, 32}, {1, 64}, {1, 32}, {6, 88}, {1, 0},
	{11, 32}, {6, 120}, {1, 32}, {1, 64}, {1, 32}, {7, 88}, {1, 0},
	{10, 32}, {4, 120}, {1, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {2, 32}, {3, 88}, {1, 0},
	{9, 32}, {4, 120}, {2, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {3, 32}, {4, 88}, {1, 0},
	{9, 32}, {4, 120}, {2, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {3, 32}, {5, 88}, {1, 0},
	{8, 32}, {3, 120}, {2, 32}, {1, 120}, {1, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {2, 32}, {1, 88}, {1, 32}, {5, 88}, {1, 0},
	{7, 32}, {10, 120}, {1, 32}, {1, 64}, {1, 32}, {4, 88}, {4, 32}, {6, 88}, {1, 0},
	{6, 32}, {11, 120}, {1, 32}, {1, 64}, {1, 32}, {15, 88}, {1, 0},
	{5, 32}, {12, 120}, {1, 32}, {1, 64}, {1, 32}, {5, 88}, {7, 32}, {4, 88}, {1, 0},
	{4, 32}, {13, 120}, {1, 32}, {1, 64}, {1, 32}, {3, 88}, {12, 32}, {2, 88}, {1, 0},
	{3, 32}, {2, 120}, {10, 32}, {2, 120}, {1, 32}, {1, 64}, {1, 32}, {1, 88}, {16, 32}, {1, 88}, {1, 0},
	{2, 32}, {1, 120}, {13, 32}, {1, 120}, {1, 32}, {1, 64}, {1, 88}, {1, 0},
	{17, 32}, {1, 120}, {1, 64}, {1, 0}, {18, 32}, {1, 64}, {15, 32}, {2, 42}, {1, 0},
	{5, 42}, {13, 32}, {1, 64}, {13, 32}, {5, 42}, {1, 0}, {1, 32}, {35, 42}, {1, 0},
	{2, 32}, {33, 42}, {1, 0}, {5, 32}, {27, 42}, {2, 0} };

const int ND=sizeof(D)/sizeof(dane);

const int M=38;	//rozmiar obrazka
//-------------------------------------------------------------
int main()
{
	obraz p( M, ND, D);

	obraz p2(p), p3;	
	cout<<p2<<endl;		//sprawdzenie konstruktora kopiuj¹cego

	p3=p2;
	cout<<p3<<endl;		//sprawdzenie operatora przypisania

	historia	h(p);

	int	K;
	int k=-1;
	
	do  {
				cout<<p;	//zobaczmy obrazek

                cout<<"\nMENU:"<<endl;
                cout<<"1 - KOLOROWANIE"<<endl;
                cout<<"2 - SKALOWANIE"<<endl;
                cout<<"3 - UNDO"<<endl;
                cout<<"0 - KONIEC"<<endl;
                cout<<"Podaj numer opcji:"<<endl;
                
				cin>>K;
                switch (K)
                {
					case 1:	//KOLOROWANIE
						{

							char znak[3];
							int kolor;

							cout<<"Podaj znak do kolorowania: ";
							cin>>znak;
							
							do{
								cout<<"i podaj kolor dla wybranego znaku (0<=kolor<=15): "<<endl;
								cout<<"\t  15/0  -bialy/czarny"<<endl;
								cout<<"\t   7/8  -jasny/ciemny szary"<<endl;
								cout<<"\t   9/1  -jasny/ciemny niebieski"<<endl;
								cout<<"\t  10/2  -jasny/ciemny zielony"<<endl;
								cout<<"\t  11/3  -trukusowy/morski"<<endl;
								cout<<"\t  12/4  -jasny/ciemny czerwony"<<endl;
								cout<<"\t  13/5  -jasny/ciemny fioletowy"<<endl;
								cout<<"\t  14/6  -jasny/ciemny zolty"<<endl;
								cin>>kolor;
							}	while (kolor<0 || kolor>15);

							p.dodaj_kolor(znak, kolor);	//ustawienie dla znaku kolor w palecie
							
							h.zapisz(p);
							
						}
						break;

                    case 2:	//SKALOWANIE
						
						p.skaluj(k);
						k*=-1;
						
						h.zapisz(p);
						break;
                   
                    case 3:	//UNDO
						p=h.undo();

						if (p.wymiar()==M) k=-1;	//powiêkszamy
						else
							k=1;

						break;

                }//switch

                
            } while (K != 0);
			
	return 0;
}
			