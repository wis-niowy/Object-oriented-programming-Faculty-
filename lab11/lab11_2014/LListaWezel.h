#ifndef LLISTA_WEZEL_H
#define LLISTA_WEZEL_H
 
class CLista;

class ListaWezel 
{
	friend class CLista;

public:
	ListaWezel(int);
	int pobierzDane();

private:
	int dane; 
	ListaWezel* nastepny; 
};

#endif