#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writing_to_file(string);

void find_short_group(string&);

int main() {
	string minGroup;
	string inputLine;

	getline(cin, inputLine);

	writing_to_file(inputLine);

	find_short_group(minGroup);

	cout << minGroup << endl;

	return 0;
}

void writing_to_file(string inputLine) {
	ofstream FILE1("D:\\labs\\oap1.2\\lab3Files\\dop2.2\\FILE1.txt");

	if (!FILE1.is_open()) {
		cout << "(((";
		exit(EXIT_FAILURE);
	}
	else {
		FILE1 << inputLine;
	}

	FILE1.close();
}
void find_short_group(string& minGroup) {
	ifstream IFILE1("D:\\labs\\oap1.2\\lab3Files\\dop2.2\\FILE1.txt");
	int countNumberMinGroup = 0;
	int NumberMinGroup = 100;

	char buff[500];

	if (!IFILE1.is_open()) {
		cout << "(((";
		exit(EXIT_FAILURE);
	}
	else {
		while (!IFILE1.eof()) {
			IFILE1 >> buff;
			countNumberMinGroup = 0;
			for (int i = 0; buff[i] != '\0'; i++) {
				countNumberMinGroup++;
			}
			if (NumberMinGroup > countNumberMinGroup) {
				minGroup = buff;
				NumberMinGroup = countNumberMinGroup;
			}
		}
	}
	IFILE1.close();
}