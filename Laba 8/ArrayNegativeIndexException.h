#pragma once
#include "Exception.h"

class ArrayNegativeIndexException : Exception {
	int index;
public:
	ArrayNegativeIndexException(int _index) : Exception("Negative array index") {
		index = _index;
	}
	int getIndex() {
		return index;
	}
	friend std::ostream& operator << (std::ostream& out, ArrayNegativeIndexException e) {
		out << e.getExceptionName() << " (index=" << e.getIndex() << ")";
		return out;
	}
};
