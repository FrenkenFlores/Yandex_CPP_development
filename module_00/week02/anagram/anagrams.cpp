#include <map>
#include <iostream>
//counts how much symbols the words have got
std::map<char, int> BuildCharCounters(const std::string &str) {
	std::map<char, int> _map;
	for (char c : str) {
		_map[c] = _map[c] + 1;
	}
	return _map;
}

int main() {
	int nbr;
	std::string str_1;
	std::string str_2;
	std::cin >> nbr;
	while (nbr != 0) {
		std::cin >> str_1 >> str_2;
		if (BuildCharCounters(str_1) == BuildCharCounters(str_2))
			std::cout << "YES" << std::endl;
		else
			std::cout << "NO" << std::endl;
		nbr--;
	}
	return EXIT_SUCCESS;
}