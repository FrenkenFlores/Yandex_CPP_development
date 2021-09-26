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
//	tmp duplicates i stream input
	std::string tmp;
//	Get current posistion
	int len = i.tellg();
//	Copy input in tmp string
	std::getline(i, tmp);
//	Return to position before getline()
	i.seekg(len ,std::ios_base::beg);
	if (i) {
		char first_delimiter, second_delimiter;
		int y, m, d;
		i >> y >> first_delimiter >> m >> second_delimiter >> d;
		if (!i || (i.peek() != int(' ')) && i.peek() != EOF) throw std::invalid_argument("Wrong date format:" + tmp);
		date.SetYear(y);
		date.SetMonth(m);
		date.SetDay(d);
		if (date.GetYear() <= 0 || date.GetMonth() <= 0 || date.GetDay() <= 0)
			throw std::invalid_argument("Wrong date format:" + tmp);
	}
	return i;
}


bool operator<(const Date& lhs, const Date& rhs) {

}

class Database {
private:
	std::map<const Date, set<const std::string> > db;
public:
	void AddEvent(const Date& date, const std::string& event) {
		if (event.empty()) return;
		if (db.find(date) == db.end()) {
			db[date].insert(event);
		} else if (db.at(date).find(event) == db.at(date).end())
			db[date].insert(event);
		std::cout << "Added successfully" << endl;
	}
	bool DeleteEvent(const Date& date, const std::string& event) {
		if (event.empty()) return false;
		if (db.at(date).find(event) == db.at(date).end()) {
			db[date].extract(event);
			std::cout << "Deleted successfully" << std::endl;
			return true;
		}
		else {
			std::cout << "Event not found" << std::endl;
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		int n = 0;
		if (db.find(date) != db.end()) {
			n = db.at(date).size();
			db.erase(date);
			std::cout << "Deleted " << db.at(date).size() << " events" << std::endl;
		}
		return n;
	}

	void Find(const Date& date) const {
		std::string events = "";
		for (const std::string &event : db.at(date)) {
			events += event + " ";
		}
		events.erase(events.end() - 1);
		std::cout << events << std::endl;
	}

	void Print() const {
		for (const std::pair<const Date, set<const std::string> > pair : db) {
			std::cout << pair.first.GetYear() << '-' << pair.first.GetMonth() << '-' << pair.first.GetDay() << ' ';
			this->Find(pair.first);
		}
	}
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
	if (!s || s.peek() != EOF) {
		s >> event;
		database->DeleteEvent(date, event);
	} else {
		database->DeleteDate(date);
	}

//	std::cout << "del: " << action << "/" << date.GetDay() << "/"<< date.GetMonth() << "/" << date.GetYear() << "/" << event << "\n";
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
	if (commands.find(action) == commands.end()) {
		std::cout << "Unknown command: " << command << endl;
		return false;
	} else if (action != "Print") {
		Date date;
		try {
			s >> date;
		} catch (std::invalid_argument &e) {
			std::cout << e.what() << std::endl;
			return false;
		}
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