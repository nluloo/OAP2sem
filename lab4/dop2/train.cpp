#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>

#define amountTrain 2

using namespace std;

void input_info_train();
void info_trains();


struct TRAIN {
    string nameDestination;
    int numberTrain;
    int time;

};

TRAIN list_train[amountTrain];

void output() {
    for (int i = 0; i < amountTrain; i++)
    {
        system("cls");
        cout << "Название пункта назначения: ";
        cout << list_train[i].nameDestination << endl;
        cout << "Номер поезда: ";
        cout << list_train[i].numberTrain << endl;
        cout << "Время отправления: ";
        cout << list_train[i].time / 100 << ":" << list_train[i].time % 100 << endl;
    }
}

int main() {
    int choice;
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    do
    {
        cout << "1. Ввод информации о поезде" << endl;
        cout << "2. Вывод информации о поезде" << endl;
        cout << "3. Информация о поездах" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            input_info_train();
            break;
        case 2:
            output();
            break;
        case 3:
            info_trains();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            break;
        }

    } while (true);

    return 0;
}

bool cmp(TRAIN& a, TRAIN& b) {
    return a.nameDestination < b.nameDestination;
}

void input_info_train() {
    system("cls");
    for (int i = 0; i < amountTrain; i++)
    {
        cout << "Название пункта назначения: ";
        cin >> list_train[i].nameDestination;
        cout << "Номер поезда: ";
        cin >> list_train[i].numberTrain;
        cout << "Введите время отправления в формате ЧЧММ: ";
        cin >> list_train[i].time;
    }

    sort(list_train, list_train + amountTrain, cmp);
}

void info_trains() {
    system("cls");
    int timeUser;
    int hours, minutes, amount = 0;
    cout << "Введите время: ";
    cin >> timeUser;

    hours = timeUser / 100;
    minutes = timeUser % 100;

    for (int i = 0; i < amountTrain; i++) {
        if (list_train[i].time / 100 > hours || list_train[i].time % 100 > minutes && list_train[i].time / 100 == hours) {
            cout << "Название пункта назначения: ";
            cout << list_train[i].nameDestination << endl;
            cout << "Номер поезда: ";
            cout << list_train[i].numberTrain << endl;
            cout << "Время отправления: ";
            cout << list_train[i].time / 100 << ":" << list_train[i].time % 100 << endl;
            amount++;
        }
    }
    if (amount == 0) {
        cout << "Рейсов после введенного времени не найдено." << endl;
    }
}