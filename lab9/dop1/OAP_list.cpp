#include "List.h"
#include <iostream>
#define amountUni 10
#define Spec 10
#define amountForm 2
using namespace std;

struct University
{
	char nameUniversity[50];
	string addresUniversity;
	int amountSpec;
	char specialties[Spec][100];
	int lastYearPoints[Spec][amountForm];
	int lengthPayments;
	University* next;
};

void menu() {
	cout << "1. �������� ������ (����, ���)" << endl;	
	cout << "2. ����� ������ �� �����" << endl;
	cout << "3. ���������� ���������" << endl;
	cout << "4. �������� ������" << endl;
}

void print(void* b)       //������� ������������ ��� ������ 
{
	University* a = (University*)b;
	cout << a->nameUniversity << "  " << endl << a->addresUniversity << endl;
	cout << '\t';
	for (int j = 0; j < a->amountSpec; j++) {
		cout << a->specialties[j] << '\t';
	}
	cout << endl << "������: ";
	for (int j = 0; j < a->amountSpec; j++) {
		for (int g = 0; g < 2; g++) {
			if (g == 0)
			{
				cout << a->lastYearPoints[j][g] << '\t';
			}
		}
	}
	cout << endl << "������: ";
	for (int j = 0; j < a->amountSpec; j++) {
		for (int g = 0; g < 2; g++) {
			if (g == 1)
			{
				cout << a->lastYearPoints[j][g] << '\t';
			}
		}
	}
	cout << endl;
	cout << "������ ������ ��� ���������� ��������: " << a->lengthPayments << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	University a1, a2;
	Object L1;
	do
	{
		menu();
		cin >> choice;
		switch (choice)
		{
			case 1:
				a1 = { "����", "��������� 13�", 3, {"��", "����", "��"},{{400, 500},{300, 340}, {500, 600}}, 4000 };
				a2 = { "���", "������� �������������", 3, {"��", "��", "��"},{{234, 300},{310, 320}, {230, 250}}, 6000 };
				L1 = Create();
				L1.Insert(&a1);
				L1.Insert(&a2);
				cout << "������ ������� ������" << endl;
				break;
			case 2:
				L1.PrintList(print);
				break;
			case 3:
				cout << endl << "���������� ��������� ������: " << L1.CountList() << endl; // ������� ���������� ��������� �����
				break;
				case 4:
					if (L1.DeleteList())
						cout << "������ ������� ������" << endl;
					else
						cout << "������ ��������" << endl;// ������� �����(��� �������)
					break;
			default:
				break;
	}
	} while (choice);


	return 0;
}
