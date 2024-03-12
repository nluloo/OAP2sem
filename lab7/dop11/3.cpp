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
			cout << "Основной стек записан в файл" << endl;
			system("pause");
			break;
		case 4:
			fromFile(first);
			cout << "Стек прочитан из файла" << endl;
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
	cout << "Выберите команду:" << endl;
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Удаление чисел из стека, кратных 3" << endl;
	cout << "3 - Запись в файл" << endl;
	cout << "4 - Чтение из файла" << endl;
	cout << "5 - Вывод на экран элементов стека по 1 элементу" << endl;
	cout << "6 - Очистка стека" << endl;
	cout << "8 - Вывод стека" << endl;
}