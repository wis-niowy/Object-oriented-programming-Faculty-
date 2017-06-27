//#include "Kontener.h"

//template<class T, static const int FIRST_CHUNK_SIZE>
//Kontener<T, FIRST_CHUNK_SIZE>::Kontener(): tab(nullptr), tabSize(0), startPos(0), elementsCount(0)
//{
//
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//Kontener<T, FIRST_CHUNK_SIZE>::~Kontener()
//{
//	delete[] tab;
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//T Kontener<T, FIRST_CHUNK_SIZE>::get(int _atIndex) const
//{
//	return tab[(startPos + _atIndex) % tabSize];
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//void Kontener<T, FIRST_CHUNK_SIZE>::push_back(T element)
//{
//	if (!tab) // lista pusta
//	{
//		tab = new T[FIRST_CHUNK_SIZE];
//		tabSize = FIRST_CHUNK_SIZE;
//		tab[startPos] = element;
//		elementsCount++;
//	}
//	else if (elementsCount == tabSize) // powiekszanie listy x2
//	{
//		T *temp = new T[tabSize];
//		for (int i = 0; i < tabSize; i++)
//		{
//			temp[i] = tab[i];
//		}
//		delete[] tab; tab = nullptr; tab = new T[2 * tabSize];
//		for (int i = 0; i < tabSize; i++)
//		{
//			tab[(i + startPos) % (2 * tabSize)] = temp[(i + startPos) % tabSize];
//		}
//		tab[(startPos + ++elementsCount) % (2 * tabSize)] = element;
//		tabSize = 2 * tabSize;
//	}
//	else
//	{
//		tab[(startPos + ++elementsCount) % tabSize] = element;
//	}
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//void Kontener<T, FIRST_CHUNK_SIZE>::pop_front()
//{
//	tab[startPos] = 0.1;
//	startPos = (startPos + 1) % tabSize;
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//void Kontener<T, FIRST_CHUNK_SIZE>::wyczysc()
//{
//	delete[] tab;
//}
//
//template<class T, static const int FIRST_CHUNK_SIZE>
//int Kontener<T, FIRST_CHUNK_SIZE>::size() const
//{
//	return elementsCount;
//}