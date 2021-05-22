#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <cstdlib>

struct calendar {
	typedef std::vector<std::vector<std::string> > month;
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

void add(std::string command[], calendar &cal) {
	cal.mon[cal.id][std::stoi(command[1]) - 1].push_back(command[2]);
};
void next(calendar &cal) {
	int difference = 0;
	cal.id = (cal.id + 1) % 12;
	for (size_t i = 0; i < cal.mon[cal.id].size(); i++) {
		cal.mon[cal.id][i] = cal.mon[cal.id - 1][i];
	}
	difference = cal.mon[cal.id - 1].size() - cal.mon[cal.id].size();

	while (difference >= 0) {
		for (int i = 0; i < cal.mon[cal.id - 1][cal.mon[cal.id - 1].size() - difference - 1].size(); i++) {
			cal.mon[cal.id][cal.mon[cal.id].size() - 1].push_back(cal.mon[cal.id - 1][cal.mon[cal.id - 1].size() - difference - 1][i]);
		}
		difference--;
	}
}
void dump(std::string command[], calendar &cal) {
	std::cout << cal.mon[cal.id][std::stoi(command[1]) - 1].size() << " ";
	for (int i = 0; i < cal.mon[cal.id][std::stoi(command[1]) - 1].size(); ++i) {
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