#include <iostream>
#include "myStack1.h"

using namespace std;

void menu();

int main() {
	setlocale(LC_ALL, "ru");
	int choice, numberUser;
	Stack* stack = nullptr;
	Stack* stack1 = nullptr;
	Stack* stack2 = nullptr;

	do
	{
		system("cls");
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> numberUser;
			push(numberUser, stack);
			system("pause");
			break;
		case 2:
			new_stack(stack, stack1, stack2);
			system("pause");
			break;
		case 3:
			toFile(stack);
			cout << "�������� ���� ������� � ����" << endl;
			system("pause");
			break;
		case 4:
			fromFile(stack);
			cout << "���� �������� �� �����" << endl;
			system("pause");
			break;
		case 5:
			cout << "number: " << pop(stack1) << endl;
			system("pause");
			break;
		case 6:
			cout << "number: " << pop(stack2) << endl;
			system("pause");
			break;
		case 7:
			clear(stack1);
			break;
		case 77:
			clear(stack2);
			break;
		case 777:
			clear(stack);
			break;
		case 8:
			show(stack1);
			system("pause");
			break;
		case 88:
			show(stack2);
			system("pause");
			break;
		case 888:
			show(stack);
			system("pause");
			break;
		default:
			break;
		}
	} while (choice != 10);

	return 0;
}
void menu() {
	cout << "�������� �������:" << endl;
	cout << "1 - ���������� �������� � ����" << endl;
	cout << "2 - ��������� �� 2 ����� ������ 50/ ������" << endl;
	cout << "3 - ������ � ����" << endl;
	cout << "4 - ������ �� �����" << endl;
	cout << "5/6 - ����� �� ����� 1 �����/ 2 ����� �� 1 ��������" << endl;
	cout << "7/77/777 - ������� �����1/�����2/�����" << endl;
	cout << "8/88/888 - ����� �����1/�����2/�����" << endl;
	cout << "10 - �����" << endl;

}