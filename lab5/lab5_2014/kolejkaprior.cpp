
#include <iostream>
#include "kolejkaprior.h"

using namespace std;

KolejkaPrior::Elem::Elem(int w, Elem *n) : wart(w), nast(n)
    {
    cout << "Utworzono element: " << w << endl;
    }

KolejkaPrior::Elem::~Elem()
    {
    cout << "Zlikwodowano element: " << wart << endl;
    }

// Tu dopisz niezbedne implementacje
/////////////////////// 1 ETAP //////////////////////////
KolejkaPrior::KolejkaPrior()
{
	glowa = nullptr;
}
KolejkaPrior::KolejkaPrior(const KolejkaPrior& k)
{
	glowa = nullptr;
	
	if (k.CzyPusta()) return;
	Elem *skoczek = k.glowa;

	while (skoczek)
	{
		Wstaw(skoczek->wart);
		skoczek = skoczek->nast;
	}
}
KolejkaPrior& KolejkaPrior::operator=(const KolejkaPrior& k)
{
	/*if (glowa)
	{
		delete[] glowa;
	}*/

	
	KolejkaPrior::KolejkaPrior(k); // wywo³anie konstruktora zamiast kopiowania calosci kodu ..
	// (KolejkaPrior)(k); - ewentualnie wyzej 
	return *this;
}
void KolejkaPrior::Wstaw(int w) // wstawia sortujac!!!
{
	Elem *aktualny = glowa, *nastepny;
	if (CzyPusta())
	{
		glowa = new Elem(w, nullptr);
	}
	else if (aktualny->wart > w) // nowa glowa
	{
		glowa = new Elem(w, aktualny);
	}
	else
	{
		while (aktualny->nast && aktualny->nast->wart < w)
			aktualny = aktualny->nast;
		nastepny = aktualny->nast;
		aktualny->nast = new Elem(w, nastepny);

	}
}
ostream& operator<<(ostream& os, const KolejkaPrior& k)
{
	KolejkaPrior::Elem *skoczek = k.glowa;
	while (skoczek)
	{
		os << skoczek->wart << " ";
		skoczek = skoczek->nast;
	}
	os << endl;
	return os;
}
int KolejkaPrior::Pobierz()
{
	Elem *do_usuniecia;
	if (!glowa) return 0;
	int zwroc = glowa->wart;
	do_usuniecia = glowa;
	glowa = glowa->nast;
	delete do_usuniecia;
	return zwroc;
}