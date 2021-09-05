#include <iostream>
#include <numeric>
using namespace std;

class Rational {
public:
	Rational() {
		this->_numerator = 0;
		this->_denominator = 1;
	}

	Rational(int numerator, int denominator) {
		int negative = 1;
		if (numerator == 0) {
			this->_numerator = 0;
			this->_denominator = 1;
			return;
		}
		if (numerator < 0 && denominator > 0) {
			negative = -1;
			numerator *= -1;
		}
		else if (numerator > 0 && denominator < 0) {
			negative = -1;
			denominator *= -1;
		}
		else if (numerator < 0 && denominator < 0) {
			negative = 1;
			numerator *= -1;
			denominator *= -1;
		}
		int greatest_common_divisor = std::gcd(numerator, denominator);
		this->_numerator = (numerator / greatest_common_divisor) * negative;
		this->_denominator = denominator / greatest_common_divisor;
	}

	int Numerator() const {
		return this->_numerator;
	}

	int Denominator() const {
		return this->_denominator;
	}

private:
	int _numerator;
	int _denominator;
};

bool operator==(const Rational &lhs, const Rational &rhs) {
	return (lhs.Denominator() == rhs.Denominator() && lhs.Numerator() == rhs.Numerator());
}

Rational operator+(const Rational &lhs, const Rational &rhs) {
	if (lhs.Denominator() == rhs.Denominator())
		return Rational(lhs.Numerator() + rhs.Numerator(), rhs.Denominator());
	else
		return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator-(const Rational &lhs, const Rational &rhs) {
	if (lhs.Denominator() == rhs.Denominator())
		return Rational(lhs.Numerator() - rhs.Numerator(), rhs.Denominator());
	else
		return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator*(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator/(const Rational &lhs, const Rational &rhs) {
	return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a * b;
		bool equal = c == Rational(8, 9);
		if (!equal) {
			cout << "2/3 * 4/3 != 8/9" << endl;
			return 1;
		}
	}

	{
		Rational a(5, 4);
		Rational b(15, 8);
		Rational c = a / b;
		bool equal = c == Rational(2, 3);
		if (!equal) {
			cout << "5/4 / 15/8 != 2/3" << endl;
			return 2;
		}
	}

	cout << "OK" << endl;
	return 0;
}
