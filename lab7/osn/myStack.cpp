#include "myStack.h"
void push(int x, Stack*& first)
{
	Stack* p = new Stack;
	p->number = x;
	p->next = first;
	first = p;
}
void new_stack(Stack*& first, Stack*& first1, Stack*& first2) {
	Stack* temp = first2;
	while (first1->next != nullptr)
	{
		if (temp == nullptr) {
			first1 = first1->next;
			temp = first2;
			continue;
		}
		if (first1->number == temp->number) {
			push(first1->number, first);
			first1 = first1->next;
			temp = first2;
		}
		else {
			temp = temp->next;
		}
	}
	delete[] temp;
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
	ofstream fileWrite("D:\\labs\\oap1.2\\lab7files\\FILE1.txt");
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


	ifstream fileRead("D:\\labs\\oap1.2\\lab7files\\FILE1.txt");

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

