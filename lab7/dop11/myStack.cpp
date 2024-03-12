#include "myStack.h"
void push(int x, Stack*& first)
{
	Stack* p = new Stack;
	p->number = x;
	p->next = first;
	first = p;
}
void new_stack(Stack*& first) {
	Stack* temp = first;
	while (temp != nullptr)
	{
		if (temp->number % 3 == 0) {
			delNumber(first, temp->number);
			temp = first;
			continue;
		}
		temp = temp->next;
	}
}
int pop(Stack*& stack) {
	if (stack == 0) {
		cout << "(((" << endl;
		return -1;
	}
	else {
		Stack* p = stack;
		int x = p->number;
		if (x) {
			stack = stack->next;
		}
		delete[] p;
		return x;
	}
}
void show(Stack*& first) {
	Stack* p = first;
	if (p == nullptr) {
		cout << "���� ����" << endl;
		return;
	}
	while (p != nullptr) {
		cout << pop(p) << ' ';
	}
	cout << endl;
	delete[] p;
}
void clear(Stack*& first) {
	delete[] first;
	first = nullptr;
}
void toFile(Stack*& first) {
	Stack* p = first;
	int buf;
	ofstream fileWrite("D:\\labs\\oap1.2\\lab7files\\FILE4.txt");
	while (p) {
		buf = p->number;
		fileWrite << buf << ' ';
		p = p->next;
	}
	fileWrite << endl;
	fileWrite.close();
}
void fromFile(Stack*& first) {
	delete[] first;
	first = nullptr;
	Stack buff, * p = nullptr, * e = nullptr;


	ifstream fileRead("D:\\labs\\oap1.2\\lab7files\\FILE4.txt");

	fileRead.seekg(0);
	fileRead >> buff.number;
	while (!fileRead.eof()) {
		push(buff.number, p);
		fileRead >> buff.number;
	}
	fileRead.close();

	while (p != nullptr) {
		buff.number = pop(p);
		push(buff.number, e);
		first = e;
	}
}
void delNumber(Stack*& p, int value) {
	Stack* previous, * current, * temp;
	if (value == p->number) // ���� ������� ������
	{
		temp = p; // ����������� ������� ���� ��������� ���������� temp ��� ������������ ��������
		p = p->next; // ����������� ������� ���� ����� ��������
		delete[] temp; // ������� ���� � ������
		return;
	}
	else // ���� ������� � �������� ��� � ����
	{
		previous = p; // �.� ������ ���� �� ����� ������ �����, �� ����� ������ �������� �� ����, ���� �� ������ ���� �����
		current = p->next; // ������� ����
		while (current != NULL && current->number != value) // ���� ������� ���� �� ����� ���� � ������ �����, �� ��������� 
		{
			previous = current; // ���������� ����
			current = current->next; // ������� ����
		}
		// ����� ������� ���� ����� �� ������� �� ����� � ���� � �������, ��� � ����� ���������
		if (current != NULL)
		{
			temp = current; // ���������� �������� ����( � ����� ������) ��������� ���������� temp
			previous->next = current->next; // ������� ���� ����� ��������� �� ��������� ���� ����� ��������.
			delete[] temp;
			return;
		}
	}
}