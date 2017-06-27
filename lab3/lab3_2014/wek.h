
#include <iostream>
using namespace std;

const int N=3;

class wek  //wektor w R3
{
    double x[N];
public:
    wek(double=0,double=0,double=0);
    wek(double*);
    double operator*(const wek& b) const;  //iloczyn skalarny
	double& operator[](int i);
	double operator[](int i) const;
	friend bool operator==(const wek& w1, const wek& w2);
    friend ostream& operator<<(ostream&,const wek& v);
};
