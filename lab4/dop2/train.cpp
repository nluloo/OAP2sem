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
        cout << "�������� ������ ����������: ";
        cout << list_train[i].nameDestination << endl;
        cout << "����� ������: ";
        cout << list_train[i].numberTrain << endl;
        cout << "����� �����������: ";
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
        cout << "1. ���� ���������� � ������" << endl;
        cout << "2. ����� ���������� � ������" << endl;
        cout << "3. ���������� � �������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
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
            cout << "����� �� ���������." << endl;
            return 0;
        default:
            cout << "�������� ����. ���������� ��� ���." << endl;
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
        cout << "�������� ������ ����������: ";
        cin >> list_train[i].nameDestination;
        cout << "����� ������: ";
        cin >> list_train[i].numberTrain;
        cout << "������� ����� ����������� � ������� ����: ";
        cin >> list_train[i].time;
    }

    sort(list_train, list_train + amountTrain, cmp);
}

void info_trains() {
    system("cls");
    int timeUser;
    int hours, minutes, amount = 0;
    cout << "������� �����: ";
    cin >> timeUser;

    hours = timeUser / 100;
    minutes = timeUser % 100;

    for (int i = 0; i < amountTrain; i++) {
        if (list_train[i].time / 100 > hours || list_train[i].time % 100 > minutes && list_train[i].time / 100 == hours) {
            cout << "�������� ������ ����������: ";
            cout << list_train[i].nameDestination << endl;
            cout << "����� ������: ";
            cout << list_train[i].numberTrain << endl;
            cout << "����� �����������: ";
            cout << list_train[i].time / 100 << ":" << list_train[i].time % 100 << endl;
            amount++;
        }
    }
    if (amount == 0) {
        cout << "������ ����� ���������� ������� �� �������." << endl;
    }
}