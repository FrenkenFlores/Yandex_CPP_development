#include <string>
#include <map>
#include <set>
#include <iostream>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <sstream>
using namespace std;

using f = void (*)(void *db, void *cmd);
class Date {
public:
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }
	void SetYear(int _year) { year=_year; }
	void SetMonth(int _month) { month=_month; }
	void SetDay(int _day) { day=_day; }

private:
	int year;
	int month;
	int day;
};


std::ostream &operator<<(std::ostream &i, Date &date) {
	if (i)
		i << date.GetYear() << '-' << date.GetMonth() << '-' << date.GetDay();
	return i;
}

std::istream &operator>>(std::istream &i, Date &date) {
	if (i) {
		char first_delimiter, second_delimiter;
		int y, m, d;
		i >> y >> first_delimiter >> m >> second_delimiter >> d;
		if (!i) throw std::invalid_argument("Wrong date format");
		date.SetYear(y);
		date.SetMonth(m);
		date.SetDay(d);
		std::cout << (i.peek() == EOF) << std::endl;
		std::cout << date << std::endl;
		if (date.GetYear() <= 0 || date.GetMonth() <= 0 || date.GetDay() <= 0)
			throw std::invalid_argument("Wrong date format: " + date.GetYear() + first_delimiter + date.GetMonth() + second_delimiter + date.GetDay());
	}
	return i;
}


bool operator<(const Date& lhs, const Date& rhs) {

}

class Database {
private:
	std::map<Date, set<const std::string> > db;
public:
	void AddEvent(const Date& date, const std::string& event) {
		if (event.empty()) return;
		if (db.at(date).find(event) == db.at(date).end())
			db[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const std::string& event) {
		if (event.empty()) return false;
		if (db.at(date).find(event) == db.at(date).end())
			db[date].extract(event);
		std::cout << "Deleted successfully" << endl;
	}
	int  DeleteDate(const Date& date) {

	}

	void Find(const Date& date) const {}

	void Print() const {}
};

void add(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<string *>(cmd);
	std::stringstream s(*command);
	std::string action;
	Date date;
	std::string event;
	s >> action;
	s >> date;
	s >> event;

//	std::cout << "add: " << action << "/" << date.GetDay() << "/"<< date.GetMonth() << "/" << date.GetYear() << "/" << event << "\n";
//	database->AddEvent(date, event);
}
void del(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<string *>(cmd);
	std::stringstream s(*command);
	std::string action;
	Date date;
	std::string event;
	s >> action;
	s >> date;
	s >> event;

//	std::cout << "del: " << action << "/" << date.GetDay() << "/"<< date.GetMonth() << "/" << date.GetYear() << "/" << event << "\n";
	database->AddEvent(date, event);
}
void find(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<string *>(cmd);
	std::stringstream s(*command);
	std::string action;
	Date date;
	s >> action;
	s >> date;

	database->Find(date);
}
void print(void *db, void *cmd){
	(void )cmd;
	Database *database = static_cast<Database *>(db);

	database->Print();
}

bool check_input(const 	std::map<std::string, f> commands, const std::string &command) {
	std::stringstream s(command);
	std::string action;
	s >> action;
	std::cout << action << std::endl;
	if (commands.find(action) == commands.end()) {
		std::cout << "Unknown command: " << command << endl;
		return false;
	} else if (action != "Print") {
		Date date;
		s >> date;
	}

	return true;
}

int main() {
	Database db;
	std::map<std::string, f> commands;
	commands["Add"] = &add;
	commands["Del"] = &del;
	commands["Find"] = &find;
	commands["Print"] = &print;
	std::string command;
	while (getline(std::cin, command)) {
		std::string action(command, 0, command.find(' '));
		if (check_input(commands, command))
			commands[action](&db, &command);
		else
			continue;
	}

	return 0;
}