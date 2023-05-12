#include <codecvt>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma once
class Computer
{
	string key;
	string name;
	string type;
	string location;
	int year;

	static int calculateOffset(string k1, string k2);
	static int getNumericKey(string key);

public:
	Computer();
	Computer(string key, string name, string type, string location, int year);

	string getKey() const;
	string getName() const;
	string getType() const;
	string getLocation() const;
	int getYear() const;

	int compare(const Computer& item) const;
	int compare(string key) const;

	friend ostream& operator<<(ostream& out, const Computer& item);
	friend ostream& operator<<(ostream& out, const vector<Computer>& items);

	bool operator==(const Computer& right) const;
	bool operator==(string& key) const;
	friend bool operator==(string key, const Computer& item);

	bool operator!=(const Computer& right) const;
	bool operator!=(string& key) const;
	friend bool operator!=(string& key, const Computer& item);

	bool operator>(const Computer& right) const;
	bool operator>(string& key) const;
	friend bool operator>(string& key, const Computer& item);

	bool operator>=(const Computer& right) const;
	bool operator>=(string& key) const;
	friend bool operator>=(string& key, const Computer& item);

	bool operator<(const Computer& right) const;
	bool operator<(string& key) const;
	friend bool operator<(string& key, const Computer& item);

	bool operator<=(const Computer& right) const;
	bool operator<=(string& key) const;
	friend bool operator<=(string& key, const Computer& item);
};
