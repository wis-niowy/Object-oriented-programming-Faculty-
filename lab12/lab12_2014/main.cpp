#include <iostream>
#include <fstream>
#include "Slowo.h"
#include "fun.h"

using namespace std;

int main(){

	////Etap 1. (1p)
	Slowo s1("Jan","John", 1);
	Slowo s2;
	//cin>>s2;
	//if(s1==s2) cout<<s1<<" to to samo co "<<s2<<endl;
	//else cout<<s1<< " i "<<s2<<" to dwa rozne slowa"<<endl;

	//Etap 2 (1p)
	fstream f;
	if (!otworz(f)) { cout << "Nie otworzono pliku!" << endl; system("PAUSE"); return 1; }
	
	char tmp[256];
	char K,szuk;
	int idx=0;
	do{
		cout<<"\nMENU:";
		cout<<"\n1 - DOPISZ dane do bazy";
		cout<<"\n2 - WYPIS";
		cout<<"\n3 - MOD";
		cout<<"\n4 - SZUKAJ";
		cout<<"\n2 - TEST";
		cout<<"\n0 - KONIEC";
		cout<<"\n*** Podaj numer opcji:  ";
				
		cin>>K;
		switch (K)
		{ 
			case '1':	// Etap 3a) 1p DOPISZ dane do bazy
						
				cin>>s1;
				if(!dopisz(f,s1)) cout<<"Nie moge dopisac "<<s1<<endl;
				break;

			case '2':	//Etap 3b) 1p WYPIS
				if(!wypisz(f)) cout<<"Nie udalo sie wypisac bazy"<<endl;;
				break;
			case '3':   //Etap 4 - 2p MODYFIKUJ
				idx=0;
				cout << "Podaj numer modyfikowanego elementu: ";
				cin >> idx;
				if(!modyfikuj(f,idx)) cout<<"Modyfikacja nie powiodla sie"<<endl;;
				break;
	//		case '4':    //5 - 2p SZUKAJ
	//			cout<<"Podaj dane osoby poszukiwanej :"<<endl;
	//			cin>>s1;
	//			if (!szukaj(f,s1))
	//				cout<<"Brak danych"<<endl;
	//			break;
	//			
			default:
				break;
		}//switch


	}while (K!='0');
	
	cout<<endl<<"----------  KONIEC  ---------------------"<<endl<<endl;
	
	system("PAUSE");
	return 0;
}
