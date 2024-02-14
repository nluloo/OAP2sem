#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writing_to_file(string);

int counting_brackets(string&, int&);

int main() {
	string line;
	int countBrackets = 0;

	getline(cin, line);

	writing_to_file(line);

	counting_brackets(line, countBrackets);

	cout << countBrackets << endl;

	return 0;
}

void writing_to_file(string line) {
	ofstream OFILE1("D:\\labs\\oap1.2\\lab3Files\\dop13.2\\FILE1.txt");

	if (!OFILE1.is_open()) {
		cout << "(((" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		OFILE1 << line;
	}

	OFILE1.close();
}

int counting_brackets(string& line, int& countBrackets) {
	ifstream IFILE1("D:\\labs\\oap1.2\\lab3Files\\dop13.2\\FILE1.txt");

	if (!IFILE1.is_open()) {
		cout << "(((" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		getline(IFILE1, line);
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == '(' || line[i] == ')') {
				countBrackets++;
			}
		}
	}

	IFILE1.close();
	return countBrackets;
}