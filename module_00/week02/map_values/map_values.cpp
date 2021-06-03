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