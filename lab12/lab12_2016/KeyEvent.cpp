#include "KeyEvent.h"

KeyEvent KeyEvent::parseText(std::string & text)
{
	std::string separator(",");
	size_t start_pos = 0;
	size_t end_pos = text.find(separator);
	std::string _keyCode(text.begin() + start_pos, text.begin() + end_pos);
	start_pos = end_pos + 1;
	end_pos = text.find(separator, start_pos);
	std::string _type(text.begin() + start_pos, text.begin() + end_pos);
	start_pos = end_pos + 1;
	std::string _time(text.begin() + start_pos, text.end());

	KeyEvent do_zwrotu;
	do_zwrotu.keyCode = stoi(_keyCode);
	do_zwrotu.time = stoi(_time);
	if (_type == "d")
	{
		do_zwrotu.type = KEY_EVENT_PRESS;
	}
	else if (_type == "u")
	{
		do_zwrotu.type = KEY_EVENT_RELEASE;
	}
	else
	{
		do_zwrotu.type = KEY_EVENT_INVALID;
	}
	return do_zwrotu;
}

std::ostream & operator<<(std::ostream & out, const KeyEvent & key)
{
	char _type;
	if (key.type == 1)
	{
		_type = 'd';
	}
	else if (key.type == 2)
	{
		_type = 'u';
	}
	out << key.keyCode << "," << _type << "," << key.time << " ";
	return out;
}

bool KeyEvent::timewiseAscOrder(const KeyEvent & key1, const KeyEvent & key2)
{
	return (key1.time - key2.time) > 0;
}

std::ofstream & operator<<(std::ofstream & plik, const KeyEvent & key)
{
	plik.write((char*)&key, sizeof(KeyEvent));
	return plik;
}

std::ifstream & operator>>(std::ifstream & plik, KeyEvent & key)
{
	plik.read((char*)&key, sizeof(KeyEvent));
	return plik;
}