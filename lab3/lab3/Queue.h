#pragma once
#include "typedefs.h"

template<typename T>
struct QueueNode {
	T data;
	struct QueueNode* nextPtr;
};

template<typename T> using QUEUENODE = QueueNode<T>;
template<typename T> using QUEUENODEPTR = QUEUENODE<T>*;

template<typename T>
class Queue {
	QUEUENODEPTR<T> headPtr;
	QUEUENODEPTR<T> tailPtr;

	int isEmpty(QUEUENODEPTR<T> headPtr) {
		return headPtr == nullptr;
	}
	
public:
	Queue() {
		this->headPtr = nullptr;
		this->tailPtr = nullptr;
	}

	void enqueue(T value) {
		QUEUENODEPTR<T> newPtr = new QUEUENODE<T>;
		if (newPtr == nullptr)
			return;
		newPtr->data = value;
		newPtr->nextPtr = nullptr;
		if (isEmpty(headPtr))
			headPtr = newPtr;
		else
			tailPtr->nextPtr = newPtr;
		tailPtr = newPtr;
	}
	T dequeue() {
		T value = headPtr->data;
		QUEUENODEPTR<T> tempPtr = *headPtr;
		headPtr = *headPtr->nextPtr;
		if (headPtr == nullptr)
			tailPtr = nullptr;
		free(tempPtr);
		return value;
	}
	T peek() {
		return headPtr->data;
	}

	template<typename K>
	T* search(K& item) {
		QUEUENODEPTR<T> currentPtr = headPtr;
		while (currentPtr != nullptr) {
			if (currentPtr->data == item)
				return &(currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}
		return nullptr;
	}

	void iterate(iteratorCallback<T> callback) {
		QUEUENODEPTR<T> currentPtr = headPtr;
		while (currentPtr != nullptr) {
			callback(&(currentPtr->data));
			currentPtr = currentPtr->nextPtr;
		}
	}
};
