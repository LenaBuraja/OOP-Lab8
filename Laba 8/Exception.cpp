#include "Exception.h"
#include <cstring>

Exception::Exception() : Exception("No description") {

}

Exception::Exception(char* _description) {
	description = new char[std::strlen(_description) + 1];
	strcpy(description, _description);
}

Exception::~Exception() {
	delete description;
}

char* Exception::getExceptionName() {
	return description;
}

std::ostream& operator << (std::ostream& out, Exception e) {
	out << "Exception: " << e.description;
	return out;
}
