#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "slowo.h"

//----------------------------------------------------
slowo::slowo(const char* _ang, const char* _pol)
{
	ang = new char[strlen(_ang) + 1];
	pol = new char[strlen(_pol) + 1];
	strcpy(ang, _ang);
	strcpy(pol, _pol);
}
//---------------------------------------------------
slowo::slowo(const slowo& slowo)
{
	if (!slowo.ang || !slowo.pol) return;
	ang = new char[strlen(slowo.ang) + 1];
	pol = new char[strlen(slowo.pol) + 1];
	strcpy(ang, slowo.ang);
	strcpy(pol, slowo.pol);
}
//---------------------------------------------------
slowo::~slowo()
{
	if (ang) delete[] ang;
	if (pol) delete[] pol;
}
//---------------------------------------------------
bool operator<(const slowo& s1, const slowo& s2)
{
	return strcmp(s1.ang, s2.ang) < 0;
}
//---------------------------------------------------
bool operator==(const slowo& s1, const slowo& s2)
{
	return strcmp(s1.ang, s2.ang) == 0;
}
//---------------------------------------------------
ostream& operator<<(ostream& out, const slowo& slowo)
{
	out << "znaczenie angielskie: " << slowo.ang << endl;
	out << "znaczenie polskie: " << slowo.pol << endl;
	return out;
}
//-----------------------------------------------
