/**
 * implementation of sequential queue based on array
 * @author zlm
 * @date 2019/2/1
 */
#ifndef __ARRAYQUEUE_H__
#define __ARRAYQUEUE_H__

#include <iostream>
using namespace std;


// 1.definition
const int CAPACITY = 10; 
template <typename T>
class ArrQueue {
public:
	ArrQueue();
	~ArrQueue();

	void push(T data);
	T pop(); // delete head element
	T front();
	int getSize();
	bool empty();
private:
	T *arr;
	int length; // current number of elements
};

// 2. implementation
template <typename T>
ArrQueue<T>::ArrQueue() {
	// allocate memory
	arr = new T[CAPACITY];
}

template <typename T>
ArrQueue<T>::~ArrQueue() {
	if (arr != nullptr) {
		delete[] arr;
		arr = nullptr;
	}
}

template <typename T>
void ArrQueue<T>::push(T data) {
	// push data to the rear of arr
	arr[length++] = data;
}

// return head element
template <typename T>
T ArrQueue<T>::front() {
	return arr[0];
}

// delete and return the rear element
T ArrQueue<T>::pop() {
	T res = arr[0];
	--length;
	for (int i = 0; i < length-1; i++) 
		arr[i] = arr[i+1];
	return res;
}

template <typename T>
int ArrQueue<T>::getSize() {
	return length;
}

template <typename T>
bool ArrQueue<T>::empty() {
	return length == 0;
}

#endif
