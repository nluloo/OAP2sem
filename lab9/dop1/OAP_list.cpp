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
	cout << "1. Создание списка (БГТУ, БГУ)" << endl;	
	cout << "2. Вывод списка на экран" << endl;
	cout << "3. Количество элементов" << endl;
	cout << "4. Удаление списка" << endl;
}

void print(void* b)       //Функция используется при выводе 
{
	University* a = (University*)b;
	cout << a->nameUniversity << "  " << endl << a->addresUniversity << endl;
	cout << '\t';
	for (int j = 0; j < a->amountSpec; j++) {
		cout << a->specialties[j] << '\t';
	}
	cout << endl << "Бюджет: ";
	for (int j = 0; j < a->amountSpec; j++) {
		for (int g = 0; g < 2; g++) {
			if (g == 0)
			{
				cout << a->lastYearPoints[j][g] << '\t';
			}
		}
	}
	cout << endl << "Платка: ";
	for (int j = 0; j < a->amountSpec; j++) {
		for (int g = 0; g < 2; g++) {
			if (g == 1)
			{
				cout << a->lastYearPoints[j][g] << '\t';
			}
		}
	}
	cout << endl;
	cout << "Размер оплаты при договорном обучении: " << a->lengthPayments << endl;
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
				a1 = { "БГТУ", "Свердлова 13а", 3, {"ПИ", "ИСИТ", "ЦД"},{{400, 500},{300, 340}, {500, 600}}, 4000 };
				a2 = { "БГУ", "Площадь независимости", 3, {"ПИ", "ПМ", "КБ"},{{234, 300},{310, 320}, {230, 250}}, 6000 };
				L1 = Create();
				L1.Insert(&a1);
				L1.Insert(&a2);
				cout << "Список успешно создан" << endl;
				break;
			case 2:
				L1.PrintList(print);
				break;
			case 3:
				cout << endl << "Количество элементов списка: " << L1.CountList() << endl; // Подсчет количества элементов листа
				break;
				case 4:
					if (L1.DeleteList())
						cout << "Список успешно удален" << endl;
					else
						cout << "Ошибка удаления" << endl;// Очистка листа(моя функция)
					break;
			default:
				break;
	}
	} while (choice);


	return 0;
}
