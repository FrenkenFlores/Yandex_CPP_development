#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
//in specified order
bool check_if_already_exist(std::map<int, std::string> & bus_stop, std::string stops_list) {
	int count = 0;
	int size = 0;
	int index = 0;
	for (auto i : bus_stop) {
		if (i.second == stops_list) {
			std::cout << "Already exists for " << i.first << std::endl;
			return true;
		}
	}
	return false;
}


int main() {
	int z = 1;
	int nbr;
	std::map<int, std::string> bus_stop;
	std::cin >> nbr;
	while (nbr > 0) {
		int N;
		std::cin >> N;
		std::string stops[N];
		std::string stops_list = "";
		for (int k = 0; k < N; ++k) {
			std::cin >> stops[k];
			stops_list = stops_list + " " + stops[k];
		}
		if (!check_if_already_exist(bus_stop, stops_list)) {
			bus_stop[z] = stops_list;
			std::cout << "New bus " << z++ << std::endl;
		}
		nbr--;
	}
	return EXIT_SUCCESS;
}
