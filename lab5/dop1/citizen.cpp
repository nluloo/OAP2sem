#include <iostream>
#include <string>
#include <windows.h>
#define maxCitizen 30

//2 

int current_amount = 0;

using namespace std;

enum gender {
    ������� = 1, �������
};

void input_info();
void output_info();
void delete_info();
void search_info();

struct listGoust {
    string pass;
    int dateDay : 6;
    int dateMonth : 5;
    int dateYear : 16;
    string address;
    gender typeGender;

    int getState() {
        return typeGender;
    }

    void setState(gender State) {
        this->typeGender = State;
    }

};

listGoust list_guest[maxCitizen];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int choise;

    do
    {
        cout << "1. ���� ����������" << endl;
        cout << "2. ����� ����������" << endl;
        cout << "3. �������� ����������" << endl;
        cout << "4. ����� ����������" << endl;
        cout << "�������� ��������: ";
        cin >> choise;

        switch (choise)
        {
        case 1:
            input_info();
            break;
        case 2:
            output_info();
            break;
        case 3:
            delete_info();
            break;
        case 4:
            search_info();
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


void input_info() {
    system("cls");
    int amountPeople, writeGender, dateIn, dateOut;

    cout << "������� ���������� ������� ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        system("cls");
        cout << "���������� " << current_amount + 1 << " ������:" << endl;
        cout << "������� ���: ";
        cin.ignore();
        getline(cin, list_guest[current_amount].pass);
        cout << "������� ���� ��������: ";
        cin >> dateIn;
        cout << "������� �����: ";
        cin.ignore();
        getline(cin, list_guest[current_amount].address);
        list_guest[current_amount].dateDay = dateIn / 10000000 * 10 + dateIn / 1000000 % 10;
        list_guest[current_amount].dateMonth = (dateIn / 100000) % 10 * 10 + (dateIn / 10000) % 10;
        list_guest[current_amount].dateYear = dateIn % 10000;
        cout << "������� ���: ";
        cin >> writeGender;
        switch (writeGender)
        {
        case 1:
            list_guest[current_amount].setState(gender::�������);
            break;
        case 2:
            list_guest[current_amount].setState(gender::�������);
            break;
        default:
            break;
        }
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " ������: " << endl;
        cout << "���: " << list_guest[i].pass << endl;
        cout << "���� ��������: " << list_guest[i].dateDay / 10 << list_guest[i].dateDay % 10 << '.' << list_guest[i].dateMonth / 10 << list_guest[i].dateMonth % 10 << '.' << list_guest[i].dateYear / 1000 << list_guest[i].dateYear / 100 % 10 << list_guest[i].dateYear / 10 % 10 << list_guest[i].dateYear % 10 << endl;
        cout << "�����: " << list_guest[i].address << endl;
        cout << "���: ";
        switch (list_guest[i].getState())
        {
        case gender::�������:
            cout << "�������" << endl;
            break;
        case gender::�������:
            cout << "�������" << endl;
            break;
        default:
            break;
        }
    }
}

void delete_info() {
    system("cls");
    int numberPeople;
    cout << "������� ����� ������, �������� �� ������ �������: ";
    cin >> numberPeople;
    for (int del = numberPeople - 1; del < current_amount; del++) {
        list_guest[del] = list_guest[del + 1];
    }
    current_amount = current_amount - 1;
}

void search_info() {
    system("cls");
    int year;
    cout << "������� ���, ����� ����� ��������: ";
    cin >> year;
    cout << "��������� ������: " << endl;
    for (int i = 0; i < current_amount; i++) {
        if (list_guest[i].dateYear == year) {
            cout << i + 1 << " ������: " << endl;
            cout << "���: " << list_guest[i].pass << endl;
            cout << "���� ��������: " << list_guest[i].dateDay / 10 << list_guest[i].dateDay % 10 << '.' << list_guest[i].dateMonth / 10 << list_guest[i].dateMonth % 10 << '.' << list_guest[i].dateYear / 1000 << list_guest[i].dateYear / 100 % 10 << list_guest[i].dateYear / 10 % 10 << list_guest[i].dateYear % 10 << endl;
            cout << "�����: " << list_guest[i].address << endl;
            cout << "���: ";
            switch (list_guest[i].getState())
            {
            case gender::������� :
                cout << "�������" << endl;
                break;
            case gender::�������:
                cout << "�������" << endl;
                break;
            default:
                break;
            }
        }
    }

}