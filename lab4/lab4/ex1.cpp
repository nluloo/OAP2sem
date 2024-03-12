#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define amountUni 10
#define Spec 10
#define amountForm 2

using namespace std;

void input_elements();
void output_elements();
void delete_elements();
void search_info();
void writeln_info_to_file();
void read_info_from_file();

int current_size = 0;

struct entrantDirectory
{
	char nameUniversity[50];
	string addresUniversity;
	int amountSpec;
	char specialties[Spec][100];
	int lastYearPoints[Spec][amountForm];
	int lengthPayments;
};

entrantDirectory list_of_uni[amountUni];

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "ru");
	int choise;

	do {
		system("cls");
		cout << "\n1.���� ������ � ����������" << endl;
		cout << "2.����� ������" << endl;
		cout << "3.�������� ������" << endl;
		cout << "4.����� �� �������������" << endl;
		cout << "5.������ ���������� � ����" << endl;
		cout << "6.������ ������ �� �����" << endl;
		cout << "7.����� �� ���������\n" << endl; 
		cout << "������� ����� ��������: ";
		cin >> choise;

		switch (choise)
		{
		case 1:
			input_elements();
			break;
		case 2:
			output_elements();
			break;
		case 3:
			delete_elements();
			break;
		case 4:
			search_info();
			break;
		case 5:
			writeln_info_to_file();
			break;
		case 6: 
			read_info_from_file();
			break;
		default:
			break;
		}

	} while (choise != 7);

	return 0;
}

void input_elements() {
	system("cls");
	cout << "���� ����������: " << endl;
	if (current_size < amountUni) {
		cout << "����� ������������ " << current_size + 1 << endl;
		cout << "�������� ������������(������������): ";
		cin >> list_of_uni[current_size].nameUniversity;
		cout << endl << "����� ������������: ";
		cin.ignore();
		getline(cin, list_of_uni[current_size].addresUniversity);
		cout << endl << "������� ���������� ��������������: ";
		cin >> list_of_uni[current_size].amountSpec;
		for (int i = 0; i < list_of_uni[current_size].amountSpec; i++) {
			cout << endl << i + 1 << " �������������: ";
			cin >> list_of_uni[current_size].specialties[i];
		}
		cout << endl << "������� �������� ����: " << endl;
		for (int i = 0; i < list_of_uni[current_size].amountSpec; i++) {
			cout << "������� ��� " << list_of_uni[current_size].specialties[i] << endl;
			for (int j = 0; j < 2; j++) {
				if (j == 0) {
					cout << "������: ";
					cin >> list_of_uni[current_size].lastYearPoints[i][j];
				}
				if (j == 1) {
					cout << "������: ";
					cin >> list_of_uni[current_size].lastYearPoints[i][j];
				}
			}
		}

		cout << endl << "������ ������ ��� ���������� ��������: ";
		cin >> list_of_uni[current_size].lengthPayments;
		current_size++;
	}
}

void output_elements() {
	system("cls");
	cout << endl;
	for (int i = 0; i < current_size; i++) {
		cout << "�������� ������������: " << list_of_uni[i].nameUniversity << endl;
		cout << "����� ������������: " << list_of_uni[i].addresUniversity << endl << endl;
		cout << "������������� � ��������� �����: " << endl;
		cout << '\t';
		for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
			cout << list_of_uni[i].specialties[j] << '\t';
		}
		cout << endl;
		cout << "������: ";
		for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
			for (int g = 0; g < 2; g++) {
				if(g == 0)
				{
					cout << list_of_uni[i].lastYearPoints[j][g] << '\t';
				}
			}
		}
		cout << endl << "������: ";
		for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
			for (int g = 0; g < 2; g++) {
				if (g == 1)
				{
					cout << list_of_uni[i].lastYearPoints[j][g] << '\t';
				}
			}
		}
		cout << endl;
		cout << "������ ������ ��� ���������� ��������: " << list_of_uni[i].lengthPayments << endl;
	}
	system("pause");
}

void delete_elements() {
	system("cls");
	int numberLine;
	cout << "\n������� ����� ������, ������� �� ������ �������: " << endl;
	cin >> numberLine;
		{	for (int de1 = (numberLine - 1); de1 < current_size; de1++)
		list_of_uni[de1] = list_of_uni[de1 + 1];
		current_size = current_size - 1;
		}

}

void search_info() {
	system("cls");
	string spec;
	cout << "������� �������������: " << endl;
	cin.ignore();
	getline(cin, spec);
	for (int i = 0; i < current_size; i++) {
		for(int j = 0; j < list_of_uni[i].amountSpec;j++)
		{
			if (list_of_uni[i].specialties[j] == spec) {
				cout << "�������� ������������: " << list_of_uni[i].nameUniversity << endl;
				cout << "��������� �����: " << endl;
				cout << '\t';
				cout << list_of_uni[i].specialties[j] << endl;
					for (int g = 0; g < 2; g++) {
						if (g == 0)
						{
							cout << "������: ";
							cout << list_of_uni[i].lastYearPoints[j][g] << endl;
						}
						if (g == 1) {
							cout << "������: ";
							cout << list_of_uni[i].lastYearPoints[j][g] << endl;
						}
					}
				cout << endl;
			}
		}
	}
	system("pause");
}

void writeln_info_to_file() {
	system("cls");
	ofstream fileWriting("D:\\labs\\oap1.2\\lab4Files\\FILE1.txt", std::ios::app);
	for (int i = 0; i < current_size; i++) {
		fileWriting << endl;
		if (current_size < amountUni) {
			fileWriting << list_of_uni[i].nameUniversity;
			fileWriting << endl;
			fileWriting << list_of_uni[i].addresUniversity;
			fileWriting << endl;
			fileWriting << list_of_uni[i].amountSpec;
			fileWriting << '\t';
			for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
				fileWriting << list_of_uni[i].specialties[j];
				fileWriting << '\t';
			}
			for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
				for (int g = 0; g < 2; g++) {
					if (g == 0) {
						fileWriting << list_of_uni[i].lastYearPoints[j][g];
						fileWriting << '\t';
					}
					if (g == 1) {
						fileWriting << list_of_uni[i].lastYearPoints[j][g];
						fileWriting << '\t';
					}
				}
			}
			fileWriting << list_of_uni[i].lengthPayments;
		}
	}
	
	fileWriting.close();
}

void read_info_from_file() {
	current_size = 0;
	ifstream readFile("D:\\labs\\oap1.2\\lab4Files\\FILE1.txt");
	int i = 0;
	char buff[50];
	while (readFile >> list_of_uni[i].nameUniversity) {
		readFile.getline(buff, 20);
		getline(readFile, list_of_uni[i].addresUniversity);
		readFile >> list_of_uni[i].amountSpec;
		readFile.ignore();
		for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
			readFile >> list_of_uni[i].specialties[j];
		}
		for (int j = 0; j < list_of_uni[i].amountSpec; j++) {
			for (int g = 0; g < 2; g++) {
				if (g == 0) {
					readFile >> list_of_uni[i].lastYearPoints[j][g];
				}
				if (g == 1) {
					readFile >> list_of_uni[i].lastYearPoints[j][g];
				}
			}
		}
		readFile >> list_of_uni[i].lengthPayments;
		current_size++;
		i++;
	}
	readFile.close();
}
