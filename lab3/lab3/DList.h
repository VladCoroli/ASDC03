#pragma once
#include "typedefs.h"

template <typename T>
struct ListDouble {
	T data;
	ListDouble* last;
	ListDouble* next;
};

template<typename T> using PListDouble = ListDouble<T>*;

template<typename T>
class DList {
	ListDouble<T>* head;
	ListDouble<T>* tail;

public:
	DList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void iterateForward(iteratorCallback<T> callback) {
		ListDouble<T>* current = head;
		while (current != nullptr) {
			callback(&(current->data));
			current = current->next;
		}
	}
	void iterateBackward(iteratorCallback<T> callback) {
		ListDouble<T>* current = tail;
		while (current != nullptr) {
			callback(&(current->data));
			current = current->last;
		}
	}

	template <typename K>
	T* searchForward(K& item) {
		ListDouble<T>* current = head;
		while (current != nullptr) {
			if (current->data == item)
				return &(current->data);
			current = current->next;
		}
		return nullptr;
	}

	template <typename K>
	T* searchBackward(K& item) {
		ListDouble<T>* current = tail;
		while (current != nullptr) {
			if (current->data == item)
				return &(current->data);
			current = current->last;
		}
		return nullptr;
	}

	//вставка в начало
	ListDouble<T>* prepend(T item) {
		ListDouble<T>* newPtr = new ListDouble<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		newPtr->next = head;
		newPtr->last = nullptr;
		if (head != nullptr)
			head->last = newPtr;
		head = newPtr;
		if (tail == nullptr)
			tail = head;
		return newPtr;
	}
	//вставка в конец
	ListDouble<T>* append(T item) {
		ListDouble<T>* newPtr = new ListDouble<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		newPtr->next = nullptr;
		newPtr->last = tail;
		if (tail != nullptr)
			tail->next = newPtr;
		tail = newPtr;
		if (head == nullptr)
			head = tail;
		return newPtr;
	}
	ListDouble<T>* insertBefore(PListDouble<T>& source, T item) {
		if (source->last == nullptr)
			return prepend(item);
		ListDouble<T>* newPtr = new ListDouble<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		ListDouble<T>* temp = source->last;
		source->last = newPtr;
		newPtr->next = source;
		temp->next = newPtr;
		newPtr->last = temp;
		return newPtr;
	}
	ListDouble<T>* insertAfter(PListDouble<T>& source, T item) {
		if (source->next == nullptr)
			return append(item);
		ListDouble<T>* newPtr = new ListDouble<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		ListDouble<T>* temp = source->next;
		source->next = newPtr;
		newPtr->prev = source;
		temp->prev = newPtr;
		newPtr->next = temp;
		return newPtr;
	}
	void deleteNode(ListDouble<T>* item) {
		if (head == item) {
			head = item->next;
			if (head)
				head->last = nullptr;
			else tail = nullptr;
		}
		else if (tail == item) {
			tail = item->last;
			if (tail)
				tail->next = nullptr;
			else head = nullptr;
		}
		else {
			ListDouble<T>* next = item->next;
			ListDouble<T>* last = item->last;
			next->prev = last;
			last->next = next;
			delete item;
		}
	}
};

