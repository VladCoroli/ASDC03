#pragma once
#include "typedefs.h"

template <typename T>
struct ListCircle {
	T data;
	ListCircle* last;
	ListCircle* next;
};

template<typename T> using PListCircle = ListCircle<T>*;

template <typename T>
class CList {
	ListCircle<T>* head;
	ListCircle<T>* tail;

	void updateLoop() {
		if (head != nullptr && tail != nullptr) {
			head->last = tail;
			tail->next = head;
		}
	}

public:
	CList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void iterateForward(iteratorCallback<T> callback) {
		iterateForward(head, callback);
	}
	void iterateForward(ListCircle<T>* start, iteratorCallback<T> callback) {
		ListCircle<T>* current = start;
		if (current == nullptr)
			return;
		do {
			callback(&(current->data));
			current = current->next;
		} while (current != start);
	}
	void iterateBackward(iteratorCallback<T> callback) {
		iterateBackward(tail, callback);
	}
	void iterateBackward(ListCircle<T>* start, iteratorCallback<T> callback) {
		ListCircle<T>* current = start;
		if (current == nullptr)
			return;
		do {
			callback(&(current->data));
			current = current->last;
		} while (current != start);
	}

	template <typename K>
	T* searchForward(K& item) {
		ListCircle<T>* current = head;
		if (current == nullptr)
			return nullptr;
		do {
			if (current->data == item)
				return &(current->data);
			current = current->next;
		} while (current != head);
		return nullptr;
	}
	template <typename K>
	T* searchBackward(K& item) {
		ListCircle<T>* current = tail;
		if (current == nullptr)
			return nullptr;
		do {
			if (current->data == item)
				return &(current->data);
			current = current->last;
		} while (current != tail);
		return nullptr;
	}

	//вставка в начало
	ListCircle<T>* prepend(T item) {
		ListCircle<T>* newPtr = new ListCircle<T>;
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
		updateLoop();
		return newPtr;
	}
	//вставка в конец
	ListCircle<T>* append(T item) {
		ListCircle<T>* newPtr = new ListCircle<T>;
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
		updateLoop();
		return newPtr;
	}
	ListCircle<T>* insertBefore(PListCircle<T>& source, T item) {
		if (source->last == nullptr)
			return prepend(item);
		ListCircle<T>* newPtr = new ListCircle<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		ListCircle<T>* temp = source->last;
		source->last = newPtr;
		newPtr->next = source;
		temp->next = newPtr;
		newPtr->last = temp;
		updateLoop();
		return newPtr;
	}
	ListCircle<T>* insertAfter(PListCircle<T>& source, T item) {
		if (source->next == nullptr)
			return append(item);
		ListCircle<T>* newPtr = new ListCircle<T>;
		if (newPtr == nullptr)
			return nullptr;
		newPtr->data = item;
		ListCircle<T>* temp = source->next;
		source->next = newPtr;
		newPtr->last = source;
		temp->last = newPtr;
		newPtr->next = temp;
		updateLoop();
		return newPtr;
	}
	void deleteNode(ListCircle<T>* item) {
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
			ListCircle<T>* next = item->next;
			ListCircle<T>* last = item->last;
			next->last = last;
			last->next = next;
			delete item;
		}
		updateLoop();
	}
};