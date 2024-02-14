#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	int numberString = 1;
	char buff[500];
	int lengthLastWord = 0;
	string lastWord;

	ifstream fin("D:\\labs\\oap1.2\\lab3Files\\dop5.1\\FILE1.txt");
	ofstream fo("D:\\labs\\oap1.2\\lab3Files\\dop5.1\\FILE2.txt");
	if (!fin.is_open())
		cout << "(((" << endl;
	else {
		while (!fin.eof()) {
			if (numberString >= 4) {
				fin.getline(buff, 500);
				fo << buff;
				fo << '\n';
				continue;
			}
			fin.getline(buff, 500);
			numberString++;
		}
	}
	fin.close();
	fo.close();
	
	string word;
	ifstream finRead("D:\\labs\\oap1.2\\lab3Files\\dop5.1\\FILE2.txt");

	if (!finRead.is_open())
		cout << "(((" << endl;
	else {
		while (finRead >> word) {
			lastWord = word;
		}
		for (int i = 0; lastWord[i] != '\0'; i++) {
			lengthLastWord++;
		}
	}
	cout << lengthLastWord << endl;
	finRead.close();

	return 0;
}