#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
//in any order
bool check_if_already_exist(std::map<int, std::vector<std::string> > & bus_stop, std::string stops[], int N) {
	int count = 0;
	int size = 0;
	int index = 0;
	for (int k = 0; k < N; ++k) {
			for (auto i : bus_stop) {
				for (auto j : i.second) {
					if (j == stops[k]) {
						index = i.first;
						size = i.second.size();
						count++;
					}
				}
				if (count == size) {
					std::cout << "Already exists for " << index << std::endl;
					return true;
				}
			}
		}

	return false;
}


int main() {
	int z = 1;
	int nbr;
	std::map<int, std::vector<std::string> > bus_stop;
	std::cin >> nbr;
	while (nbr > 0) {
		int N;
		std::cin >> N;
		std::string stops[N];
		for (int k = 0; k < N; ++k) {
			std::cin >> stops[k];
		}
		if (!check_if_already_exist(bus_stop, stops, N)) {
			for (int k = 0; k < N; ++k) {
				bus_stop[z].push_back(stops[k]);
			}
			std::cout << "New bus " << z++ << std::endl;
		}
		nbr--;
	}
	return EXIT_SUCCESS;
}
