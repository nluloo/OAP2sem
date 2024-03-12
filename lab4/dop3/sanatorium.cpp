#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#define maxTravel 30

using namespace std;

void input_info_sanatorium();
void search_info();
void sort_sanatoriums();

struct sanatoriumTravel {
	string nameSanatorium;
	string location;
	string tratmentProfile;
	int amountTravel;
};

sanatoriumTravel info_sanatorium[maxTravel];
int current_size = 0;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int choise;

	do
	{
		system("cls");
		cout << "\n1.���� ����������\n2.����� ��������������� ����������\n3.����� ����������\n4.�����\n";
		cin >> choise;
		switch (choise)
		{
		case 1:
			input_info_sanatorium();
			break;
		case 2:
			sort_sanatoriums();
			break;
		case 3:
			search_info();
			break;
		case 0:
			break;
		default:
			break;
		}
	} while (choise != 0);


	return 0;
}

bool cmp(sanatoriumTravel& a, sanatoriumTravel& b) {
	return a.nameSanatorium < b.nameSanatorium;
}
bool cmpp(sanatoriumTravel& a, sanatoriumTravel& b) {
	return a.tratmentProfile < b.tratmentProfile;
}

void input_info_sanatorium() {
	system("cls");
	int amountTrave;
	cout << "������� ���������� ����������: ";
	cin >> amountTrave;
	int correct_size = current_size;

	for (current_size; current_size < correct_size + amountTrave; current_size++) {
		cout << "������� �������� ���������: ";
		cin.ignore();
		getline(cin, info_sanatorium[current_size].nameSanatorium);
		cout << "������� ����� ���������: ";
		getline(cin, info_sanatorium[current_size].location);
		cout << "������� ������� ���������: ";
		getline(cin, info_sanatorium[current_size].tratmentProfile);
		cout << "������� ���������� �������: ";
		cin >> info_sanatorium[current_size].amountTravel;
	}
}

void sort_sanatoriums() {
	system("cls");
	sort(info_sanatorium, info_sanatorium + current_size, cmp);
	sort(info_sanatorium, info_sanatorium + current_size, cmpp);

	for (int i = 0; i < current_size; i++) {
		cout << "�������� ���������: ";
		cout << info_sanatorium[i].nameSanatorium << endl;
		cout << "����� ���������: ";
		cout << info_sanatorium[i].location << endl;
		cout << "������� ���������: ";
		cout << info_sanatorium[i].tratmentProfile << endl;
		cout << "���������� �������: ";
		cout << info_sanatorium[i].amountTravel << endl;
	}


}

void search_info() {
	string userBuff;
	int choise;

	cout << "1.����� �� �����\n2.����� �� ��������� �������\n";

	do
	{
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout << "������� ���: ";
			cin.ignore();
			getline(cin, userBuff);
			for (int i = 0; i < current_size; i++) {
				if (userBuff == info_sanatorium[i].nameSanatorium) {
					cout << "�������� ���������: ";
					cout << info_sanatorium[i].nameSanatorium << endl;
					cout << "����� ���������: ";
					cout << info_sanatorium[i].location << endl;
					cout << "������� ���������: ";
					cout << info_sanatorium[i].tratmentProfile << endl;
					cout << "���������� �������: ";
					cout << info_sanatorium[i].amountTravel << endl;
				}
			}
			break;
		case 2:
			cout << "������� �������: ";
			cin.ignore();
			getline(cin, userBuff);
			for (int i = 0; i < current_size; i++) {
				if (userBuff == info_sanatorium[i].tratmentProfile) {
					cout << "�������� ���������: ";
					cout << info_sanatorium[i].nameSanatorium << endl;
					cout << "����� ���������: ";
					cout << info_sanatorium[i].location << endl;
					cout << "������� ���������: ";
					cout << info_sanatorium[i].tratmentProfile << endl;
					cout << "���������� �������: ";
					cout << info_sanatorium[i].amountTravel << endl;
				}
			}
			break;
		case 3:
			break;
		default:
			break;
		}
	} while (choise != 3);
}