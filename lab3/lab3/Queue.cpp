//#include "Queue.h"
//
//template<typename T>
//void Queue<T>::enqueue(T value)
//{
//	QUEUENODEPTR<T> newPtr = new QUEUENODE<T>;
//	if (newPtr == nullptr) 
//		return;
//	newPtr->data = value;
//	newPtr->nextPtr = nullptr;
//	if (isEmpty(headPtr))
//		headPtr = newPtr;
//	else
//		tailPtr->nextPtr = newPtr;
//	tailPtr = newPtr;
//}
//template<typename T>
//T Queue<T>::dequeue() {
//	T value = headPtr->data;
//	QUEUENODEPTR<T> tempPtr = *headPtr;
//	headPtr = *headPtr->nextPtr;
//	if (headPtr == nullptr)
//		tailPtr = nullptr;
//	free(tempPtr);
//	return value;
//}
//
//template<typename T>
//T Queue<T>::peek() {
//	T value = headPtr->data;
//	return value;
//}
//
//template<typename T>
//void Queue<T>::isEmpty(QUEUENODEPTR<T> headPtr) {
//	return headPtr == nullptr;
//}
//
//template<typename T>
//void Queue<T>::iterate(void(*callback)(T* item))
//{
//	QUEUENODEPTR<T> currentPtr = headPtr;
//	while (currentPtr != nullptr) {
//		callback(currentPtr->data);
//		currentPtr = currentPtr->nextPtr;
//	}
//}
