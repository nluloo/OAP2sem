#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Stack
{
	int number;
	Stack* next;
}; // исправить

void push(int, Stack*&);
int pop(Stack*&);
void show(Stack*&);
void toFile(Stack*&);
void fromFile(Stack*&);
void clear(Stack*&);
void printList(Stack*);
int del(Stack*&, int);

void new_stack(Stack*&, Stack*&, Stack*&);