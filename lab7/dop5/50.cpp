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
			cout << "Основной стек записан в файл" << endl;
			system("pause");
			break;
		case 4:
			fromFile(stack);
			cout << "Стек прочитан из файла" << endl;
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
	cout << "Выберите команду:" << endl;
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Разбиение на 2 стека больше 50/ меньше" << endl;
	cout << "3 - Запись в файл" << endl;
	cout << "4 - Чтение из файла" << endl;
	cout << "5/6 - Вывод на экран 1 стека/ 2 стека по 1 элементу" << endl;
	cout << "7/77/777 - Очистка стека1/стека2/стека" << endl;
	cout << "8/88/888 - Вывод стека1/стека2/стека" << endl;
	cout << "10 - выход" << endl;

}