#pragma once
#include "Exception.h"

class ArrayProductException : Exception {
	int size1;
	int size2;
public:
	ArrayProductException(int _size1, int _size2) : Exception("Different sizes of the multiplied arrays") {
		size1 = _size1;
		size2 = _size2;
	}
	int getFirstSize() {
		return size1;
	}
	int getSecondSize() {
		return size2;
	}
	friend std::ostream& operator << (std::ostream& out, ArrayProductException e) {
		out << e.getExceptionName() << " (sizes are: " << e.getFirstSize() << "; " << e.getSecondSize() << ")";
		return out;
	}
};
