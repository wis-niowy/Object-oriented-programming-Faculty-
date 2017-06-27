#include <cmath>
// tutaj zaimplementuj klasê COSINUS

// COSINUS jako zwykla klasa:

//class COSINUS: public wielomian<double>
//{
//	
//public:
//	//COSINUS() : wielomian<double>() {};
//	COSINUS(): wielomian(0, nullptr) {};
//	double operator()(double x) const 
//	{
//		return cos(x);
//	}
//
//	double operator()(double x, int) const
//	{
//		return -sin(x);
//	}
//};

// COSINUS jako szablon dzidziczacy inny szablon:

template<class T=double>
class COSINUS : public wielomian<T>
{

public:
	//COSINUS() : wielomian<double>() {};
	COSINUS() : wielomian(0, nullptr) {};
	T operator()(T x) const
	{
		return cos(x);
	}

	T operator()(T x, int) const
	{
		return -sin(x);
	}
};
