#include <fstream>
#include <iostream>

int main(void) {
	std::string line;
	std::ifstream input("input.txt");
	std::ofstream output("output.txt");
	while (std::getline(input, line))
		output << line << std::endl;

	return 0;
}