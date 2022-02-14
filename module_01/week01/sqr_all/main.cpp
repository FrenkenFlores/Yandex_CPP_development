#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;
#include "sqr_all.cpp"



int main(){
	// Пример вызова функции
	vector<int> v = {1, 2, 3};
	cout << "vector:";
	for (int x : Sqr(v)) {
	cout << ' ' << x;
	}
	cout << endl;

	map<int, int> map_of_nums = {
			{4, 5},
			{7, 3}
	};

	cout << "map of numbers:" << endl;
	for (const auto& x : Sqr(map_of_nums)) {
		cout << x.first << ' ' << x.second << endl;
	}

	map<int, pair<int, int>> map_of_pairs = {
			{4, {2, 2}},
			{7, {4, 3}}
	};

	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
	cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

	map<int, vector<double> > map1 = {
			{4, {232, 2}},
			{7, {12, 3}}
	};
	for (const auto& x : Sqr(map1)) { }


	map<int, pair<vector<int>, int> > map2 = {
			{4, {{2,2,3}, 2}},
			{7, {{4,5,4}, 3}}
	};

	for (const auto& x : Sqr(map_of_pairs)) {}
}