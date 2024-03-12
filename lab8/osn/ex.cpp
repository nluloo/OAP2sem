#include <iostream>

using namespace std;

struct myCharQue
{
	char ss;
	myCharQue* next;
};
void pop(myCharQue**, myCharQue**, char);
void show(myCharQue*);
void del(myCharQue*&, myCharQue*&, char);
void menu();
void delChar(myCharQue*&, char);

int main() {
	setlocale(LC_ALL, "ru");
	myCharQue* begin = NULL, *end=NULL;
	int choice;
	char s;
	do {
		system("cls");
		menu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cin >> s;
			pop(&begin, &end, s);
			break;
		case 2:
			show(begin);
			system("pause");
			break;
		case 3:
			cin >> s;
			del(begin, end, s);
			break;
		case 4:
			cin >> s;
			delChar(begin, s);
			system("pause");
			break;
		default:
			break;
		}
	} while (choice != 5);
	return 0;
}
void pop(myCharQue** begin, myCharQue** end, char value) {
	myCharQue* p = new myCharQue;
	if (*end == NULL) {
		p->ss = value;
		p->next = nullptr;
		*begin = *end = p;
		return;
	}
	p->next = NULL;
	if (*begin == NULL) {
		*begin = *end = p;
	}
	else {
		p->ss = value;
		(*end)->next = p;
		*end = p;
	}
}
void show(myCharQue* begin) {
	myCharQue* p = begin;
	if (p == NULL) {
		cout << "(((" << endl;
	}
	else {
		while (p != NULL) {
			cout << p->ss << endl;
			p = p->next;
		}
	}
}
void del(myCharQue*& begin, myCharQue*& end ,char value) {
	myCharQue* temp, *pr, *current;
	if (begin->ss == value) {
		temp = begin;
		begin = begin->next;
		delete[] temp;
		return;
	}
	else {
		pr = begin;
		current = begin->next;
		while (current != nullptr && current->ss != value) {
			pr = current;
			current = current->next;
		}
		if (current != nullptr) {
			temp = current;
			pr->next = current->next;
			delete[] temp;
			return;
		}
	}
}
void menu() {
	cout << "1. Ввести элемент в очередь" << endl;
	cout << "2. Вывод списка очереди" << endl;
	cout << "3. Удаление элемента в очереди" << endl;
	cout << "4. Ввести спец символ и удалить все символы до него" << endl;
	cout << "5. Выход" << endl;
}
void delChar(myCharQue*& begin, char value) {
	myCharQue* current, *pr, *cr, *temp;
	int j = 0;
	if (begin->ss == value) {
		return;
	}
	else {
		current = begin;
		while (current != NULL && current->ss != value) {
			current = current->next;
		}
		if (current == NULL) {
			cout << "Такого символа нет" << endl;
			return;
		}
		while (begin != current) {
			temp = begin;
			begin = begin->next;
			delete[] temp;
		}
	}
}