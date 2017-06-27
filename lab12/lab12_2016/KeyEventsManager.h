#pragma once

#include "KeyEvent.h"
#include <fstream>
#include <vector>

class KeyEventsManager
{
	std::vector<KeyEvent> keys;
public:
	KeyEventsManager() {}
	~KeyEventsManager() {}
	bool isValid() const;
	bool equals(const KeyEventsManager &) const;

#if ETAP1 == 1
	void readTextFile(const char *fileName);
#endif
#if ETAP2 == 1
	friend std::ostream & operator<<(std::ostream &, const KeyEventsManager &);
#endif
#if ETAP3 == 1
	void sort(bool(*crit)(const KeyEvent &, const KeyEvent &));
#endif
#if ETAP4 == 1
	void saveBinaryFile(const char *fileName);
	void loadBinaryFile(const char *fileName);
#endif
#if ETAP5 == 1
	void writeTextFile(const char *);
#endif
};

