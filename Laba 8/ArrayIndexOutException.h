#pragma once
#include "Exception.h"

class ArrayIndexOutException : Exception {
	int index;
	int size;
public:
	ArrayIndexOutException(int _index, int _size) : Exception("Index out of array") {
		index = _index;
		size = _size;
	}
	int getIndex() {
		return index;
	}
	int getSize() {
		return size;
	}
	friend std::ostream& operator << (std::ostream& out, ArrayIndexOutException e) {
		out << e.getExceptionName() << " (index=" << e.getIndex() << "; size=" << e.getSize() << ")";
		return out;
	}
};
