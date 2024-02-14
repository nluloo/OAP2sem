#include <iostream>
#include <cstdarg>

int mn(int size, ...);

using namespace std;

int main() {

	cout << mn(8, 3, 5, 1, -10, 2, 4, 6, 32);

	return 0;
}

int mn(int size, ...) {
	va_list arrSize;
	va_start(arrSize, size);
	int min = va_arg(arrSize, int);
	for (int i = 1; i < size; i++) {
		int number = va_arg(arrSize, int);
		if(min > number)
			min = number;
	}
	va_end(arrSize);
	return min;
}