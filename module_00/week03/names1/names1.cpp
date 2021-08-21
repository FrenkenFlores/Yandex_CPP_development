#include <string>
#include <map>

using namespace std;

struct name {
	string first_name;
	string last_name;
};

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		// If the year is negative or name already changed this year
		if (year < 0 || (data[year].first_name.size() && data.count(year)))
			return ;
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
		// If the year is negative or name already changed this year
		if (year < 0 || (data[year].last_name.size() && data.count(year)))
			return ;
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
	string GetFullName(int year) {
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
private:
	map<int, struct name, greater<int> > data;
};