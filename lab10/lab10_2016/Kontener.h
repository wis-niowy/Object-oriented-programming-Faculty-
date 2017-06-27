#pragma once
#include "KontenerException.h"
#include "Etapy.h"
#include <iostream>
using namespace std;

template<class T, static const int FIRST_CHUNK_SIZE = 5>
class Kontener
{
	static const int FIRST_CHUNK_SIZE = 5;
	T *tab;
	int tabSize;
	int startPos;
	int elementsCount;
public:
	Kontener();
	~Kontener();
	T get(int atIndex) const;
	void push_back(T element);
	void pop_front();
	void wyczysc();
	int size() const;

	friend ostream& operator<<(ostream& out, const Kontener<T, FIRST_CHUNK_SIZE>& el)
	{
		for (int i = 0; i < el.tabSize; i++)
		{
			out << el.tab[(i + el.startPos) % el.tabSize] << " ";
		}
		out << endl;
		return out;
	}

#if ETAP_5 == 1
	void sortuj(bool (*kryterium)(const T& a, const T& b));
#endif
};


template<class T, static const int FIRST_CHUNK_SIZE>
Kontener<T, FIRST_CHUNK_SIZE>::Kontener() : tab(nullptr), tabSize(0), startPos(0), elementsCount(0)
{

}

template<class T, static const int FIRST_CHUNK_SIZE>
Kontener<T, FIRST_CHUNK_SIZE>::~Kontener()
{
	delete[] tab;
}

template<class T, static const int FIRST_CHUNK_SIZE>
T Kontener<T, FIRST_CHUNK_SIZE>::get(int _atIndex) const
{
	if (!tab) throw  KontenerUninitializedException();
	//if (elementsCount == 0) throw  KontenerEmptyException();
	if (_atIndex < 0 || _atIndex > tabSize || elementsCount == 0) throw  KontenerIndexOutOfBoundsException(_atIndex);
	return tab[(startPos + _atIndex) % tabSize];
}

template<class T, static const int FIRST_CHUNK_SIZE>
void Kontener<T, FIRST_CHUNK_SIZE>::push_back(T element)
{
	if (!tab) // lista pusta
	{
		tab = new T[FIRST_CHUNK_SIZE];
		tabSize = FIRST_CHUNK_SIZE;
		tab[startPos] = element;
		elementsCount++;
	}
	else if (elementsCount == tabSize) // powiekszanie listy x2
	{
		T *temp = new T[tabSize];
		for (int i = 0; i < tabSize; i++)
		{
			temp[i] = tab[i];
		}
		delete[] tab; tab = nullptr; tab = new T[2 * tabSize];
		for (int i = 0; i < tabSize; i++)
		{
			tab[(i + startPos) % (2 * tabSize)] = temp[(i + startPos) % tabSize];
		}
		tab[(startPos + elementsCount) % (2 * tabSize)] = element;
		elementsCount++;
		tabSize = 2 * tabSize;
	}
	else
	{
		tab[(startPos + elementsCount) % tabSize] = element;
		elementsCount++;
	}
}

template<class T, static const int FIRST_CHUNK_SIZE>
void Kontener<T, FIRST_CHUNK_SIZE>::pop_front()
{
	if (!tab) throw  KontenerUninitializedException();
	if (elementsCount == 0) throw  KontenerEmptyException();
	tab[startPos] = 0.1;
	startPos = (startPos + 1) % tabSize;
	elementsCount--;
}

template<class T, static const int FIRST_CHUNK_SIZE>
void Kontener<T, FIRST_CHUNK_SIZE>::wyczysc()
{
	delete[] tab;
}

template<class T, static const int FIRST_CHUNK_SIZE>
int Kontener<T, FIRST_CHUNK_SIZE>::size() const
{
	return elementsCount;
}

template<class T, static const int FIRST_CHUNK_SIZE>
void Kontener<T, FIRST_CHUNK_SIZE>::sortuj(bool(*kryterium)(const T& a, const T& b))
{
	for (int i = 0; i < tabSize - 1; i++)
		for (int j = 0; j < tabSize - i - 1; j++)
		{
			if (kryterium(tab[j], tab[j + 1]))
				swap(tab[j], tab[j + 1]);
		}
}