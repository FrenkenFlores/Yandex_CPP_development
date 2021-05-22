#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>

//std::vector<std::list<std::string> > january(31, nullptr);
//std::vector<std::list<std::string> > february(28, nullptr);
//std::vector<std::list<std::string> > march(31, nullptr);
//std::vector<std::list<std::string> > april(30, nullptr);
//std::vector<std::list<std::string> > may(31, nullptr);
//std::vector<std::list<std::string> > june(30, nullptr);
//std::vector<std::list<std::string> > july(31, nullptr);
//std::vector<std::list<std::string> > august(31, nullptr);
//std::vector<std::list<std::string> > september(30, nullptr);
//std::vector<std::list<std::string> > october(31, nullptr);
//std::vector<std::list<std::string> > november(30, nullptr);
//std::vector<std::list<std::string> > december(31, nullptr);




struct calendar {
	typedef std::vector<std::list<std::string> > month;
	month january;
	month february;
	month march;
	month april;
	month may;
	month june;
	month july;
	month august;
	month september;
	month october;
	month november;
	month december;
	static month fill(int size) {
		std::list<std::string> _list;
		month mon(size, _list);
		return mon;
	}
};

void init(calendar &cal) {
	cal.january = calendar::fill(31);
	cal.february = calendar::fill(28);
	cal.march = calendar::fill(31);
	cal.april = calendar::fill(30);
	cal.may = calendar::fill(31);
	cal.june = calendar::fill(30);
	cal.july = calendar::fill(31);
	cal.august = calendar::fill(31);
	cal.september = calendar::fill(30);
	cal.october = calendar::fill(31);
	cal.november = calendar::fill(30);
	cal.december = calendar::fill(31);
}

void add(std::string command[]) {
	std::cout << "ADD" << std::endl;
};
void next(std::string command[]) {
	std::cout << "NEXT" << std::endl;
}
void dump(std::string command[]) {
	std::cout << "DUMP" << std::endl;
}

void launch_command(std::string com[]) {
	if (com[0].find("ADD") != std::string::npos)
		add(com);
	else if (com[0].find("NEXT") != std::string::npos)
		next(com);
	else if (com[0].find("DUMP") != std::string::npos)
		dump(com);
}

void parse_line(std::string &str) {
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
	launch_command(com);
}



int main(void) {
	int q;
	std::string str;
	calendar cal;

	init(cal);
	std::cin >> q;
	while (q != 0) {
		std::getline(std::cin, str);
		parse_line(str);
		q--;
	}

	return (0);
}