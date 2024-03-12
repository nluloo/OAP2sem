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
		cout << "Стек пуст" << endl;
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
	if (value == p->number) // Если элемент первый
	{
		temp = p; // Присваиваем текущий узел временной переменной temp для последующего удаление
		p = p->next; // Присваиваем первому узлу новое значение
		delete[] temp; // Удаляем узел с цифрой
		return;
	}
	else // Если элемент в середине или в коце
	{
		previous = p; // Т.к первый узел не равен нашему числу, то будем делать проходки до того, пока не найдем наше число
		current = p->next; // Текущий узел
		while (current != NULL && current->number != value) // Пока текущий узел не равен нулю и нашему числу, то выполняем 
		{
			previous = current; // предыдущий узел
			current = current->next; // текущий узел
		}
		// Когда находит наше число то выходит из цикла и идет в условие, уже с нашим значением
		if (current != NULL)
		{
			temp = current; // присваение текущего узла( с нашей цифрой) временной переменной temp
			previous->next = current->next; // Прошлый узел будет указывать на следующий узел после удаление.
			delete[] temp;
			return;
		}
	}
}