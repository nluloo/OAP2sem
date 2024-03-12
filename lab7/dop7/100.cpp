#include <iostream>
#include "myStack.h"

using namespace std;

void menu();

int main() {
	setlocale(LC_ALL, "ru");
	int c, b;
	Stack* first = nullptr;
	Stack* first1 = nullptr;
	Stack* first2 = nullptr;

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
			new_stack(first, first1, first2);
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
			cout << "number: " << pop(first1) << endl;
			system("pause");
			break;
		case 6:
			cout << "number: " << pop(first2) << endl;
			system("pause");
			break;
		case 7:
			clear(first1);
			break;
		case 77:
			clear(first2);
			break;
		case 777:
			clear(first);
			break;
		case 8:
			show(first1);
			system("pause");
			break;
		case 88:
			show(first2);
			system("pause");
			break;
		case 888:
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
	cout << "2 - ��������� �� 2 ����� ����/������" << endl;
	cout << "3 - ������ � ����" << endl;
	cout << "4 - ������ �� �����" << endl;
	cout << "5/6 - ����� �� ����� 1 �����/ 2 ����� �� 1 ��������" << endl;
	cout << "7/77/777 - ������� �����1/�����2/�����" << endl;
	cout << "8/88/888 - ����� �����1/�����2/�����" << endl;
}