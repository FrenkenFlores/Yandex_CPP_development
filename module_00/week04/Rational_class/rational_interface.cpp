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

int main() {
	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}