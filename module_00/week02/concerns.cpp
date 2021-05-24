#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdlib>

typedef std::vector<std::vector<std::string> > month;

struct calendar {
	month mon[12];
	int id;
	static month fill(int size) {
		std::vector<std::string> _list;
		month mon(size, _list);
		return mon;
	}
};

void init(calendar &cal) {
	cal.mon[0] = calendar::fill(31);
	cal.mon[1] = calendar::fill(28);
	cal.mon[2] = calendar::fill(31);
	cal.mon[3] = calendar::fill(30);
	cal.mon[4] = calendar::fill(31);
	cal.mon[5] = calendar::fill(30);
	cal.mon[6] = calendar::fill(31);
	cal.mon[7] = calendar::fill(31);
	cal.mon[8] = calendar::fill(30);
	cal.mon[9] = calendar::fill(31);
	cal.mon[10] = calendar::fill(30);
	cal.mon[11] = calendar::fill(31);
	cal.id = 0;
}


void clean(month &mon) {
	std::vector<std::string> _list;
	for (size_t i = 0; i < mon.size(); ++i) {
		mon[i].clear();
	}
}

void add(std::string command[], calendar &cal) {
	cal.mon[cal.id][std::stoi(command[1]) - 1].push_back(command[2]);
};

void next(calendar &cal) {
	int difference = 0;
	cal.id = cal.id + 1;
	if (cal.id == 12) {
		cal.id = 0;
		month tmp = cal.mon[11];
		init(cal);
		cal.mon[11] = tmp;
	}
	int prev = cal.id - 1;
	if (cal.id == 0)
		prev = 11;

	for (size_t i = 0; i < cal.mon[cal.id].size() && i < cal.mon[prev].size(); i++) {
		cal.mon[cal.id][i] = cal.mon[prev][i];
		cal.mon[prev][i].clear();
	}
	difference = cal.mon[prev].size() - cal.mon[cal.id].size();

	while (difference >= 0) {
		int i = 0;
		while (cal.mon[prev][cal.mon[prev].size() - difference - 1].size() > i) {
			cal.mon[cal.id][cal.mon[cal.id].size() - 1].push_back(cal.mon[prev][cal.mon[prev].size() - difference - 1][i]);
			i++;
		}
		difference--;
	}
	clean(cal.mon[prev]);
}

void dump(std::string command[], calendar &cal) {
	std::cout << cal.mon[cal.id][std::stoi(command[1]) - 1].size() << " ";
	for (size_t i = 0; i < cal.mon[cal.id][std::stoi(command[1]) - 1].size(); ++i) {
		std::cout << cal.mon[cal.id][std::stoi(command[1]) - 1][i] << " ";
	}
	std::cout << std::endl;
}

void launch_command(std::string com[], calendar &cal) {
	if (com[0].find("ADD") != std::string::npos)
		add(com, cal);
	else if (com[0].find("NEXT") != std::string::npos)
		next(cal);
	else if (com[0].find("DUMP") != std::string::npos)
		dump(com, cal);
}

void parse_line(std::string &str, calendar &cal) {
	size_t i = 0;
	size_t j = 0;
	size_t z = 0;
	std::string com[3];
	std::string::iterator it_b = str.begin();
	std::string::iterator it_e = str.end();
	while ((i = str.find(" ")) && i != std::string::npos) {
		str[i] = '\0';
		com[j++] = std::string(it_b, it_b + i - z);
		it_b = str.begin() + i + 1;
		z = i;
	}
	com[j] = std::string(it_b, it_e);
	launch_command(com, cal);
}

int main(void) {
	int q;
	std::string str;
	calendar cal;

	init(cal);
	std::cin >> q;
	while (q >= 0) {
		std::getline(std::cin, str);
		parse_line(str, cal);
		q--;
	}
	return (0);
}