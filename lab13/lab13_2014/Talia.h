#pragma once
#include <iostream>
#include <deque>
using namespace std;

class Talia
{
protected:
	deque<string> karty;

public:
	//Talia() {};
	Talia(const char**);
	Talia(const Talia&);
	void potasuj();
	friend ostream& operator<<(ostream& out, const Talia& t);
};

