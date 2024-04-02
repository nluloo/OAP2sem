#include <iostream>

using namespace std;


float function(int n, int m) {
	if (n == 0) {
		return 1;
	}
	if (n < m)
		return -1;
	return 2 * function(n-1,m);
}

int main() {
	cout << function(4, 3) << endl;
	return 0;
}