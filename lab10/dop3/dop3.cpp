#include <iostream>
#include <stdarg.h>

using namespace std;

void function(int* arr, int l, int r, int n) {
	if (l == r) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
	for (int i = l; i <= r; i++) {
		swap(arr[l], arr[i]);
		function(arr, l + 1, r, n);
		swap(arr[l], arr[i]);
	}
}
void rearrangement(int a, ...) {
	int* arr = new int[a];

	va_list factor;
	va_start(factor, a);
	for (int i = 0; i < a; i++) {
		arr[i] = va_arg(factor,int);
	}
	va_end(factor);
	
	function(arr, 0, a - 1, a);
	delete[] arr;
}

int main() {
	rearrangement(4, 1, 2, 3, 4);
	return 0;
}