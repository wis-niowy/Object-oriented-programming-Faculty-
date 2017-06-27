
#ifndef _KOLEJKA_H_
#define _KOLEJKA_H_

#include <iostream>

using namespace std;

class KolejkaPrior
    {
    private:

    class Elem
        {
        public:
        Elem(int w, Elem* n=NULL);
        ~Elem();
        int wart;
        Elem *nast;
        };

    Elem *glowa;

    public:

    KolejkaPrior();
    KolejkaPrior(const KolejkaPrior& k); // elementy tworzonej kolejki musza byc uporzadkowane od najmniejszego do najwiekszego
   // ~KolejkaPrior();
    KolejkaPrior& operator=(const KolejkaPrior& k); // elementy kolejki musza byc uporzadkowane od najmniejszego do najwiekszego
    void Wstaw(int w); // wstawia w takim miejscu aby elementy kolejki byly uporzadkowane od najmniejszego do najwiekszego
    int Pobierz(); // pobiera (i usuwa) najmniejszy element z kolejki (czyli zawsze pierwszy), jesli kolejka jest pusta zwraca 0 (oczywiscie nic nie usuwa)
	bool CzyPusta() const { return !glowa; };
    friend ostream& operator<<(ostream& os, const KolejkaPrior& k);
	friend void sortuj(const KolejkaPrior&, KolejkaPrior&);
    };

#endif   // _KOLEJKA_H_
