#include <iostream>

using namespace std;


float function(float x, int n) {
	if (n == 0 || n == 1)
		return n == 0 ? 1 : x;
	return function(x, n - 1) * x / n;
}

int main() {
	cout << function(100, 3) << endl;
	return 0;
}