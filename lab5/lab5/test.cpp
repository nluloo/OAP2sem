#include <iostream> 
using namespace std;
union Utypes
{
	char c;
	int ivalue;
	float fvalue;
	double dvalue;
} mun;

Utypes list[20];

int main()
{
	setlocale(LC_ALL, "Russian");
	mun.c = 'b';
	list[2].c = 'a';
	cout << mun.c << ' ' << list[2].c << endl;
	mun.ivalue = 1990;
	cout << mun.ivalue << endl;
	mun.fvalue = 19.90;
	cout << mun.fvalue << endl;
	mun.dvalue = 987654.32E+13;
	cout << mun.dvalue << endl;

	// ниже приведены операторы некорректного вывода
	cout << mun.c << endl;
	cout << mun.ivalue << endl;
	cout << mun.fvalue << endl;
	cout << mun.dvalue << endl;
	cout << "Размер объединения составляет " << sizeof(Utypes) << " байт.";
	return 0;
}
