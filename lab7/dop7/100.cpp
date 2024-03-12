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
			cout << "Основной стек записан в файл" << endl;
			system("pause");
			break;
		case 4:
			fromFile(first);
			cout << "Стек прочитан из файла" << endl;
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
	cout << "Выберите команду:" << endl;
	cout << "1 - Добавление элемента в стек" << endl;
	cout << "2 - Разбиение на 2 стека четн/нечетн" << endl;
	cout << "3 - Запись в файл" << endl;
	cout << "4 - Чтение из файла" << endl;
	cout << "5/6 - Вывод на экран 1 стека/ 2 стека по 1 элементу" << endl;
	cout << "7/77/777 - Очистка стека1/стека2/стека" << endl;
	cout << "8/88/888 - Вывод стека1/стека2/стека" << endl;
}