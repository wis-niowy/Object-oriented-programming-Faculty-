#pragma once
#include <iostream>
using namespace std;

// klasa slowo - 2 pkt

class slowo
{
	char* ang;	//slowo w j.angielskim
	char* pol;	//slowo w j.polskim
public:
	slowo(const char* _ang="", const char* _pol="");
	slowo(const slowo&);
	~slowo();
    	
	const char* get_ang() const { return ang; }
	const char* get_pol() const { return pol; }
	
	friend bool operator<(const slowo& , const slowo& );	//porownanie slow
	friend bool operator==(const slowo& , const slowo& );

	friend ostream& operator<<(ostream& , const slowo& );
};
