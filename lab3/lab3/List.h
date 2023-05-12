#pragma once
#include "typedefs.h"

template<typename T>
struct ListOne {
	T data;
	ListOne* next;
};

template<typename T>
class List {
	ListOne<T>* strPtr;

public:
	List() {
		this->strPtr = nullptr;
	}

	void iterate(iteratorCallback<T> callback) {
		ListOne<T>* curPtr = strPtr;
		while (curPtr != nullptr) {
			callback(&(curPtr->data));
			curPtr = curPtr->next;
		}
	}

	template <typename K>
	T* search(K& item) {
		ListOne<T>* curPtr = strPtr;
		while (curPtr != nullptr) {
			if (curPtr->data == item)
				return &(curPtr->data);
			curPtr = curPtr->next;
		}
		return nullptr;
	}

	//вставка в начало
	ListOne<T>* prepend(T& data) {
		ListOne<T>* newPtr = new ListOne<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = data;
		newPtr->next = strPtr;
		strPtr = newPtr;
		return newPtr;
	}
	//вставка в определенную позицию
	ListOne<T>* insert(ListOne<T>* after, T& data) {
		ListOne<T>* newPtr = new ListOne<T>;
		newPtr->data = data;
		ListOne<T>* curPtr = after->next;
		newPtr->next = curPtr;
		after->next = newPtr;
		return newPtr;
	}
	//вставка в конец
	ListOne<T>* append(T& data) {
		ListOne<T>* newPtr = new ListOne<T>;
		if (newPtr == nullptr)
			return nullptr; 
		newPtr->data = data;
		ListOne<T>* curPtr = strPtr;
		ListOne<T>* nextPtr = curPtr->next;
		while (nextPtr != nullptr) {
			curPtr = nextPtr;
			nextPtr = nextPtr->next;
		}
		curPtr->next = newPtr;
		newPtr->next = nullptr;
		return newPtr;
	}
	void deleteNode(T& data) {
		if (strPtr == nullptr)
			return;
		ListOne<T>* curPtr = nullptr, * previousPtr = nullptr, * tempPtr = nullptr;
		if (strPtr->data == data) {
			tempPtr = strPtr;
			strPtr = strPtr->next;
			delete tempPtr;
			return;
		}
		curPtr = strPtr->next;
		previousPtr = strPtr;
		while (curPtr != nullptr) {
			if (curPtr->data == data) {
				tempPtr = curPtr;
				previousPtr->next = curPtr->next;
				delete tempPtr;
				return;
			}
			previousPtr = curPtr;
			curPtr = curPtr->next;
		}
	}
	void deleteNode(ListOne<T>& data) {
		deleteNode(data.data);
	}

	void clear() {
		ListOne<T>* curPtr = strPtr;
		ListOne<T>* temp;
		while (curPtr != nullptr) {
			temp = curPtr;
			curPtr = curPtr->next;
			delete temp;
		}
		*curPtr = nullptr;
	}
};