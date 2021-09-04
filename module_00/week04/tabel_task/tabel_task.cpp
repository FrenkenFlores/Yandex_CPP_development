#include <fstream>
#include <iostream>
#include <iomanip>

int main(void) {
	int n, m, num;
	std::ifstream input("input.txt");
	if (input.is_open()) {
		input >> n;
		input.ignore(1);
		input >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				input >> num;
				input.ignore(1);
				if (j != m - 1)
					std::cout << std::setw(10) << num << " ";
				else
					std::cout << std::setw(10) << num;
			}
			if (i != n - 1)
				std::cout << std::endl;
		}
	}
	return 0;
}