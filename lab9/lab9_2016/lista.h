#pragma once
#include <iostream> 
#include "samolot.h"
using namespace std;

struct statek_powietrzny
{
	statek_powietrzny *next;
	samolot *ufo; //Unidentified Flying Object :)
};

class lista
{
	statek_powietrzny *head;
public:
	lista():head(nullptr){}
	~lista();
	int size() const;
	void push_back(samolot *s);
	void pop_front();
	void remove(statek_powietrzny *ol); //usuwa wskazywany element z listy
	statek_powietrzny *get(int); //zwraca wskaünik do i-tego elementu listy
};