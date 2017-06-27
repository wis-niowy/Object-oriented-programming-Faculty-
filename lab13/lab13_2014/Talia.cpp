#include "Talia.h"
#include <ctime>
#include <string>
using namespace std;

Talia::Talia(const char** post) 
{
	for (int i = 0; i < 12; ++i)
	{
		karty.push_front(string(post[i]));
		karty.push_back(string(post[i]));
	}
	karty.push_back(string(post[12]));
}

Talia::Talia(const Talia& t)
{
	for (int i = 0; i < t.karty.size(); ++i)
	{
		karty.push_front(t.karty[i]);
	}
}

void Talia::potasuj()
{
	for (int i = 0; i < 25; ++i)
	{
		int indeks = -1;
		do {
			indeks = rand() % 25;
		} while (i == indeks);
		deque<string>::iterator ind1 = karty.begin() + i;
		deque<string>::iterator ind2 = karty.begin() + indeks;
		swap(*ind1, *ind2);
	}
	
}

ostream& operator<<(ostream& out, const Talia& t)
{
	for (int i = 0; i < t.karty.size(); ++i)
	out << t.karty[i] << " ";

	return out;
}