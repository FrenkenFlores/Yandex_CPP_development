#include <iostream>
#include "names3.cpp"
using namespace std;

int main() {
	Person person("Polina", "Sergeeva", 1960);
	{
		cout << person.GetFullNameWithHistory(1959) << endl;
		cout << person.GetFullNameWithHistory(1960) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	{
		cout << person.GetFullNameWithHistory(1965) << endl;
		cout << person.GetFullNameWithHistory(1967) << endl;
	}

	return 0;
}