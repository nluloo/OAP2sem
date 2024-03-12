#include <iostream>
#include <fstream>

using namespace std;

struct list {
	int number;
	list* next;
};

void menu();
void write(list*&, int);
void printList(list*);
void search(list*, int);
void toFile(list*&);
int delNumber(list*&, int);
void fromFile(list*&);
int sum(list*);

int main() {
	setlocale(LC_ALL, "ru");
	int value, choice;
	list* first = NULL;

	menu();
	do {
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> value;
			write(first, value);
			printList(first);
			break;
		case 2:
			cin >> value;
			delNumber(first, value);
			printList(first);
			break;
		case 3:
			cin >> value;
			search(first, value);
			break;
		case 4:
			printList(first);
			break;
		case 5:
			toFile(first);
			break;
		case 6:
			fromFile(first);
			break;
		case 7:
			cout << sum(first);
			break;
		default:
			break;
		}
	} while (true);

	return 0;
}
void menu() {
	cout << "1.Добавить элемент" << endl;
	cout << "2.Удалить элемент" << endl;
	cout << "3.Поиск элемента" << endl;
	cout << "4.Вывод списка в окно" << endl;
	cout << "5.Запись списка в файл" << endl;
	cout << "6.Считывание списка из файла" << endl;
	cout << "7.Сумма положительных элементов, у которых 7 на конце" << endl;
}

void write(list*& p, int value) {
	list* newList = new list;
	if (newList != NULL) {
		newList->number = value;
		newList->next = p;
		p = newList;
	}
	else {
		cout << "Ошибка(" << endl;
	}
}
void printList(list* p) {
	if (p == NULL)
		cout << "Список пуст." << endl;
	else {
		cout << "Список:" << endl;
		while (p != NULL) {
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}
void search(list* p, int value) {
	int h = 0;
	if (p == NULL)
		cout << "Список пуст." << endl;
	else {
		cout << "Список:" << endl;
		while (p != NULL) {
			h++;
			if (p->number == value) {
				cout << "Данное число есть в списке под номером: " << h << endl;
				return;
			}
			else {
				p = p->next;
			}

		}
		cout << "Число не найдено." << endl;
	}
}
int delNumber(list*& p, int value) {
	list* previous, * current, * temp;
	if (value == p->number)
	{
		temp = p;
		p = p->next;
		delete temp;
		return value;
	}
	else
	{
		previous = p;
		current = p->next;
		while (current != NULL && current->number != value)
		{
			previous = current;
			current = current->next;
		}
		if (current != NULL)
		{
			temp = current;
			previous->next = current->next;
			delete(temp);
			return value;
		}
	}
	return 0;

}
void toFile(list*& p) {
	list* temp = p;
	list buff;
	ofstream writeFile("D:\\labs\\oap1.2\\lab6files\\FILE3.txt");
	while (temp) {
		buff = *temp;
		writeFile << temp->number << ' ';
		temp = temp->next;
	}
	writeFile.close();
}
void fromFile(list*& p) {
	list* first = NULL;
	ifstream readFile("D:\\labs\\oap1.2\\lab6files\\FILE3.txt");

	int value;
	readFile >> value;
	while (!readFile.eof())
	{
		write(first, value);
		readFile >> value;
	}
	p = first;

	readFile.close();
}
int sum(list* p) {
	int h = 0;
	if (p == NULL)
		cout << "Список пуст." << endl;
	else {
		cout << "Список:" << endl;
		while (p != NULL) {
			if (p->number % 10 == 7 && p->number > 0) {
				h += p->number;
				p = p->next;
			}
			else {
				p = p->next;
			}
		}
	}
	return h;
}