#include <string>
#include <iostream>
#include <map>
#include <list>

using namespace std;

struct name {
	string first_name;
	string last_name;
};

class Person {
public:
	Person(const string &first_name, const string &last_name, int year) {
		_first_name = first_name;
		_last_name = last_name;
		_year = year;
		struct name n;
		n.first_name = first_name;
		n.last_name = last_name;
		data[year] = n;
	}
	void ChangeFirstName(int year, const string& first_name) {
		// If the year is negative
		if (year < 0 || _year > year)
			return ;
		_first_name = first_name;
		// If last name was added, but the first name was not added yet
		if (data[year].last_name.size() && data.count(year)) {
			data[year].first_name = first_name;
			return ;
		}
		struct name n;
		n.first_name = first_name;
		n.last_name = string();
		data[year]=n;
	}
	void ChangeLastName(int year, const string& last_name) {
		// If the year is negative
		if (year < 0 || _year > year)
			return ;
		_last_name = last_name;
		// If first was name added, but the last name was not added yet
		if (data[year].first_name.size() && data.count(year)) {
			data[year].last_name = last_name;
			return ;
		}
		struct name n;
		n.first_name = string();
		n.last_name = last_name;
		data[year]=n;
	}
	string GetFullName(int year) const {
		if (_year > year)
			return "No person";
		string first_name = string();
		string last_name = string();
		for (pair<int, struct name> item : data) {
			if (item.first <= year) {
				if (item.second.first_name.empty())
					continue;
				first_name = item.second.first_name;
				break;
			}
		}
		for (pair<int, struct name> item : data) {
			if (item.first <= year) {
				if (item.second.last_name.empty())
					continue;
				last_name = item.second.last_name;
				break;
			}
		}
		if (first_name.empty() && last_name.empty())
			return "Incognito";
		else if (first_name.empty() and last_name.size())
			return last_name + " with unknown first name";
		else if (last_name.empty() and first_name.size())
			return first_name + " with unknown last name";
		else
			return first_name + " " + last_name;
	}
	string GetFullNameWithHistory(int year) const{
		if (_year > year)
			return "No person";
		string first_name = string();
		string last_name = string();
		list<string> first_name_history;
		list<string> last_name_history;
		for (pair<int, struct name> item : data) {
			if (item.first <= year) {
				if (item.second.first_name.empty())
					continue;
				first_name_history.push_back(item.second.first_name);
			}
		}
		for (pair<int, struct name> item : data) {
			if (item.first <= year) {
				if (item.second.last_name.empty())
					continue;
				last_name_history.push_back(item.second.last_name);
			}
		}

		// Get the first element and remove it
		if (first_name_history.size()) {
			first_name = first_name_history.front();
			first_name_history.pop_front();
		}
		if (last_name_history.size()) {
			last_name = last_name_history.front();
			last_name_history.pop_front();
		}

		// Create a string with name history
		string first_name_history_string;
		if (first_name_history.size()) {
			string tmp = first_name;
			first_name_history_string += "(";
			while (first_name_history.size()) {
				if (tmp == first_name_history.front() && first_name_history.front().size()) {
					first_name_history.pop_front();
					continue;
				}
				tmp = first_name_history.front();
				first_name_history_string += first_name_history.front();
				first_name_history_string += ", ";
				first_name_history.pop_front();
			}
			if (first_name_history_string.find(',') != std::string::npos)
				first_name_history_string.erase(first_name_history_string.size() - 2, first_name_history_string.size());
			first_name_history_string += ")";
			// If first_name_history_string is empty, it will hold (), then clean it
			if (first_name_history_string.size() == 2)
				first_name_history_string = string();
		}

		string last_name_history_string;
		if (last_name_history.size()){
			string tmp = last_name;
			last_name_history_string += "(";
			while (last_name_history.size()) {
				if (tmp == last_name_history.front() && last_name_history.front().size()) {
					last_name_history.pop_front();
					continue;
				}
				tmp = last_name_history.front();
				last_name_history_string += last_name_history.front();
				last_name_history_string += ", ";
				last_name_history.pop_front();
			}
			if (last_name_history_string.find(',') != std::string::npos)
				last_name_history_string.erase(last_name_history_string.size() - 2, last_name_history_string.size());
			last_name_history_string += ")";
			// If last_name_history_string is empty, it will hold (), then clean it
			if (last_name_history_string.size() == 2)
				last_name_history_string = string();
		}


		if (first_name.empty() && last_name.empty())
			return "Incognito";
		else if (first_name.empty() and last_name.size())
			return last_name + (last_name_history_string.size() ? " " + last_name_history_string : "") + " with unknown first name";
		else if (last_name.empty() and first_name.size())
			return first_name + (first_name_history_string.size() ? " " + first_name_history_string : "") + " with unknown last name";
		else
			return first_name + (first_name_history_string.size() ? " " + first_name_history_string : "") + " " + last_name + (last_name_history_string.size() ? " " + last_name_history_string : "");
	}
private:
	int _year;
	string _first_name;
	string _last_name;
	map<int, struct name, greater<int> > data;
};