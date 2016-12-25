#pragma once
#include <ostream>

class Exception {
	char* description;
public:
	Exception();
	Exception(char* message);
	~Exception();
	char* getExceptionName();
	friend std::ostream& operator << (std::ostream& out, Exception e);
};
