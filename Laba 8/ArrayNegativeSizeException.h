#pragma once
#include "Exception.h"

class ArrayNegativeSizeException : Exception {
	int size;
public:
	ArrayNegativeSizeException(int _size) : Exception("Negative array size") {
		size = _size;
	}
	int getSize() {
		return size;
	}
	friend std::ostream& operator << (std::ostream& out, ArrayNegativeSizeException e) {
		out << e.getExceptionName() << " (size=" << e.getSize() << ")";
		return out;
	}
};
