#include <fstream>
#include <iostream>

int main(void) {
	std::string line;
	std::ifstream input("input.txt");
	while (std::getline(input, line))
		std::cout << line << std::endl;

	return 0;
}