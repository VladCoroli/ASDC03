#pragma once
#include "typedefs.h"

template<typename T>
struct StackNode {
	T data;
	struct StackNode* nextPtr;
};

template<typename T>
class Stack {
	StackNode<T>* top;

public:
	Stack() {
		this->top = nullptr;
	}

	void push(T data) {
		StackNode<T>* newPtr = new StackNode<T>;
		if (newPtr == nullptr)
			return;
		newPtr->data = data;
		newPtr->nextPtr = top;
		top = newPtr;
	}

	T pop() {
		if (top == nullptr)
			return NULL;
		T temp = top->data;
		StackNode<T>* ptop = top;
		top = top->nextPtr;
		delete ptop;
		return temp;
	}

	T peek() {
		return *top->data;
	}

	template<typename K>
	T* search(K &item) {
		StackNode<T>* currentPtr = top;
		while (currentPtr != nullptr) {
			if (currentPtr->data == item)
				return &(currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		return nullptr;
	}

	void iterate(iteratorCallback<T> callback) {
		StackNode<T>* currentPtr = top;
		while (currentPtr != nullptr) {
			callback(&(currentPtr->data));
			currentPtr = currentPtr->nextPtr;
		}
	}
};