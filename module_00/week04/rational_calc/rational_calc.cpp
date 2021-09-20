#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <numeric>
#include <map>
#include <set>
#include <vector>
#include <stdexcept>
#include <algorithm>
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
		else if (denominator == 0) {
			throw std::invalid_argument("Invalid argument");
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
	int new_num = lhs.Numerator() * rhs.Denominator();
	int new_den = lhs.Denominator() * rhs.Numerator();
	if (new_den == 0) {
		throw std::domain_error("Division by zero");
	}
	return Rational(new_num, new_den);
}

istream &operator>>(istream &i, Rational &obj) {
	if (i) {
		char symbol;
		int numerator;
		int	denominator;
		i >> numerator;
		if (i.fail() || i.eof())
			return i;

		i >> symbol;
		if (i.fail() || i.eof() || symbol != '/')
			return i;

		i >> denominator;
		if (i.fail())
			return i;

		obj = Rational(numerator, denominator);
	}
	return i;
}


ostream &operator<<(ostream &o, const Rational &obj) {
	o << obj.Numerator() << '/' << obj.Denominator();
	return o;
}

bool operator<(const Rational &lhs, const Rational &rhs) {
	int d = lhs.Denominator() * rhs.Denominator();
	return (lhs.Numerator() * (d / lhs.Denominator())) < (rhs.Numerator() * (d / rhs.Denominator()));
}

int main() {
	Rational r;
	Rational l;
	string operation;
	try {
		std::cin >> r >> operation >> l;
		if (operation == "+") {
			std::cout << r + l << std::endl;
		} else if (operation == "-") {
			std::cout << r - l << std::endl;
		} else if (operation == "*") {
			std::cout << r * l << std::endl;
		} else if (operation == "/") {
			std::cout << r / l << std::endl;
		}
	} catch (exception& e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
	return 0;
}