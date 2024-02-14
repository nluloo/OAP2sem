#include <iostream>
#include <cmath>

double f(double x) {

	double y = pow(x, 3) + x - 4;

	return y;
}

double f2(double x) {

	double y = exp(x) - 4;

	return y;
}

double yravn1(double a, double b, double e) {

	double x;

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f(x) * f(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	return x;

}
double yravn2(double a, double b, double e) {

	double x;

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (f2(x) * f2(a) <= 0) {
			b = x;
		}
		else {
			a = x;
		}
	}
	return x;

}

int main() {
	setlocale(LC_ALL, "ru");
	const double e = 0.001;
	double a, b;

	std::cin >> a >> b;

	double (*operation)(double, double, double);

	double result;

	operation = yravn1;
	result = operation(a, b, e);

	std::cout << result << std::endl;

	operation = yravn2;
	result = operation(a, b, e);

	std::cout << result;

	return 0;
}