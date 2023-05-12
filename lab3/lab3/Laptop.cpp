#include "Laptop.h"

using namespace std;

int Laptop::calculateOffset(string k1, string k2)
{
	return getNumericKey(k1) - getNumericKey(k2);
}
int Laptop::getNumericKey(string key) {
	int result = 0;

	int position = 0;
	for (int i = key.length() - 1; i >= 0; i--) {
		result += key[i] * pow(10, key.length() - i);
	}

	return result;
}

Laptop::Laptop()
{
}

Laptop::Laptop(string key, string name, string year, string price, int ram)
{
	this->key = key;
	this->name = name;
	this->year = year;
	this->price = price;
	this->ram = ram;
}
string Laptop::getKey() const {
	return key;
}
string Laptop::getName() const {
	return name;
}
string Laptop::getYear() const {
	return year;
}
string Laptop::getPrice() const {
	return price;
}
int Laptop::getRam() const {
	return ram;
}

int Laptop::compare(const Laptop& item) const {
	return compare(item.getKey());
}
int Laptop::compare(string key) const {
	if (getKey() > key)
		return 1;
	else if (getKey() < key)
		return -1;
	return 0;
}



ostream& operator<<(ostream& out, const Laptop& item)
{
	return out << setw(7) << item.key << setw(45) << item.name << setw(20) << item.year << setw(35) << item.price << setw(7) << item.ram << "\n";
}

ostream& operator<<(ostream& out, const vector<Laptop>& items)
{
	for (int i = 0; i < items.size(); i++) {
		out << setw(3) << i << items[i];
	}
	return out;
}

bool operator==(string key, const Laptop& item)
{
	return item.getKey() == key;
}
bool Laptop::operator==(const Laptop& right) const
{
	return this->getKey() == right.getKey();
}
bool Laptop::operator==(string& key) const
{
	return this->getKey() == key;
}


bool operator!=(string& key, const Laptop& item)
{
	return key != item.getKey();
}
bool Laptop::operator!=(const Laptop& right) const
{
	return this->getKey() != right.getKey();
}
bool Laptop::operator!=(string& key) const
{
	return this->getKey() != key;
}


bool operator>(string& key, const Laptop& item)
{
	return key > item.getKey();
}
bool Laptop::operator>(const Laptop& right) const
{
	return this->getKey() > right.getKey();
}
bool Laptop::operator>(string& key) const
{
	return this->getKey() > key;
}

bool operator>=(string& key, const Laptop& item)
{
	return key >= item.getKey();
}
bool Laptop::operator>=(const Laptop& right) const
{
	return this->getKey() >= right.getKey();
}
bool Laptop::operator>=(string& key) const
{
	return this->getKey() >= key;
}


bool operator<(string& key, const Laptop& item)
{
	return key < item.getKey();
}
bool Laptop::operator<(const Laptop& right) const
{
	return this->getKey() < right.getKey();
}
bool Laptop::operator<(string& key) const
{
	return this->getKey() < key;
}

bool operator<=(string& key, const Laptop& item)
{
	return key <= item.getKey();
}
bool Laptop::operator<=(const Laptop& right) const
{
	return this->getKey() <= right.getKey();
}
bool Laptop::operator<=(string& key) const
{
	return this->getKey() <= key;
}