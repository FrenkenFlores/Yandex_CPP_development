#include <string>
#include <map>
#include <set>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <iomanip>

using f = void (*)(void *db, void *cmd);

struct Day {
	int value;
	explicit Day(int new_value) {
		value = new_value;
	}
};

struct Month {
	int value;
	explicit Month(int new_value) {
		value = new_value;
	}
};

struct Year {
	int value;
	explicit Year(int new_value) {
		value = new_value;
	}
};


class Date {
public:
	int GetYear() const { return year; }
	int GetMonth() const { return month; }
	int GetDay() const { return day; }
	void SetYear(Year _year) { year=_year.value; }
	void SetMonth(Month _month) { month=_month.value; }
	void SetDay(Day _day) { day=_day.value; }

private:
	int year;
	int month;
	int day;
};


std::ostream &operator<<(std::ostream &i, Date &date) {
	std::cout << std::setfill('0');
	if (i) {
		if (date.GetYear() < 0) {
			i << '-' << std::setw(4) << (date.GetYear() * -1) << '-';
		} else {
			i << std::setw(4) << date.GetYear() << '-';
		}
		i << std::setw(2) << date.GetMonth() << '-' \
 		<< std::setw(2) << date.GetDay();
	}
	return i;
}

std::istream &operator>>(std::istream &i, Date &date) {
//	tmp duplicates i stream input
	std::string tmp;
//	Get current posistion
	int len = i.tellg();
//	Copy input in tmp string
	std::getline(i, tmp);
	tmp = std::string(tmp, 1);
//	Cut off date from tmp
	tmp = std::string(tmp, 0, tmp.find(' '));
//	Return to position before getline()
	i.seekg(len ,std::ios_base::beg);
	if (i) {
		char first_delimiter, second_delimiter;
		int y, m, d;
		i >> y >> first_delimiter >> m >> second_delimiter >> d;
		if (!i || (i.peek() != int(' ')) && i.peek() != EOF)
			throw std::invalid_argument("Wrong date format: " + tmp);
		date.SetYear(Year(y));
		date.SetMonth(Month(m));
		date.SetDay(Day(d));
		if (date.GetMonth() < 1 || date.GetMonth() > 12)
			throw std::invalid_argument("Month value is invalid: " + std::to_string(date.GetMonth()));
		else if (date.GetDay() > 31 || date.GetDay() < 1)
			throw std::invalid_argument("Day value is invalid: " + std::to_string(date.GetDay()));

	}
	return i;
}


bool operator<(const Date& lhs, const Date& rhs) {
	int l_days = lhs.GetYear() * 12 * 30 + lhs.GetMonth() * 30 + lhs.GetDay();
	int r_days = rhs.GetYear() * 12 * 30 + rhs.GetMonth() * 30 + rhs.GetDay();
	return l_days < r_days;
}

class Database {
private:
	std::map<Date, std::set<std::string> > db;
public:
	void AddEvent(const Date& date, const std::string& event) {
		if (event.empty()) return;
		db[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const std::string& event) {
		if (event.empty() || db.find(date) == db.end()) return false;
		if (db.at(date).find(event) != db.at(date).end()) {
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
		}
		std::cout << "Deleted " << n << " events" << std::endl;
		return n;
	}

	void Find(const Date& date) const {
		if (db.find(date) != db.end()) {
			for (const std::string &event : db.at(date)) {
				std::cout << event << std::endl;
			}
		}
	}

//	Первый вариант
	void Print() const {
		std::cout << std::setfill('0');
		for (const std::pair<Date, std::set<std::string> > &pair : db) {
			if (pair.second.empty()) continue;
			if (pair.first.GetYear() < 0)
				std::cout << '-' << std::setw(4) << (pair.first.GetYear() * -1) << '-';
			else
				std::cout	<< std::setw(4) << pair.first.GetYear() << '-';
			std::cout 	<< std::setw(2) << pair.first.GetMonth() << '-' \
						<< std::setw(2) << pair.first.GetDay() << ' ';
			std::string events = "";
			for (const std::string &event : db.at(pair.first)) {
				events += event + " ";
			}
			events.erase(events.end() - 1);
			std::cout << events << std::endl;
		}
	}
//	Второй вариант
	void _Print() const {
		std::cout << std::setfill('0');
		for (const std::pair<Date, std::set<std::string> > &pair : db) {
			if (pair.second.empty()) continue;
			for (const std::string &event : db.at(pair.first)) {
				if (pair.first.GetYear() < 0)
					std::cout << '-' << std::setw(4) << (pair.first.GetYear() * -1) << '-';
				else
					std::cout	<< std::setw(4) << pair.first.GetYear() << '-';
				std::cout 	<< std::setw(2) << pair.first.GetMonth() << '-' \
							<< std::setw(2) << pair.first.GetDay() << ' ' << event \
							<< std::endl;
			}
		}
	}
};

void add(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<std::string *>(cmd);
	std::stringstream s(*command);
	std::string action;
	Date date;
	std::string event;
	s >> action;
	s >> date;
	s >> event;

	database->AddEvent(date, event);
}
void del(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<std::string *>(cmd);
	std::stringstream s(*command);
	std::string action;
	Date date;
	std::string event;
	s >> action;
	s >> date;
	if (s || s.peek() != EOF) {
		s >> event;
		database->DeleteEvent(date, event);
	} else {
		database->DeleteDate(date);
	}

}
void find(void *db, void *cmd){
	Database *database = static_cast<Database *>(db);
	std::string *command = static_cast<std::string *>(cmd);
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
	if (action.empty()) return false;
	if (commands.find(action) == commands.end()) {
		std::cout << "Unknown command: " << command << std::endl;
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