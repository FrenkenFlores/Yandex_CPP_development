#include <map>
#include <iostream>

void change_capital(const std::string & country_name, const std::string & capital_name, std::map<std::string, std::string> &countries) {
	if (countries.count(country_name) == 0) {
		std::cout << "Introduce new country " << country_name << " with capital " << capital_name << std::endl;
		countries[country_name] = capital_name;
	} else if (countries.find(country_name) != countries.end() && countries[country_name] == capital_name) {
		std::cout << "Country " << country_name << " hasn't changed its capital" << std::endl;
	} else {
		std::cout << "Country " << country_name << " has changed its capital from " << countries[country_name] << " to " << capital_name << std::endl;
		countries[country_name] = capital_name;
	}
}

void dump(std::map<std::string, std::string> &countries) {
	if (countries.size() == 0) {
		std::cout << "There are no countries in the world" << std::endl;
		return;
	}
	std::map<std::string, std::string>::iterator it = countries.begin();
	for (int i = 0; i < countries.size() - 1; i++) {
		std::cout << it->first << "/" << it->second << " ";
		++it;
	}
	std::cout << it->first << "/" << it->second << std::endl;
}

void rename(const std::string &old_country, const std::string &new_country, std::map<std::string, std::string> &countries) {
	if (countries.find(old_country) == countries.end() || new_country == old_country || countries.find(new_country) != countries.end()) {
		std::cout << "Incorrect rename, skip" << std::endl;
		return;
	}
	std::cout << "Country " << old_country << " with capital " << countries[old_country] <<
		 " has been renamed to " << new_country << std::endl;
	countries[new_country] = countries[old_country];
	countries.erase(old_country);
}

void about(const std::string & country_name,std::map<std::string, std::string> &countries) {
	if (countries.find(country_name) == countries.end()) {
		std::cout << "Country " << country_name << " doesn't exist" << std::endl;
		return;
	}
	std::cout << "Country " << country_name << " has capital " << countries[country_name] << std::endl;
}

void launch_command(std::string com[], std::map<std::string, std::string> &countries) {
	if (com[0].find("CHANGE_CAPITAL") != std::string::npos)
		change_capital(com[1], com[2], countries);
	else if (com[0].find("RENAME") != std::string::npos)
		rename(com[1], com[2], countries);
	else if (com[0].find("ABOUT") != std::string::npos)
		about(com[1], countries);
	else if (com[0].find("DUMP") != std::string::npos)
		dump(countries);
}

void parse_line(std::map<std::string, std::string> &countries) {
	std::string com[3];
	int j = 0;
	int com_size;
	std::cin >> com[j++];
	if (com[0] == "CHANGE_CAPITAL" || com[0] == "RENAME")
		com_size = 3;
	else if (com[0] == "ABOUT")
		com_size = 2;
	else if (com[0] == "DUMP")
		com_size = 1;
	while (j < com_size)
		std::cin >> com[j++];
	launch_command(com, countries);
}

int main() {
	int nbr;
	std::map<std::string, std::string> countries;
	std::cin >> nbr;
	while (nbr >= 0) {
		parse_line(countries);
		nbr--;
	}
	return EXIT_SUCCESS;
}
