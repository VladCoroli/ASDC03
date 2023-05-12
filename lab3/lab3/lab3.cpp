#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Laptop.h"
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include "DList.h"
#include "CList.h"
#include "Tree.h"

using namespace std;

const char delimiter = ' ';
const int columns = 5;
const string _path = "C:\\txt3.txt";
string search_key = "24";

vector<Laptop> read(const string& path = _path);
vector<string> split(const string& source);

void showFound(Laptop* item, const char *message);
void separator(const char *message);

void print(Laptop*item);

int main()
{
	vector<Laptop> items = read();

	separator("LINKED LIST");
	List<Laptop> list;
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		list.prepend(*i);
	}
	list.iterate(print);
	showFound(list.search(search_key), "linked list");

	separator("DOUBLE LINKED LIST");
	DList<Laptop> dlist;
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		dlist.prepend(*i);
	
	}
	dlist.iterateForward(print);
	showFound(dlist.searchForward(search_key), "double linked list");

	separator("RING LINKED LIST");
	CList<Laptop> clist;
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		clist.prepend(*i);
		
	}
	clist.iterateForward(print);
	showFound(clist.searchForward(search_key), "ring linked list");

	separator("STACK");
	Stack<Laptop> stack;
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		stack.push(*i);
		
	}
	stack.iterate(print);
	showFound(stack.search(search_key), "stack");

	separator("QUEUE");
	Queue<Laptop> queue;
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		queue.enqueue(*i);

	}
	queue.iterate(print);
	showFound(queue.search(search_key), "queue");

	Tree<Laptop> tree;
	separator("TREE");
	for (vector<Laptop>::iterator i = items.begin(); i != items.end(); i++) {
		tree.add(*i);
		
	}
	separator("INORDER");
	tree.inorder(print);
	showFound(tree.search(search_key), "tree");
	separator("PREORDER");
	tree.preorder(print);
	showFound(tree.search(search_key), "tree");
	separator("POSTORDER");
	tree.postorder(print);
	showFound(tree.search(search_key), "tree");
}

void print(Laptop* item) {
	cout << *item;
}
void separator(const char *title) {
	cout << endl;
	for (int i = 0; i < 40; i++)
		cout << "=";
	cout << " " << title << " ";
	for (int i = 0; i < 40; i++)
		cout << "=";
	cout << endl << endl;
}

void showFound(Laptop* item, const char* message) {
	if (item == nullptr) {
		cout << "Item not found in " << message;
	}
	else cout << "Found in " << message << endl << *item;
}

vector<Laptop> read(const string& path) {
	vector<Laptop> museums;
	string name, type;
	ifstream in(path);
	if (!in.is_open()) {
		throw "Unable to read file";
	}

	string line;
	while (getline(in, line)) {
		vector<string> parts = split(line);
		if (parts.size() != columns)
			continue;
		museums.push_back(Laptop(parts[0], parts[1], parts[2], parts[3], stoi(parts[4])));
	}
	return museums;
}
vector<string> split(const string& source)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(source);
	while (getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}