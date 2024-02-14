#include <iostream>
#include <cstdarg>

int mnArray(int size, ...);

using namespace std;

int main() {


	cout << mnArray(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;
	cout << mnArray(4, 1, 6, 7, 8) << endl;
	cout << mnArray(6, 4, 5, 6, 7, 8, 1) << endl;
	cout << mnArray(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;

	return 0;
}



int mnArray(int size, ...) {
	va_list arrSize;
	va_start(arrSize, size);
	int result = 0;

	for (int i = 0; i < size; i += 2) {
		result += va_arg(arrSize, int) * va_arg(arrSize, int);
	}
	va_end(arrSize);
	return result;
}