#include <map>
#include <iostream>

void change_capital(const std::string & country_name, const std::string & capital_name, std::map<std::string, std::string> &countries) {
	if (countries.count(country_name) == 0) {
		std::cout << "Introduce new country " << country_name << " with capital " << capital_name << std::endl;
		countries[country_name] = capital_name;
	} else {
		std::cout << "Country " << country_name << " has changed its capital from " << countries[country_name] << " to " << capital_name << std::endl;
		countries[country_name] = capital_name;
	}
}

void dump(std::map<std::string, std::string> &countries) {
	for (auto i : countries) {
		std::cout << i.first << "/" << i.second << std::endl;
	}
}

void rename(const std::string &old_country, const std::string &new_country, std::map<std::string, std::string> &countries) {
	if (countries.find(old_country) == countries.end()) {
		std::cout << "there is no such country as " << old_country << std::endl;
		return;
	}
	std::cout << "Country " << old_country << " with capital " << countries[old_country] <<
		 " has been renamed to " << new_country << std::endl;
	countries[new_country] = countries[old_country];
	countries.erase(old_country);
}

void about(const std::string & country_name,std::map<std::string, std::string> &countries) {
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

void parse_line(std::string &str, std::map<std::string, std::string> &countries) {
	size_t i = 0;
	size_t j = 0;
	size_t z = 0;
	std::string com[3];
	std::string::iterator it_b = str.begin();
	std::string::iterator it_e = str.end();
	while ((i = str.find(" ")) && i != std::string::npos) {
		str[i] = '\0';
		com[j++] = std::string(it_b, it_b + i - z);
		it_b = str.begin() + i;
		z = i;
	}
	com[j] = std::string(it_b, it_e);
	launch_command(com, countries);
}

int main() {
	int nbr;
	std::string command;
	std::map<std::string, std::string> countries;
	std::cin >> nbr;
	while (nbr >= 0) {
		std::getline(std::cin, command);
		parse_line(command, countries);
		nbr--;
	}
	return EXIT_SUCCESS;
}
