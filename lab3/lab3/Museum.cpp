#include "Museum.h"

using namespace std;

int Museum::calculateOffset(string k1, string k2)
{
	return getNumericKey(k1) - getNumericKey(k2);
}
int Museum::getNumericKey(string key) {
	int result = 0;

	int position = 0;
	for (int i = key.length() - 1; i >= 0; i--) {
		result += key[i] * pow(10, key.length() - i);
	}

	return result;
}

Museum::Museum()
{
}

Museum::Museum(string key, string name, string type, string location, int year)
{
	this->key = key;
	this->name = name;
	this->type = type;
	this->location = location;
	this->year = year;
}
string Museum::getKey() const {
	return key;
}
string Museum::getName() const {
	return name;
}
string Museum::getType() const {
	return type;
}
string Museum::getLocation() const {
	return location;
}
int Museum::getYear() const {
	return year;
}

int Museum::compare(const Museum& item) const {
	return compare(item.getKey());
}
int Museum::compare(string key) const {
	if (getKey() > key)
		return 1;
	else if (getKey() < key)
		return -1;
	return 0;
}



ostream& operator<<(ostream& out, const Museum& item)
{
	return out << setw(7) << item.key << setw(45) << item.name << setw(20) << item.type << setw(35) << item.location << setw(7) << item.year << "\n";
}

ostream& operator<<(ostream& out, const vector<Museum>& items)
{
	for (int i = 0; i < items.size(); i++) {
		out << setw(3) << i << items[i];
	}
	return out;
}

bool operator==(string key, const Museum& item)
{
	return item.getKey() == key;
}
bool Museum::operator==(const Museum& right) const
{
	return this->getKey() == right.getKey();
}
bool Museum::operator==(string& key) const
{
	return this->getKey() == key;
}


bool operator!=(string& key, const Museum& item)
{
	return key != item.getKey();
}
bool Museum::operator!=(const Museum& right) const
{
	return this->getKey() != right.getKey();
}
bool Museum::operator!=(string& key) const
{
	return this->getKey() != key;
}


bool operator>(string& key, const Museum& item)
{
	return key > item.getKey();
}
bool Museum::operator>(const Museum& right) const
{
	return this->getKey() > right.getKey();
}
bool Museum::operator>(string& key) const
{
	return this->getKey() > key;
}

bool operator>=(string& key, const Museum& item)
{
	return key >= item.getKey();
}
bool Museum::operator>=(const Museum& right) const
{
	return this->getKey() >= right.getKey();
}
bool Museum::operator>=(string& key) const
{
	return this->getKey() >= key;
}


bool operator<(string& key, const Museum& item)
{
	return key < item.getKey();
}
bool Museum::operator<(const Museum& right) const
{
	return this->getKey() < right.getKey();
}
bool Museum::operator<(string& key) const
{
	return this->getKey() < key;
}

bool operator<=(string& key, const Museum& item)
{
	return key <= item.getKey();
}
bool Museum::operator<=(const Museum& right) const
{
	return this->getKey() <= right.getKey();
}
bool Museum::operator<=(string& key) const
{
	return this->getKey() <= key;
}