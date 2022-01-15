//
// Created by FrenkenFlores on 13.01.2022.
//

// Fail some tests, should be implemented by STL vectors in the task
#include <iostream>
#include <stdexcept>
#include "matrix_sum.cpp"

using namespace std;

int main() {
	Matrix one;
	Matrix two;

	cin >> one >> two;
	cout << one + two << endl;

	try {
		std::cout << Matrix(0,5) + Matrix(8, 0);
	} catch (exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << Matrix(-1,-1);
	} catch (exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << Matrix(5,5).At(-1,-1);
	} catch (exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << Matrix(5,5).At(5,5);
	} catch (exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}