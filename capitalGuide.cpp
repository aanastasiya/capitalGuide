#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	map<string, string> countryCapitals;

	int commands;
	cin >> commands;

	string command;
	for (int i = 0; i < commands; i++) {
		cin >> command;

		if (command == "CHANGE_CAPITAL") {
			string country, newCapital;
			cin >> country >> newCapital;

			if (countryCapitals.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << newCapital << endl;
			}
			else if (countryCapitals[country] == newCapital) {
				cout << "Country " << country << " hasn't changed its capital" << endl;
			}
			else if (countryCapitals[country] != newCapital) {
				cout << "Country " << country << " has changed its capital from "
						<< countryCapitals[country] << " to " << newCapital << endl;
			}
			countryCapitals[country] = newCapital;
		}
		else if (command == "RENAME") {
			string oldCountryName, newCountryName;
			cin >> oldCountryName >> newCountryName;

			if (oldCountryName == newCountryName || countryCapitals.count(oldCountryName) == 0
					|| countryCapitals.count(newCountryName) != 0) {
				cout << "Incorrect rename, skip" << endl;
			}
			else {
				cout << "Country " << oldCountryName << " with capital " << countryCapitals[oldCountryName]
						<< " has been renamed to " << newCountryName << endl;
				countryCapitals[newCountryName] = countryCapitals[oldCountryName];
				countryCapitals.erase(oldCountryName);
			}
		}
		else if (command == "ABOUT") {
			string country;
			cin >> country;

			if (countryCapitals.count(country) == 0)
				cout << "Country " << country << " doesn't exist" << endl;
			else
				cout << "Country " << country << " has capital " << countryCapitals[country] << endl;
		}
		else if (command == "DUMP") {
			if (countryCapitals.empty())
				cout << "There are no countries in the world" << endl;
			else {
				for (const auto& item : countryCapitals)
					cout << item.first << "/" << item.second << " ";
				cout << endl;
			}
		}
	}

	return 0;
}
