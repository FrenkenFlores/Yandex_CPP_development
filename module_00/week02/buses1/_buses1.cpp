#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

void parse_line(std::map<std::string, std::vector<std::string> > &bus_stop) {
	std::string str;
	std::cin >> str;
	if (str == "NEW_BUS") {
		std::string bus;
		int stop_count;
		std::cin >> bus >> stop_count;
		std::string stops[stop_count];
		for (int i = 0; i < stop_count; ++i) {
			std::cin >> stops[i];
			bus_stop[bus].push_back(stops[i]);
		}
	}
	else if (str == "BUSES_FOR_STOP") {
		bool flag = false;
		std::vector<std::string> busses;
		std::string stop;
		std::cin >> stop;
		for (auto i : bus_stop) {
			for (auto j : i.second) {
				if (j.find(stop) != std::string::npos) {
					flag = true;
					busses.push_back(i.first);
					busses.push_back(" ");
				}
			}
		}
		if (flag == false)
			std::cout << "No stop";
		for (int i = 1; i < busses.size(); i++) {
			std::cout << busses[i - 1];
		}
		std::cout << std::endl;
	}
	else if (str == "STOPS_FOR_BUS") {
		bool flag = false;
		std::vector<std::string> inter;
		std::string bus;
		std::cin >> bus;
		//check if bus exists
		for (auto i : bus_stop) {
			if (i.first == bus) {
				flag = true;
			}
		}
		if (flag == false) {
			std::cout << "No bus" << std::endl;
			return;
		}
		//output
		std::vector<std::string> stops;
		for (auto i : bus_stop[bus]) {
			//check intersection with other busses
			for (auto k : bus_stop) {
				for (auto z : k.second) {
					std::cout << "Checked: " << k.first << std::endl;
					if (z == i && k.first != bus) {
						inter.push_back(k.first);
						std::cout << "Pushed back: " << k.first << std::endl;
						break;
					}
				}
			}
			std::cout << "Stop " << i << ":";
			if (inter.empty())
				std::cout << " no interchange" << std::endl;
			else {
				for (int j = 0; j < inter.size(); j++) {
					std::cout << " " << inter[j];
				}
				std::cout << std::endl;
			}
			inter.clear();
		}
	} else if (str == "ALL_BUSES") {
		if (bus_stop.empty()) {
			std::cout << "No buses" << std::endl;
			return;
		}
		for (auto i : bus_stop) {
			std::cout << "Bus " << i.first << ":";
			for (auto j : i.second) {
				std::cout << " " << j;
			}
			std::cout << std::endl;
		}
	}
}

int main() {
	int nbr;
	std::map<std::string, std::vector<std::string> > bus_stop;
	std::cin >> nbr;
	while (nbr >= 0) {
		parse_line(bus_stop);
		nbr--;
	}
	return EXIT_SUCCESS;
}
