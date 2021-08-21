#include <iostream>
#include "names1.cpp"
using namespace std;

int main() {
	{
		Person person;

		person.ChangeFirstName(1965, "Polina");
		person.ChangeLastName(1967, "Sergeeva");
		{
			cout << person.GetFullName(1900) << endl;
			cout << person.GetFullName(1965) << endl;
			cout << person.GetFullName(1990) << endl;
		}

		person.ChangeFirstName(1970, "Appolinaria");
		{
			cout << person.GetFullName(1969) << endl;
			cout << person.GetFullName(1970) << endl;
		}

		person.ChangeLastName(1968, "Volkova");
		{
			cout << person.GetFullName(1969) << endl;
			cout << person.GetFullName(1970) << endl;
		}
	}
	{
		Person person;

		int year = 1;
		person.ChangeFirstName(year, std::to_string(year)+"_first");
		person.ChangeLastName(year, std::to_string(year)+"_last");
		std::cout << "year: " << year << '\n';
		std::cout << person.GetFullName(year) << '\n';

		year = 2;
		person.ChangeFirstName(year, std::to_string(year)+"_first");
		person.ChangeLastName(year, std::to_string(year)+"_last");
		std::cout << "year: " << year << '\n';
		std::cout << person.GetFullName(year) << '\n';

		year = 3;
		person.ChangeFirstName(year, std::to_string(2)+"_first");
		person.ChangeLastName(year, std::to_string(2)+"_last");
		std::cout << "year: " << year << '\n';
		std::cout << person.GetFullName(year) << '\n';
	}
	return 0;
}