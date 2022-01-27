#include <map>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#include <iostream>

using namespace std;
enum class Lang {
	DE, FR, IT
};

struct Region {
	string std_name;
	string parent_std_name;
	map<Lang, string> names;
	int64_t population;
};

#include "find_max_repetition_count.cpp"

int main() {
	cout << FindMaxRepetitionCount({
										   {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   },
								   }) << endl;

	cout << FindMaxRepetitionCount({
										   {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Russia",
												   "Eurasia",
												   {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Toulouse",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   89
										   }, {
												   "Moscow",
												   "Russia",
												   {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
												   31
										   },
								   }) << endl;

	return 0;
}
