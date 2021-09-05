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

int main() {
	{
		Rational r1(4, 6);
		Rational r2(2, 3);
		bool equal = r1 == r2;
		if (!equal) {
			cout << "4/6 != 2/3" << endl;
			return 1;
		}
	}

	{
		Rational a(2, 3);
		Rational b(4, 3);
		Rational c = a + b;
		bool equal = c == Rational(2, 1);
		if (!equal) {
			cout << "2/3 + 4/3 != 2" << endl;
			return 2;
		}
	}

	{
		Rational a(5, 7);
		Rational b(2, 9);
		Rational c = a - b;
		bool equal = c == Rational(31, 63);
		if (!equal) {
			cout << "5/7 - 2/9 != 31/63" << endl;
			return 3;
		}
	}

	cout << "OK" << endl;
	return 0;
}