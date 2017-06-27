#include <iomanip>
#include <time.h>
#include "slownik.h"

const int M=20;

//----------------------------------------------------------------
int main()
{
	cout<<"----------  ETAP 1. ---------------------"<<endl<<endl;
	
	{
		slowo A("digit","cyfra"), B("addition","dodawanie");
		cout<<"slowo A:"<<A<<endl<<"slowo B:"<<B<<endl;
		
		slowo C(A);
		cout<<"slowo C:"<<C<<endl;
		
		cout<<"A<B: "<<(A<B)<<endl;
		cout<<"B<A: "<<(B<A)<<endl;
		cout<<"A==C: "<<(A==C)<<endl<<endl;
		cout<<"A==B: "<<(A==B)<<endl<<endl;
	}
	
	cout<<"----------  ETAP 2. ---------------------"<<endl<<endl;

	slowo slowka_dnia[M]={
							
				 slowo("limit","granica"), slowo("addition","dodawanie"), slowo("sequence","ciag"),
				 slowo("convex","wypukly"), slowo("digit","cyfra"),	 slowo("integral","calka"),
				 slowo("singular","osobliwa"), slowo("unit","jednosc"), slowo("axiom","aksjomat"),
				 slowo("multiplicity","krotnosc"), slowo("curve","krzywa"), slowo("numeral","liczba"),
				 slowo("number","liczba"), slowo("multiply","mnozyc"), slowo("unit","jednostka"),	
				 slowo("infinity","nieskonczonosc"), slowo("enumeration","numeracja"),
				 slowo("ascending","rosnacy"), slowo("tangent","styczna"), slowo("triangle","trojkat")
	};
	
	slownik S(M,slowka_dnia);
	
	int K;

			do{
				cout<<"SLOWNIK (posortowany wg pola: 'ang' oraz 'pol'):"<<endl;
				cout<<S;

				cout<<"\nMENU:";
                cout<<"\n1 - DOPISZ slowo do slownika";
              	cout<<"\n2 - TEST";
				cout<<"\n0 - KONIEC";
                cout<<"\n*** Podaj numer opcji:  ";
                
				cin>>K;
                switch (K)
                {
					case 1:	//DOPISZ slowo do slownika
						
						char ang[100], pol[100];

						cout<<"DOPISYWANIE"<<endl;
						cout<<"Podaj slowo ANGIELSKIE: ";
						cin>>ang;
						
						cout<<"Podaj ODPOWIEDNIK POLSKI dla slowa angielskiego: ";
						cin>>pol;
						
						S.wstaw(slowo(ang,pol));
						
						break;

                    case 2:	//TEST
						
						cout<<"TEST"<<endl;
						S.test();
						system("PAUSE");
						break;
						
                }//switch


	}while (K!=0);
	
	
	cout<<endl<<"----------  KONIEC  ---------------------"<<endl<<endl;
	system("PAUSE");
}	

