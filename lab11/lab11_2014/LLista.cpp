#include "LLista.h"

CLista::CLista() 
{
	glowa = nullptr;
	ogon = nullptr;
}

CLista::~CLista()
{
	if ( !czyPusta() ) 
   {    
      ListaWezel *bierzacy = glowa;
      ListaWezel *temp;

	  while ( bierzacy != ogon ) 
      {  
         temp = bierzacy;
         bierzacy = bierzacy->nastepny;
         delete temp;
      }
	  delete bierzacy;
   }
}

bool CLista::czyPusta() const
{
	if(glowa == nullptr && ogon == nullptr) 
		return 1;
	else
		return 0;
}
 
void CLista::wstawPoczatek(int _dane)
{
	if(czyPusta()) 
	{
		ListaWezel *nowy_wezel = new ListaWezel(_dane); 
		glowa = nowy_wezel; 
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
	else 
	{
		ListaWezel *nowy_wezel = new ListaWezel(_dane);
		nowy_wezel->nastepny = glowa; 
		glowa = nowy_wezel; 
		ogon->nastepny = glowa;
	}
}

void CLista::wstawKoniec(int _dane)
{
	if(czyPusta()) 
	{
		ListaWezel *nowy_wezel = new ListaWezel(_dane);
		glowa = nowy_wezel;
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
	else 
	{
		ListaWezel *nowy_wezel = new ListaWezel(_dane);
		ogon->nastepny = nowy_wezel; 
		ogon = nowy_wezel;
		ogon->nastepny = glowa;
	}
}

void CLista::wstawPosortowane(int _dane) 
{
	if(czyPusta()) 
	{
		wstawPoczatek(_dane);
	}
	else 
	{
		if(_dane < glowa->dane) 
		{
			wstawPoczatek(_dane);
		}
		else if(_dane >= ogon->dane) 
		{
			wstawKoniec(_dane);
		}
		else 
		{
			ListaWezel * bierzacy = glowa;
			ListaWezel *nowy_wezel = new ListaWezel(_dane); 
			while(bierzacy != ogon) 
			{
				if( (nowy_wezel->dane < bierzacy->nastepny->dane) && (nowy_wezel->dane >= bierzacy->dane)) 
				{
					ListaWezel *next_node = bierzacy->nastepny; 
					bierzacy->nastepny = nowy_wezel; 
					nowy_wezel->nastepny = next_node; 
					break;
				}
				bierzacy = bierzacy->nastepny; 
			}
		}
	}
}

void CLista::drukuj()
{
	if(czyPusta())
	{
		cout << "Lista jest pusta" << endl;
	
	}
	else
	{
		ListaWezel *bierzacy = glowa;

		cout << "Zawartosc listy: ";
		while(bierzacy != ogon)
		{
			cout << bierzacy->dane << ' ';
			bierzacy = bierzacy->nastepny; 
		}
		cout << bierzacy->dane << endl;
	}
}