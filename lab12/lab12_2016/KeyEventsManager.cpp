#include "KeyEventsManager.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool KeyEventsManager::isValid() const {
	bool valid = keys.size() > 0;
	for (size_t i = 0; i < keys.size(); ++i) {
		valid &= keys.at(i).isValid();
	}
	return valid;
}
bool KeyEventsManager::equals(const KeyEventsManager &other) const {
	//if (keys.size() != other.keys.size()) return false;
	return keys == other.keys;
}

void KeyEventsManager::readTextFile(const char *fileName)
{
	ifstream plik(fileName, ios::in);
	if (!keys.empty()) keys.clear();
	plik.seekg(ios::beg);
	while (!plik.eof())
	{
		KeyEvent element;
		string wczytane;
		getline(plik, wczytane);
		string sep(" ");
		size_t start_pos = 0;
		size_t end_pos = wczytane.find(sep);
		while (end_pos != string::npos)
		{
			string trojka(wczytane.begin() + start_pos, wczytane.begin() + end_pos);
			start_pos = end_pos + 1;
			end_pos = wczytane.find(sep, start_pos);
			keys.push_back(element.parseText(trojka));
		}
		string trojka(wczytane.begin() + start_pos, wczytane.end());
		if (trojka.length() > 1)
		{
			keys.push_back(element.parseText(trojka));
		}
	}
	plik.clear();
	plik.close();
}

std::ostream & operator<<(std::ostream & out, const KeyEventsManager & key)
{
	for (int i = 0; i < key.keys.size(); i++ )
	{
		out << key.keys.at(i);
	}
	return out;
}

void KeyEventsManager::sort(bool(*crit)(const KeyEvent & , const KeyEvent & ))
{
	for (int i = 0; i < keys.size() - 1; i++)
		for (int j = 0; j < keys.size() - i - 1; j++)
		{
			if (crit(keys.at(j), keys.at(j + 1)))
				swap(keys.at(j), keys.at(j+1));
		}
}

void KeyEventsManager::saveBinaryFile(const char *fileName)
{
	ofstream plik(fileName, ios::out | ios::binary);
	plik.seekp(ios::beg);
	for (int i = 0; i < keys.size(); i++)
	{
		plik << keys.at(i);
	}
	plik.clear();
	plik.close();
}

void KeyEventsManager::loadBinaryFile(const char *fileName)
{
	ifstream plik(fileName, ios::in | ios::binary);
	plik.seekg(ios::beg);
	while (!plik.eof())
	{
		KeyEvent dane;
		plik >> dane;
		if (!dane.isValid()) break;
		keys.push_back(dane);
	}
	plik.clear();
	plik.close();
}

void KeyEventsManager::writeTextFile(const char *fileName)
{
	ofstream plik(fileName, ios::out);
	plik << *this;
}