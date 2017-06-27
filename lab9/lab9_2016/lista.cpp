#include "lista.h"

lista::~lista()
{
	statek_powietrzny* jumper = head, *jumper2 = head->next;
	while (jumper2 != nullptr)
	{
		delete[] jumper;
		jumper = jumper2;
		jumper2 = jumper2->next;
	}
	delete[] jumper;
	head = nullptr;
}

int lista::size() const
{
	statek_powietrzny *jumper = head;
	int rozmiar = 0;
	if (jumper != nullptr)
	{
		rozmiar++;
		while (jumper->next != nullptr)
		{
			rozmiar++;
			jumper = jumper->next;
		}
	}
	return rozmiar;
}

void lista::push_back(samolot *s)
{
	statek_powietrzny *jumper = head;
	if (head == nullptr) // glowy nie ma
	{
		head = new statek_powietrzny;
		head->next = nullptr;
		head->ufo = s;
	}
	else
	{
		while (jumper->next != nullptr)
		{
			jumper = jumper->next;
		}
		jumper->next = new statek_powietrzny;
		jumper->next->ufo = s;
		jumper->next->next = nullptr;
	}
}

void lista::pop_front()
{
	statek_powietrzny* jumper = head->next;
	delete[] head;
	head = jumper;
}

void lista::remove(statek_powietrzny *ol)
{
	statek_powietrzny* jumper = head;
	while (jumper != nullptr && jumper->next != ol)
	{
		jumper = jumper->next;
	}
	jumper->next = ol->next;
	ol->next = nullptr;
	delete[] ol;
}

statek_powietrzny *lista::get(int i)
{
	if (i >= 1)
	{
		i--;
		statek_powietrzny *jumper = head;
		while (i > 0 && jumper->next != nullptr)
		{
			jumper = jumper->next;
			i--;
		}
		if (i == 0) return jumper;
		else return nullptr;
	}
}