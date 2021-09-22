#include <string>
#include <map>
#include <set>
#include <iostream>
#include <exception>
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

std::istream &operator>>(std::istream &i, Date &date) {
	if (i) {
		int y, m, d;
		i >> y;
		i.ignore(1);
		i >> m;
		i.ignore(1);
		i >> d;
		date.SetYear(y);
		date.SetMonth(m);
		date.SetDay(d);
	}
	return i;
}

bool operator<(const Date& lhs, const Date& rhs);

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

	void Find(const Date& date) const;

	void Print() const;
};

int find_date(const std::string &str) {
	for (int i = 0; i < str.length(); i++) {
		if (std::isalpha(str[i]))
			return i;
	}
	return 0;
}

int find_event(const std::string &str) {

	for (int i = 0; i < str.length(); i++) {
		if (std::isalpha(str[i]))
			return i;
	}
	return 0;
}


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
	database->AddEvent(date, event);
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
		if (commands.find(action) == commands.end()) {
			std::cout << "Unknown command: " << command << endl;
			continue;
		} else
			commands[action](&db, &command);
	}

	return 0;
}