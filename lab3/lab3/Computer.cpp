#include "Computer.h"

using namespace std;

int Computer::calculateOffset(string k1, string k2)
{
	return getNumericKey(k1) - getNumericKey(k2);
}
int Computer::getNumericKey(string key) {
	int result = 0;

	int position = 0;
	for (int i = key.length() - 1; i >= 0; i--) {
		result += key[i] * pow(10, key.length() - i);
	}

	return result;
}

Computer::Computer()
{
}

Computer::Computer(string key, string name, string type, string location, int year)
{
	this->key = key;
	this->name = name;
	this->type = type;
	this->location = location;
	this->year = year;
}
string Computer::getKey() const {
	return key;
}
string Computer::getName() const {
	return name;
}
string Computer::getType() const {
	return type;
}
string Computer::getLocation() const {
	return location;
}
int Computer::getYear() const {
	return year;
}

int Computer::compare(const Computer& item) const {
	return compare(item.getKey());
}
int Computer::compare(string key) const {
	if (getKey() > key)
		return 1;
	else if (getKey() < key)
		return -1;
	return 0;
}



ostream& operator<<(ostream& out, const Computer& item)
{
	return out << setw(7) << item.key << setw(45) << item.name << setw(20) << item.type << setw(35) << item.location << setw(7) << item.year << "\n";
}

ostream& operator<<(ostream& out, const vector<Computer>& items)
{
	for (int i = 0; i < items.size(); i++) {
		out << setw(3) << i << items[i];
	}
	return out;
}

bool operator==(string key, const Computer& item)
{
	return item.getKey() == key;
}
bool Computer::operator==(const Computer& right) const
{
	return this->getKey() == right.getKey();
}
bool Computer::operator==(string& key) const
{
	return this->getKey() == key;
}


bool operator!=(string& key, const Computer& item)
{
	return key != item.getKey();
}
bool Computer::operator!=(const Computer& right) const
{
	return this->getKey() != right.getKey();
}
bool Computer::operator!=(string& key) const
{
	return this->getKey() != key;
}


bool operator>(string& key, const Computer& item)
{
	return key > item.getKey();
}
bool Computer::operator>(const Computer& right) const
{
	return this->getKey() > right.getKey();
}
bool Computer::operator>(string& key) const
{
	return this->getKey() > key;
}

bool operator>=(string& key, const Computer& item)
{
	return key >= item.getKey();
}
bool Computer::operator>=(const Computer& right) const
{
	return this->getKey() >= right.getKey();
}
bool Computer::operator>=(string& key) const
{
	return this->getKey() >= key;
}


bool operator<(string& key, const Computer& item)
{
	return key < item.getKey();
}
bool Computer::operator<(const Computer& right) const
{
	return this->getKey() < right.getKey();
}
bool Computer::operator<(string& key) const
{
	return this->getKey() < key;
}

bool operator<=(string& key, const Computer& item)
{
	return key <= item.getKey();
}
bool Computer::operator<=(const Computer& right) const
{
	return this->getKey() <= right.getKey();
}
bool Computer::operator<=(string& key) const
{
	return this->getKey() <= key;
}