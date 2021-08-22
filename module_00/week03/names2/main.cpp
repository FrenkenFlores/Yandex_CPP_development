#include <iostream>
#include "names2.cpp"
using namespace std;

int main() {
	{
		Person person;

		person.ChangeFirstName(1900, "Eugene");
		person.ChangeLastName(1900, "Sokolov");
		person.ChangeLastName(1910, "Sokolov");
		person.ChangeFirstName(1920, "Evgeny");
		person.ChangeLastName(1930, "Sokolov");
		cout << person.GetFullNameWithHistory(1940) << endl;
	}
	{
		Person person;

		person.ChangeFirstName(1965, "Polina");
		person.ChangeLastName(1967, "Sergeeva");
		{
			cout << person.GetFullNameWithHistory(1900) << endl;
			cout << person.GetFullNameWithHistory(1965) << endl;
			cout << person.GetFullNameWithHistory(1990) << endl;
		}

		person.ChangeFirstName(1970, "Appolinaria");
		{
			cout << person.GetFullNameWithHistory(1969) << endl;
			cout << person.GetFullNameWithHistory(1970) << endl;
		}

		person.ChangeLastName(1968, "Volkova");
		{
			cout << person.GetFullNameWithHistory(1969) << endl;
			cout << person.GetFullNameWithHistory(1970) << endl;
		}

		person.ChangeFirstName(1990, "Polina");
		person.ChangeLastName(1990, "Volkova-Sergeeva");
		cout << person.GetFullNameWithHistory(1990) << endl;

		person.ChangeFirstName(1966, "Pauline");
		cout << person.GetFullNameWithHistory(1966) << endl;

		person.ChangeLastName(1960, "Sergeeva");
		{
			cout << person.GetFullNameWithHistory(1960) << endl;
			cout << person.GetFullNameWithHistory(1967) << endl;
		}

		person.ChangeLastName(1961, "Ivanova");
		cout << person.GetFullNameWithHistory(1967) << endl;
	}
	{
		Person person;

		person.ChangeFirstName(1965, "Polina");
		person.ChangeFirstName(1965, "Appolinaria");

		person.ChangeLastName(1965, "Sergeeva");
		person.ChangeLastName(1965, "Volkova");
		person.ChangeLastName(1965, "Volkova-Sergeeva");

		{
			cout << person.GetFullNameWithHistory(1964) << endl;
			cout << person.GetFullNameWithHistory(1965) << endl;
			cout << person.GetFullNameWithHistory(1966) << endl;
		}
	}
	return 0;
}