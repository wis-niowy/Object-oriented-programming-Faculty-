#include <math.h>
#include "CMPLX.h"
//-----------------------------------------------
ostream& operator<<(ostream& out,CMPLX& z)
{
	out<<"("<<z.re<<","<<z.im<<")";
	return out;
}//----------------------------------------------
CMPLX CMPLX::operator*(CMPLX& z)
{
	CMPLX w;
	w.re=re*z.re-im*z.im;
	w.im=re*z.im+im*z.re;
	return w;
}//----------------------------------------------
CMPLX operator*(double r,CMPLX& z)
{
	return CMPLX(r*z.re,r*z.im);
}//----------------------------------------------
CMPLX CMPLX::operator/(CMPLX& z)
{
	CMPLX w;
	w.re=(re*z.re+im*z.im)/(z.re*z.re+z.im*z.im);
	w.im=-(re*z.im+im*z.re)/(z.re*z.re+z.im*z.im);
	return w;
}//----------------------------------------------
CMPLX CMPLX::operator-(CMPLX& z)
{
	CMPLX w;
	w.re=re-z.re;
	w.im=im-z.im;
	return w;
}//-----------------------------------------------
CMPLX CMPLX::operator+(CMPLX& z)
{
	CMPLX w;
	w.re=re+z.re;
	w.im=im+z.im;
	return w;
}//-----------------------------------------------
