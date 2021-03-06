#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>

void parse_line(std::vector<std::pair<std::string, std::vector<std::string> > > &bus_stop) {
	std::string str;
	std::cin >> str;
	if (str == "NEW_BUS") {
		std::string bus;
		int stop_count;
		std::cin >> bus >> stop_count;
		std::vector<std::string> stops;
		std::string input;
		for (int i = 0; i < stop_count; ++i) {
			std::cin >> input;
			stops.push_back(input);
		}
		bus_stop.push_back(std::pair<std::string, std::vector<std::string> >(bus, stops));
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
		int index = 0;
		while (bus_stop[index].first != bus) {
			index++;
		}
		std::vector<std::string> stops;
		for (auto i : bus_stop[index].second) {
			//check intersection with other busses
			for (auto k : bus_stop) {
				for (auto z : k.second) {
					if (z == i && k.first != bus) {
						inter.push_back(k.first);
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
		std::map< std::string, std::vector<std::string> > sorted_bus_stops;
		for (auto i : bus_stop) {
			sorted_bus_stops[i.first] = i.second;
		}
		for (auto i : sorted_bus_stops) {
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
	std::vector<std::pair<std::string, std::vector<std::string> > > bus_stop;	// vector of pairs as unsorted map
	std::cin >> nbr;
	while (nbr >= 0) {
		parse_line(bus_stop);
		nbr--;
	}
	return EXIT_SUCCESS;
}
