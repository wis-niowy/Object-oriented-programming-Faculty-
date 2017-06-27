#pragma once
#include <iomanip>
#include <iostream> 
#include <string> 
using namespace std;

class wyjatek_transportu
{
protected:
	string wiadomosc;
public:
	wyjatek_transportu(string _wiadomosc="Samolot zostaje na ziemi");
	virtual void info() const;
};

class wyjatek_braku_paliwa: public wyjatek_transportu
{
	double paliwo;
public:
	wyjatek_braku_paliwa(string _wiadomosc, double _paliwo);
	void info() const;
};

class wyjatek_oplacalnosci :public wyjatek_transportu
{
	double zaladunek;
public:
	wyjatek_oplacalnosci(double _zaladunek);
	void info() const;
};
