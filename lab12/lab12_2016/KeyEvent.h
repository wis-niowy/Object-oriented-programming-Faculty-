#pragma once

#include <string>
#include <iostream>
#include "Etapy.h"
#include <fstream>

class KeyEvent
{
public:
	enum KeyEventType {
		KEY_EVENT_INVALID,
		KEY_EVENT_PRESS,
		KEY_EVENT_RELEASE
	};

private:
	int keyCode;
	long time;
	KeyEventType type;

public:
	KeyEvent() : keyCode(0), time(-1), type(KEY_EVENT_INVALID) {}
	~KeyEvent() {}
	bool isValid() const {
		return keyCode != 0 && time >= 0 && type != KEY_EVENT_INVALID;
	}
	bool operator==(const KeyEvent &other) const {
		return keyCode == other.keyCode && time == other.time && type == other.type;
	}

#if ETAP1 == 1
	static KeyEvent parseText(std::string &);
#endif
#if ETAP2 == 1
	friend std::ostream & operator<<(std::ostream &, const KeyEvent &);
#endif
#if ETAP3 == 1
	static bool timewiseAscOrder(const KeyEvent &, const KeyEvent &);
#endif
#if ETAP4 == 1
	friend std::ofstream & operator<<(std::ofstream &, const KeyEvent &);
	friend std::ifstream & operator>>(std::ifstream &, KeyEvent &);
#endif
};
