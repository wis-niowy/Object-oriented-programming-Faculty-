

//template<double (*f)(double )>
template<double (*f)(double )>
class FUNKCJA : public wielomian<double>
{

public:
	FUNKCJA() : wielomian(0, nullptr) {};
	double operator()(double x) const
	{
		return f(x);
	}
		
	double operator()(double x, int) const
	{
		return (f(x + EPS) - f(x - EPS)) / (2 * EPS);
	}
};


