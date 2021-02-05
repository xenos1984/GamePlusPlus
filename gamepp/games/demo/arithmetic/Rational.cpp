#include <numeric>
#include "Rational.h"

Rational::Rational(long long n, long long d)
{
	if(n == 0)
	{
		num = 0;
		den = 1;
	}
	else
	{
		long long gcd = std::gcd(std::abs(n), std::abs(d));
		den = std::abs(d) / gcd;
		num = (d < 0 ? -1 : 1) * n / gcd;
	}
}

std::ostream& operator<<(std::ostream& os, const Rational& r)
{
	os << r.num;
	if(r.den != 1)
		os << "/" << r.den;
	return os;
}

bool operator==(const Rational& x, const Rational& y)
{
	return x.num == y.num && x.den == y.den;
}

bool operator!=(const Rational& x, const Rational& y)
{
	return !(x == y);
}

bool operator<(const Rational& x, const Rational& y)
{
	return x.num * y.den < y.num * x.den;
}

bool operator>(const Rational& x, const Rational& y)
{
	return y < x;
}

bool operator<=(const Rational& x, const Rational& y)
{
	return !(y < x);
}

bool operator>=(const Rational& x, const Rational& y)
{
	return !(x < y);
}

Rational operator*(const Rational& x, const Rational& y)
{
	return Rational(x.num * y.num, x.den * y.den);
}

Rational operator/(const Rational& x, const Rational& y)
{
	return Rational(x.num * y.den, x.den * y.num);
}

Rational operator+(const Rational& x, const Rational& y)
{
	return Rational(x.num * y.den + y.num * x.den, x.den * y.den);
}

Rational operator-(const Rational& x, const Rational& y)
{
	return Rational(x.num * y.den - y.num * x.den, x.den * y.den);
}
