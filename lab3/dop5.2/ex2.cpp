#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void writing_to_file(string);
void find_integer(string&);

int main() {

	string line;
	string intGroup;

	getline(cin, line);
	
	writing_to_file(line);

	find_integer(intGroup);

	cout << intGroup << endl;

	return 0;
}

void writing_to_file(string line) {
	ofstream fout("D:\\labs\\oap1.2\\lab3Files\\dop5.2\\FILE1.txt");

	if (!fout.is_open())
		cout << "(((" << endl;
	else {
		fout << line;
	}
	fout.close();
}
void find_integer(string& intGroup) {
	ifstream fin("D:\\labs\\oap1.2\\lab3Files\\dop5.2\\FILE1.txt");
	int countInt = 0;

	if (!fin.is_open())
		cout << "(((" << endl;
	else {
		while (!fin.eof()) {
			countInt = 0;
			int i = 0;
			fin >> intGroup;
			for (; intGroup[i] != '\0'; i++) {
				if (intGroup[i] == '0' || intGroup[i] == '1' || intGroup[i] == '2' || intGroup[i] == '3' || intGroup[i] == '4' || intGroup[i] == '5' || intGroup[i] == '6' || intGroup[i] == '7' || intGroup[i] == '8' || intGroup[i] == '9') {
					countInt++;
				}
			}
			if (countInt == i) {
				return;
			}
		}
	}

	fin.close();
}