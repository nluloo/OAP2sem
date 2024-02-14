#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	char buff[500];
	int space = 0;

	ifstream FILE1("D:\\labs\\oap1.2\\lab3Files\\dop13.1\\FILE1.txt");
	ofstream FILE2("D:\\labs\\oap1.2\\lab3Files\\dop13.1\\FILE2.txt");
	
	if (!FILE1.is_open()) {
		cout << "(((" << endl;
		return 1;
	}
	else {
		while (!FILE1.eof())
		{
			space = 0;
			FILE1.getline(buff, 500);
			for (int i = 0; buff[i] != '\0'; i++) {
				if (buff[i] == ' ') { // Проверка на пробел
					space++;
				}
			}
			if (space > 1) { // Если есть 2 пробела и более, то записать строку в новый файл
				FILE2 << buff;
				FILE2 << endl;
			}
		}
	}

	FILE1.close();
	FILE2.close();

	ifstream IFILE2("D:\\labs\\oap1.2\\lab3Files\\dop13.1\\FILE2.txt");
	int countVowel = 0;
	int countMaxWordVowel = 0;
	string wordMaxVowel;

	if (!IFILE2.is_open()) {
		cout << "(((" << endl;
		return 1;
	}
	else {
		while (!IFILE2.eof())
		{
			countVowel = 0;
			IFILE2 >> buff;
			for (int i = 0; buff[i] != '\0'; i++) {
				if (buff[i] == 'a' || buff[i] == 'e' || buff[i] == 'y' || buff[i] == 'u' || buff[i] == 'i' || buff[i] == 'o') {
					countVowel++;
				}
			}
			if (countVowel > countMaxWordVowel) {
				wordMaxVowel = buff;
			}
		}
	}

	cout << wordMaxVowel << endl;

	IFILE2.close();

	return 0;
}