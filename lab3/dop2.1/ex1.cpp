#include <iostream>
#include <fstream>

using namespace std;

int main() {

	char buff[500];
	char word[50];
	int amountWords = 0;
	ifstream FILE1("D:\\labs\\oap1.2\\lab3Files\\dop2.1\\FILE1.txt");
	ofstream FILE2("D:\\labs\\oap1.2\\lab3Files\\dop2.1\\FILE2.txt");

	if (!FILE1.is_open()) {
		cout << "(((";
		return 1;
	}
	else {
		while(!FILE1.eof())
		{
			FILE1.getline(buff, 500);
			if (buff[0] == 'A') {
				FILE2 << buff;
				FILE2 << endl;
			}
		}
	}

	FILE1.close();
	FILE2.close();

	ifstream FILE2read("D:\\labs\\oap1.2\\lab3Files\\dop2.1\\FILE2.txt");

	while (FILE2read >> word)
	{
		amountWords++;
	}

	FILE2read.close();

	cout << amountWords << endl;

	return 0;
}