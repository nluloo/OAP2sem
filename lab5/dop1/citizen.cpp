#include <iostream>
#include <string>
#include <windows.h>
#define maxCitizen 30

//2 

int current_amount = 0;

using namespace std;

enum gender {
    Мужской = 1, Женский
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
        cout << "1. Ввод информации" << endl;
        cout << "2. Вывод информации" << endl;
        cout << "3. Удаление информации" << endl;
        cout << "4. Поиск информации" << endl;
        cout << "Выберите действие: ";
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
            cout << "Выход из программы." << endl;
            return 0;
        default:
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            break;
        }

    } while (true);

    return 0;
}


void input_info() {
    system("cls");
    int amountPeople, writeGender, dateIn, dateOut;

    cout << "Введите количество человек ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        system("cls");
        cout << "Информация " << current_amount + 1 << " жителя:" << endl;
        cout << "Введите ФИО: ";
        cin.ignore();
        getline(cin, list_guest[current_amount].pass);
        cout << "Введите дату рождения: ";
        cin >> dateIn;
        cout << "Введите адрес: ";
        cin.ignore();
        getline(cin, list_guest[current_amount].address);
        list_guest[current_amount].dateDay = dateIn / 10000000 * 10 + dateIn / 1000000 % 10;
        list_guest[current_amount].dateMonth = (dateIn / 100000) % 10 * 10 + (dateIn / 10000) % 10;
        list_guest[current_amount].dateYear = dateIn % 10000;
        cout << "Введите пол: ";
        cin >> writeGender;
        switch (writeGender)
        {
        case 1:
            list_guest[current_amount].setState(gender::Мужской);
            break;
        case 2:
            list_guest[current_amount].setState(gender::Женский);
            break;
        default:
            break;
        }
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " житель: " << endl;
        cout << "ФИО: " << list_guest[i].pass << endl;
        cout << "Дата рождения: " << list_guest[i].dateDay / 10 << list_guest[i].dateDay % 10 << '.' << list_guest[i].dateMonth / 10 << list_guest[i].dateMonth % 10 << '.' << list_guest[i].dateYear / 1000 << list_guest[i].dateYear / 100 % 10 << list_guest[i].dateYear / 10 % 10 << list_guest[i].dateYear % 10 << endl;
        cout << "Адрес: " << list_guest[i].address << endl;
        cout << "Пол: ";
        switch (list_guest[i].getState())
        {
        case gender::Мужской:
            cout << "Мужской" << endl;
            break;
        case gender::Женский:
            cout << "Женский" << endl;
            break;
        default:
            break;
        }
    }
}

void delete_info() {
    system("cls");
    int numberPeople;
    cout << "Введите номер жителя, которого вы хотите удалить: ";
    cin >> numberPeople;
    for (int del = numberPeople - 1; del < current_amount; del++) {
        list_guest[del] = list_guest[del + 1];
    }
    current_amount = current_amount - 1;
}

void search_info() {
    system("cls");
    int year;
    cout << "Введите год, чтобы найти человека: ";
    cin >> year;
    cout << "Найденные жители: " << endl;
    for (int i = 0; i < current_amount; i++) {
        if (list_guest[i].dateYear == year) {
            cout << i + 1 << " житель: " << endl;
            cout << "ФИО: " << list_guest[i].pass << endl;
            cout << "Дата рождения: " << list_guest[i].dateDay / 10 << list_guest[i].dateDay % 10 << '.' << list_guest[i].dateMonth / 10 << list_guest[i].dateMonth % 10 << '.' << list_guest[i].dateYear / 1000 << list_guest[i].dateYear / 100 % 10 << list_guest[i].dateYear / 10 % 10 << list_guest[i].dateYear % 10 << endl;
            cout << "Адрес: " << list_guest[i].address << endl;
            cout << "Пол: ";
            switch (list_guest[i].getState())
            {
            case gender::Мужской :
                cout << "Мужской" << endl;
                break;
            case gender::Женский:
                cout << "Женский" << endl;
                break;
            default:
                break;
            }
        }
    }

}