#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Slowo.h"


bool otworz(fstream& );
bool dopisz(fstream& , Slowo& );
bool wypisz(fstream& );
bool modyfikuj(fstream& , int);

//bool szukaj(/* uzupe³nij */);
