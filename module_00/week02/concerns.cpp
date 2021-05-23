#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdlib>

typedef std::vector<std::vector<std::string> > month;

struct calendar {
	month mon;
	int table[12][1];
	int id;
	static month fill(int size) {
		std::vector<std::string> _list;
		month mon(size, _list);
		return mon;
	}
};

void init(calendar &cal) {
	cal.table[0][0] = 31;
	cal.table[1][0] = 28;
	cal.table[2][0] = 31;
	cal.table[3][0] = 30;
	cal.table[4][0] = 31;
	cal.table[5][0] = 30;
	cal.table[6][0] = 31;
	cal.table[7][0] = 31;
	cal.table[8][0] = 30;
	cal.table[9][0] = 31;
	cal.table[10][0] = 30;
	cal.table[11][0] = 31;
	cal.id = 0;
	cal.mon = calendar::fill(cal.table[0][0]);
}

void add(std::string command[], calendar &cal) {
	cal.mon[std::stoi(command[1]) - 1].push_back(command[2]);
};
void next(calendar &cal) {
	int difference = 0;
	month tmp_mon = cal.mon;
	cal.id = (cal.id + 1) % 12;
	cal.mon.resize(cal.table[cal.id][0]);
	for (size_t i = 0; i < cal.mon.size(); i++) {
		cal.mon[i] = tmp_mon[i];
	}
	difference = tmp_mon.size() - cal.mon.size();

	while (difference >= 0) {
		for (int i = 0; i < tmp_mon[tmp_mon.size() - difference - 1].size(); i++) {
			cal.mon[cal.mon.size() - 1].push_back(tmp_mon[tmp_mon.size() - difference - 1][i]);
		}
		difference--;
	}
}
void dump(std::string command[], calendar &cal) {
	std::cout << cal.mon[std::stoi(command[1]) - 1].size() << " ";
	for (int i = 0; i < cal.mon[std::stoi(command[1]) - 1].size(); ++i) {
		std::cout << cal.mon[std::stoi(command[1]) - 1][i] << " ";
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
	int i = 0;
	int j = 0;
	int z = 0;
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