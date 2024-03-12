#include <iostream>

using namespace std;
int gg;
struct list
{
	float number;
	list* next;
};

void pop(list**, list**, float);
void show(list*);
list maxValue(list*);
void shiftNumber(list*&, list*&);
void menu();

int main() {
	setlocale(LC_ALL, "ru");
	list* begin = nullptr, * end = nullptr;
	int choice;
	float number;
	do {
		menu();
		cin >> choice;
		system("cls");
			switch (choice)
			{
			case 1:
				cin >> number;
				pop(&begin, &end, number);
				break;
			case 2:
				show(begin);
				break;
			case 3:
				maxValue(begin);
				shiftNumber(begin, end);
				break;
			default:
				break;
			}
	} while (choice != 4);

	return 0;
}

void menu() {
	cout << "Ввод элемента в очередь" << endl;
	cout << "Вывод элементов очереди" << endl;
	cout << "Циклический сдвиг" << endl;
}

void pop(list** begin, list** end, float value) {
	list* p = new list;
	if (*end == NULL) {
		p->number = value;
		p->next = nullptr;
		*begin = *end = p;
		return;
	}
	p->next = NULL;
	if (*begin == NULL) {
		*begin = *end = p;
	}
	else {
		p->number = value;
		(*end)->next = p;
		*end = p;
	}
}
void show(list* begin) {
	list* p = begin;
	if (p == NULL) {
		cout << "(((" << endl;
	}
	else {
		while (p != NULL) {
			cout << p->number << endl;
			p = p->next;
		}
	}
}

void shiftNumber(list*& begin, list*& end) {
	list* temp = begin;
	end->next = begin;
	int i = 0;
		while (i < gg) {
			temp = begin;
			begin = begin->next;
			end = temp;
			i++;
		}

	end->next = NULL; // Должно быть, т.к последний элемент ни на что не указывает
}
list maxValue(list* begin) {
	list max = *begin;
	int g = 0;
	while (begin != NULL)
	{
		if (max.number < begin->number) {
			max = *begin;
			gg = g;
		}
		begin = begin->next;
		g++;
	}
	return max;
}