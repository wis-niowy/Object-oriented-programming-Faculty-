#include <iostream>
using namespace std;

// zaimplementuj szablon wielomianow dla ogólnego typu T
// domyœlnym typem jest double
template <class T = double>
class wielomian
{
    T* w;
	int st;

public:
	wielomian<T>(int _st, T* _w = 0): st(_st)
    {
		if (_w)
		{
			w = new T[st + 1];
			for (int i = 0; i < st + 1; i++)
			{
				w[i] = _w ? _w[i] : 0; // ???????
			}
		}
    }

	~wielomian()
	{ 
		//delete[] w;
	}

	wielomian<T>(const wielomian<T>& p)
    {
		*this = wielomian<T>(p.st, p.w);
    }
	            
    T operator()(T x) const //wartoœæ wielomianu dla x
    {
		T wynik = w[st];
		for (int i = st - 1; i >= 0; i--)
		{
			wynik = wynik * x + w[i];
		}
		return wynik;
    }

	T operator()(T x, int ) const	//wartoœæ pochodnej dla x
	{
		return this->Pochodna()(x); // operator () dla wielomianu Pochodna
	}

    wielomian<T> Pochodna() const // wielomian reprezentuj¹cy pochodn¹
    {
		/*wielomian<T> do_zwrotu(st - 1);
		do_zwrotu.w = new T[st];
		for (int i = st - 1; i >= 0; i--)
		{
			do_zwrotu.w[i] = T(i + 1) * this->w[i + 1];
		}
		return do_zwrotu;*/
		T *wartosci = new T[st];
		for (int i = st - 1; i >= 0; i--)
			wartosci[i] = w[i + 1] * T(i + 1);

		return wielomian(st - 1, wartosci);
    }

    friend ostream& operator<<(ostream& out, const wielomian& p)
	{
		out << p.w[0] << " + " << p.w[1] << "x";; // w czym problem ???
		for (int i = 2; i < p.st + 1; i++)
		{
			out << " + " << p.w[i] << "x^" << i;
		}
		out << endl;
		return out;
	}
	
};
