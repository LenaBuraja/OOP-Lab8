#include "Array.h"
#include <iostream>
#include <ctime>
#include <cassert>

template <class T>
Array<T> minimum(Array<T> arr, T min) {
	int size = 0;
	Array<T> result(arr.getSize());
	for (int i = 0; i < arr.getSize(); i++) {
		T elem = arr.getElement(i);
		if (elem < min) {
			result.setElement(size, elem);
			size++;
		}
	}
	result.setSize(size);
	return result;
}

int main() {
	srand(time(0));

	try {
		Array<int>arri(-5); // 5 -> -20
		for (int i = 0; i < arri.getSize(); i++) {
			arri.setElement(i, rand() % 100);
		}
		//arri.setSize(-2);
		std::cout << arri << std::endl;
		std::cout << minimum(arri, 50) << std::endl;
		//std::cout << arri[30] << std::endl;
		//arri[-5] = 8;

		{
			Array<int>arrp(5); // 5 -> 10
			for (int i = 0; i < arrp.getSize(); i++) {
				arrp.setElement(i, rand() % 100);
			}
			std::cout << arri << " * " << arrp << " = " << arri * arrp << std::endl;
		}

		arri.setSize(6);
		assert(arri.getSize() == 5);
	}
	catch (ArrayNegativeSizeException e) {
		std::cout << e << std::endl;
	}
	catch (ArrayIndexOutException e) {
		std::cout << e << std::endl;
	}
	catch (ArrayNegativeIndexException e) {
		std::cout << e << std::endl;
	}
	catch (ArrayProductException e) {
		std::cout << e << std::endl;
	}
	return 0;
}
