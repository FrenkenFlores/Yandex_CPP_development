#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int i = 1;
	int n;
	std::cin >> n;
	map<set<string>, int> m;

	while (n > 0) {
		int count;
		cin >> count;
		set<string> stops;
		for (int i = 0; i < count; ++i) {
			string input;
			cin >> input;
			stops.insert(input);
		}
		if (m.find(stops) != m.end()) {
			cout << "Already exists for " << m[stops] << endl;
		} else {
			m[stops] = i;
			cout << "New bus " << i++ << endl;
		}
		n--;
	}
	return 0;
}

