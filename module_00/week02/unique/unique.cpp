#include <iostream>
#include <set>


int main() {
	std::set<std::string> _set;
	int nbr;
	std::cin >> nbr;
	while (nbr > 0) {
		std::string input;
		std::cin >> input;
		_set.insert(input);
		nbr--;
	}
	std::cout << _set.size();
	return EXIT_SUCCESS;
}
