#include <map>
#include <string>
#include <set>
#include <iostream>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
	std::set<std::string> _set;
	for (auto i : m) {
		_set.insert(i.second);
	}
	return _set;
}

int main () {

	std::map<int, std::string> _map;
	_map[1] = "odd";
	_map[2] = "even";
	_map[3] = "odd";
	_map[4] = "even";
	_map[5] = "odd";
	_map[6] = "even";
	std::set<std::string> values = BuildMapValuesSet(_map);

	for (const std::string& value : values) {
		std::cout << value << std::endl;
	}
};