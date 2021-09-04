#include <fstream>
#include <iostream>
#include <iomanip>

int main(void) {
	double num;
	std::ifstream input("input.txt");
	if (input.is_open()) {
		std::cout << std::fixed << std::setprecision(3);
		while (input >> num) {
			std::cout << num << std::endl;
		}
	}
	return 0;
}