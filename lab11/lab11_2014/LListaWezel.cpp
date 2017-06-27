#include "LListaWezel.h"

ListaWezel::ListaWezel(int _dane)
{
	dane = _dane; 
	nastepny = nullptr; 
}

int ListaWezel::pobierzDane() 
{
	return dane;
}