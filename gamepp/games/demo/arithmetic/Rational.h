#ifndef GAMEPP_GAMES_DEMO_ARITHMETIC_RATIONAL_H
#define GAMEPP_GAMES_DEMO_ARITHMETIC_RATIONAL_H

#include <ostream>

class Rational
{
private:
	long long num, den;

public:
	Rational(long long n, long long d = 1);

	friend std::ostream& operator<<(std::ostream&, const Rational&);

	friend bool operator==(const Rational&, const Rational&);
	friend bool operator!=(const Rational&, const Rational&);

	friend bool operator<(const Rational&, const Rational&);
	friend bool operator<=(const Rational&, const Rational&);
	friend bool operator>(const Rational&, const Rational&);
	friend bool operator>=(const Rational&, const Rational&);

	friend Rational operator*(const Rational&, const Rational&);
	friend Rational operator/(const Rational&, const Rational&);
	friend Rational operator+(const Rational&, const Rational&);
	friend Rational operator-(const Rational&, const Rational&);
};

#endif
