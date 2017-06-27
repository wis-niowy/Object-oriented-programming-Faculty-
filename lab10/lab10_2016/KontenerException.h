#pragma once

#include <string>

class KontenerException {
public:
	virtual std::string info() const = 0; // metoda zwracaj¹ca krotki opis problemu
};

class KontenerUninitializedException : public KontenerException
{
public:
	KontenerUninitializedException() {};
	std::string info() const
	{
		return "Proba dostepu do danych niezainicjalizowanego Kontenera (bez zaalokowanej pamiêci)!";
	}
};

class KontenerEmptyException : public KontenerException
{
public:
	KontenerEmptyException() {};
	std::string info() const
	{
		return "Proba pobrania elementu z pustego kontenera!";
	}
};

class KontenerIndexOutOfBoundsException : public KontenerException
{
	int indeks;
public:
	KontenerIndexOutOfBoundsException(int indeks) : indeks(indeks) {};
	std::string info() const
	{
		char* char_indeks = new char[1];
		char_indeks[0] = (char)indeks + (char)'0'; // ????????????????
		std::string str_indeks = std::string(char_indeks);
		return "Proba dostepu do nieistniejacego indeksu Kontenera! Podany indeks to: " + str_indeks;
	}
};