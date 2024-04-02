#include <iostream>
#include <fstream>

using namespace std;
ofstream fileWrite("D:\\labs\\oap1.2\\lab10files\\dop1.txt");
int function(int a, int* arr, int& i ) {
	if (a > 0) {
		function(a - 1, arr, i);
		arr[i] = a;
		i++;
		return a - 1;
	}
}

void swap(int* arr, int l, int r, int n) {

	if (l == r) {
		for (int i = 0; i < 4; i++) {
			fileWrite << arr[i];
		}
		fileWrite << endl;

	}
	for (int i = l; i <= r; i++) {
		swap(arr[l], arr[i]);
		swap(arr, l + 1, r, n);
		swap(arr[l], arr[i]);
	}

}

int main() {
	int* arr = new int[4];
	int i = 0;

	function(4, arr, i);
	swap(arr, 0, 4 - 1, 4);
	fileWrite.close();

	return 0;
}