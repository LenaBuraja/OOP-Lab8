#pragma once
#include <ostream>
#include "ArrayNegativeSizeException.h"
#include "ArrayIndexOutException.h"
#include "ArrayNegativeIndexException.h"
#include "ArrayProductException.h"

template <class T>
class Array {
	int size;
	T* element;
public:
	Array(int size);
	Array(Array<T>& arr);
	void setSize(int newSize);
	void setElement(int index, T value);
	int getSize();
	T& getElement(int index);
	~Array();

	static int compare(Array& arr1, Array& arr2);

	friend std::ostream &operator<< (std::ostream& out, Array& arr) {
		out << "[";
		for (int i = 0; i < arr.getSize(); i++) {
			out << arr.getElement(i);
			if (i != arr.getSize() - 1) {
				out << ", ";
			}
		}
		out << "]";
		return out;
	}
	Array operator* (Array& arr);
	T& operator[] (int index) {
		return getElement(index);
	}
	bool operator== (Array& arr);
	bool operator<= (Array& arr);
};

template <class T>
Array<T>::Array(int size) {
	if (size < 0) {
		throw ArrayNegativeSizeException(size);
	}
	this->size = 0;
	element = new T[this->size];
	setSize(size);
}

template <class T>
Array<T>::Array(Array<T>& arr) : Array(arr.getSize()) {
	for (int i = 0; i < getSize(); i++) {
		setElement(i, arr.getElement(i));
	}
}

template <class T>
void Array<T>::setSize(int newSize) {
	if (newSize < 0) {
		throw ArrayNegativeSizeException(newSize);
	}
	T *newArr = new T[newSize];
	int minSize = (size < newSize) ? size : newSize;
	for (int i = 0; i < minSize; i++) {
		newArr[i] = element[i];
	}
	delete element;
	size = newSize;
	element = newArr;
}

template <class T>
void Array<T>::setElement(int index, T value) {
	if (index >= getSize()) {
		throw ArrayIndexOutException(index, getSize());
	}
	else if (index < 0) {
		throw ArrayNegativeIndexException(index);
	}
	element[index] = value;
}

template <class T>
T& Array<T>::getElement(int index) {
	if (index >= getSize()) {
		throw ArrayIndexOutException(index, getSize());
	}
	else if (index < 0) {
		throw ArrayNegativeIndexException(index);
	}
	return element[index];
}

template <class T>
int Array<T>::getSize() {
	return size;
}

template <class T>
Array<T>::~Array() {
	delete element;
}

template <class T>
int Array<T>::compare(Array& arr1, Array& arr2) {
	int sizeDiff = arr1.getSize() - arr2.getSize();
	if (sizeDiff < 0) {
		return -1;
	}
	else if (sizeDiff > 0) {
		return 1;
	}
	else {
		for (int i = 0; i < arr1.getSize(); i++) {
			int elemDiff = arr1.getElement(i) - arr2.getElement(i);
			if (elemDiff < 0) {
				return -1;
			}
			else if (elemDiff > 0) {
				return 1;
			}
		}
		return 0;
	}
}

template <class T>
Array<T> Array<T>::operator* (Array<T>& arr) {
	if (this->getSize() != arr.getSize()) {
		throw ArrayProductException(this->getSize(), arr.getSize());
	}
	Array result(this->getSize());
	for (int i = 0; i < result.getSize(); i++) {
		result.setElement(i, this->getElement(i) * arr.getElement(i));
	}
	return result;
}

template <class T>
bool Array<T>::operator== (Array<T>& arr) {
	return (compare(*this, arr) == 0);
}

template <class T>
bool Array<T>::operator<= (Array<T>& arr) {
	return (compare(*this, arr) < 1);
}
