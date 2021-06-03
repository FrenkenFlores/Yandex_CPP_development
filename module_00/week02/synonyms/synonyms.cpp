#include <map>
#include <set>
#include <string>
#include <iostream>

void check_synonym(std::string word1, std::string word2, std::map<std::string, std::set<std::string> > &_map) {
	for (auto i : _map[word1]) {
		if (word2 == i) {
			std::cout << "YES" << std::endl;
			return;
		}
	}
	std::cout << "NO" << std::endl;
	return ;
}


int main() {
	int n;
	std::map<std::string, std::set<std::string> > _map;
	std::set<std::string> _set;
	std::string input;
	std::cin >> n;
	while (n > 0) {
		std::cin >> input;
		if (input == "ADD") {
			std::string word, synonym;
			std::cin >> word >> synonym;
			_map[word].insert(synonym);
			_map[synonym].insert(word);
		} else if (input == "COUNT") {
			std::string word;
			std::cin >> word;
			std::cout << _map[word].size() << std::endl;
		} else if (input == "CHECK") {
			std::string word1, word2;
			std::cin >> word1 >> word2;
			check_synonym(word1, word2, _map);
		}
		n--;
	}

	return 0;
}