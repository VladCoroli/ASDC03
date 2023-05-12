#include <codecvt>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma once
class Museum
{
	string key;
	string name;
	string type;
	string location;
	int year;

	static int calculateOffset(string k1, string k2);
	static int getNumericKey(string key);

public:
	Museum();
	Museum(string key, string name, string type, string location, int year);

	string getKey() const;
	string getName() const;
	string getType() const;
	string getLocation() const;
	int getYear() const;

	int compare(const Museum& item) const;
	int compare(string key) const;

	friend ostream& operator<<(ostream& out, const Museum& item);
	friend ostream& operator<<(ostream& out, const vector<Museum>& items);

	bool operator==(const Museum& right) const;
	bool operator==(string& key) const;
	friend bool operator==(string key, const Museum& item);

	bool operator!=(const Museum& right) const;
	bool operator!=(string& key) const;
	friend bool operator!=(string& key, const Museum& item);

	bool operator>(const Museum& right) const;
	bool operator>(string& key) const;
	friend bool operator>(string& key, const Museum& item);

	bool operator>=(const Museum& right) const;
	bool operator>=(string& key) const;
	friend bool operator>=(string& key, const Museum& item);

	bool operator<(const Museum& right) const;
	bool operator<(string& key) const;
	friend bool operator<(string& key, const Museum& item);

	bool operator<=(const Museum& right) const;
	bool operator<=(string& key) const;
	friend bool operator<=(string& key, const Museum& item);
};

