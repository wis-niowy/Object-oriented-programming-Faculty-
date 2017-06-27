#include <iostream>
using namespace std;

class	CMPLX	{
	double	re,im;
public:
	CMPLX(double _re=0,double _im=0){re=_re; im=_im;};
	CMPLX operator*(CMPLX&);
	CMPLX operator/(CMPLX&);
	CMPLX operator-(CMPLX&);
	CMPLX operator+(CMPLX&);
	
	friend ostream& operator<<(ostream&,CMPLX&);
	friend CMPLX operator*(double,CMPLX&);
	friend double abs(const CMPLX& z) {return sqrt(z.re*z.re+z.im*z.im);}
};
