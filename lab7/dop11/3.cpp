#include <iostream>
#include "myStack.h"

using namespace std;

void menu();

int main() {
	setlocale(LC_ALL, "ru");
	int c, b;
	Stack* first = nullptr;

	do
	{
		system("cls");
		menu();
		cin >> c;
		switch (c)
		{
		case 1:
			cin >> b;
			push(b, first);
			system("pause");
			break;
		case 2:
			new_stack(first);
			system("pause");
			break;
		case 3:
			toFile(first);
			cout << "�������� ���� ������� � ����" << endl;
			system("pause");
			break;
		case 4:
			fromFile(first);
			cout << "���� �������� �� �����" << endl;
			system("pause");
			break;
		case 5:
			cout << "number: " << pop(first) << endl;
			system("pause");
			break;
		case 7:
			clear(first);
			break;
		case 8:
			show(first);
			system("pause");
			break;
		default:
			break;
		}
	} while (c != 10);

	return 0;
}
void menu() {
	cout << "�������� �������:" << endl;
	cout << "1 - ���������� �������� � ����" << endl;
	cout << "2 - �������� ����� �� �����, ������� 3" << endl;
	cout << "3 - ������ � ����" << endl;
	cout << "4 - ������ �� �����" << endl;
	cout << "5 - ����� �� ����� ��������� ����� �� 1 ��������" << endl;
	cout << "6 - ������� �����" << endl;
	cout << "8 - ����� �����" << endl;
}