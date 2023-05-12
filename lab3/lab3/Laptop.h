#include <codecvt>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#pragma once
class Laptop
{
	string key;
	string name;
	string year;
	string price;
	int ram;

	static int calculateOffset(string k1, string k2);
	static int getNumericKey(string key);

public:
	Laptop();
	Laptop(string key, string name, string year, string price, int ram);

	string getKey() const;
	string getName() const;
	string getYear() const;
	string getPrice() const;
	int getRam() const;

	int compare(const Laptop& item) const;
	int compare(string key) const;

	friend ostream& operator<<(ostream& out, const Laptop& item);
	friend ostream& operator<<(ostream& out, const vector<Laptop>& items);

	bool operator==(const Laptop& right) const;
	bool operator==(string& key) const;
	friend bool operator==(string key, const Laptop& item);

	bool operator!=(const Laptop& right) const;
	bool operator!=(string& key) const;
	friend bool operator!=(string& key, const Laptop& item);

	bool operator>(const Laptop& right) const;
	bool operator>(string& key) const;
	friend bool operator>(string& key, const Laptop& item);

	bool operator>=(const Laptop& right) const;
	bool operator>=(string& key) const;
	friend bool operator>=(string& key, const Laptop& item);

	bool operator<(const Laptop& right) const;
	bool operator<(string& key) const;
	friend bool operator<(string& key, const Laptop& item);

	bool operator<=(const Laptop& right) const;
	bool operator<=(string& key) const;
	friend bool operator<=(string& key, const Laptop& item);
};

