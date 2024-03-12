#include <iostream>
#include "myStack.h"

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
			push(numberUser, stack1);
			break;
		case 2:
			cin >> numberUser;
			push(numberUser, stack2);
			break;
		case 3:
			new_stack(stack, stack1, stack2);
			break;
		case 4:
			toFile(stack);
			break;
		case 44:
			fromFile(stack);
			break;
		case 5:
			cout <<"number: " << pop(stack) << endl;
			system("pause");
			break;
		case 6:
			clear(stack);
			break;
		case 7:
			show(stack);
			system("pause");
			break;
		default:
			break;
		}
	} while (choice != 8);

	return 0;
}
void menu() {
	cout << "Выберите команду:" << endl;
	cout << "1 - Добавление элемента в стек 1" << endl;
	cout << "2 - Добавиление элемента в стек 2" << endl;
	cout << "3 - Нахождение одинаковых значений и запись в стек" << endl;
	cout << "4 - Запись в файл" << endl;
	cout << "5 - Чтение из файла" << endl;
	cout << "6 - Очистка стека" << endl;
	cout << "7 - Вывод стека с очисткой" << endl;
	cout << "8 - Выход" << endl;
}