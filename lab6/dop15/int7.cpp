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
	cout << "1.�������� �������" << endl;
	cout << "2.������� �������" << endl;
	cout << "3.����� ��������" << endl;
	cout << "4.����� ������ � ����" << endl;
	cout << "5.������ ������ � ����" << endl;
	cout << "6.���������� ������ �� �����" << endl;
	cout << "7.����� ������������� ���������, � ������� 7 �� �����" << endl;
}

void write(list*& p, int value) {
	list* newList = new list;
	if (newList != NULL) {
		newList->number = value;
		newList->next = p;
		p = newList;
	}
	else {
		cout << "������(" << endl;
	}
}
void printList(list* p) {
	if (p == NULL)
		cout << "������ ����." << endl;
	else {
		cout << "������:" << endl;
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
		cout << "������ ����." << endl;
	else {
		cout << "������:" << endl;
		while (p != NULL) {
			h++;
			if (p->number == value) {
				cout << "������ ����� ���� � ������ ��� �������: " << h << endl;
				return;
			}
			else {
				p = p->next;
			}

		}
		cout << "����� �� �������." << endl;
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
		cout << "������ ����." << endl;
	else {
		cout << "������:" << endl;
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