#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string.h>

#define max_train 30

int current_amount = 0;

using namespace std;

void read_amount();

void input_to_file();
void read_from_file();
void search_info();

union RailWay {
    int NumberTrain;
    char address[300];
};

RailWay list_train[max_train];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int choice;
    read_amount();

    do {
        cout << "1. Ввод информации" << endl;
        cout << "2. Вывод информации" << endl;
        cout << "3. Поиск информации" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            input_to_file();
            break;
        case 2:
            read_from_file();
            break;
        case 3:
            search_info();
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}

void input_to_file() {

    ofstream FILE1("D:\\labs\\oap1.2\\lab5files\\dop1.2\\FILE1.txt", ios::app);

    if (!FILE1.is_open()) {
        cout << "fail" << endl;
        exit(EXIT_FAILURE);
    }

    int numberTrains;
    cout << "Введите количество поездов ";
    cin >> numberTrains;

    int cur_size = current_amount;

    for (; current_amount < cur_size + numberTrains; current_amount++) {
        system("cls");
        cout << "Информация " << current_amount + 1 << " поезда:" << endl;
        cout << "Введите номер поезда: ";
        cin >> list_train[current_amount].NumberTrain;
        FILE1 << list_train[current_amount].NumberTrain << '\n';
        cout << "Введите пункт назначения: ";
        cin.ignore();
        cin.getline(list_train[current_amount].address, 100);
        FILE1 << list_train[current_amount].address << '\n';
        cout << "Введите дни следования: ";
        cin.getline(list_train[current_amount].address, 100);
        FILE1 << list_train[current_amount].address << '\t';
        cout << "Введите время прибытия: ";
        cin >> list_train[current_amount].NumberTrain;
        FILE1 << list_train[current_amount].NumberTrain << '\t';
        cout << "Введите время отправления: ";
        cin >> list_train[current_amount].NumberTrain;
        FILE1 << list_train[current_amount].NumberTrain << '\n';
    }
    FILE1.close();

}

void read_from_file() {
    system("cls");
    ifstream fileRead("D:\\labs\\oap1.2\\lab5files\\dop1.2\\FILE1.txt");
    int buff;
    char c;

    if (!fileRead) {
        cout << "(((" << endl;
        return;
    }

    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " поезд: " << endl;
        fileRead >> list_train[i].NumberTrain;
        fileRead.ignore();
        cout << "Номер поезда: " << list_train[i].NumberTrain << endl;
        fileRead.getline(list_train[i].address, 100);
        cout << "Пункт назначения: " << list_train[i].address << endl;
        fileRead >> list_train[i].address;
        cout << "Дни следования: " << list_train[i].address << endl;
        fileRead >> list_train[i].NumberTrain;
        cout << "Время прибытия: " << list_train[i].NumberTrain / 1000 << list_train[i].NumberTrain / 100 % 10 << ':' << list_train[i].NumberTrain % 100 / 10 << list_train[i].NumberTrain % 10 << endl;
        fileRead >> list_train[i].NumberTrain;
        cout << "Время отправления: " << list_train[i].NumberTrain / 1000 << list_train[i].NumberTrain / 100 % 10 << ':' << list_train[i].NumberTrain % 100 / 10 << list_train[i].NumberTrain % 10 << endl;

        fileRead.ignore();
    }

    fileRead.close();
    cout << endl;
    system("pause");
}

void read_amount() {
    ifstream file("D:\\labs\\oap1.2\\lab5files\\dop1.2\\FILE1.txt", ios::binary);
    char buff[300];

    if (!file) {
        cout << "(((" << endl;
        return;
    }
    while (file.getline(buff, 300)) {
        current_amount++;
    }
    current_amount /= 3;
    file.close();
}


void search_info() {
    system("cls");
    ifstream fileSearch("D:\\labs\\oap1.2\\lab5files\\dop1.2\\FILE1.txt");
    string LastNameWrite;
    char buff[50] = { " " };
    int c;
    cout << "Введите пункт назначения: ";
    cin.ignore();
    getline(cin, LastNameWrite);

    for (int i = 0; i < current_amount; i++) {
        fileSearch >> c;
        fileSearch.ignore();
        fileSearch.getline(list_train[i].address, 300);
        if (list_train[i].address == LastNameWrite) {
            cout << i + 1 << " поезд: " << endl;
            cout << "Номер поезда: " << c << endl;
            cout << "Пункт назначения: " << list_train[i].address << endl;
            fileSearch >> list_train[i].address;
            cout << "Дни следования: " << list_train[i].address << endl;
            fileSearch >> list_train[i].NumberTrain;
            cout << "Время прибытия: " << list_train[i].NumberTrain / 1000 << list_train[i].NumberTrain / 100 % 10 << ':' << list_train[i].NumberTrain % 100 / 10 << list_train[i].NumberTrain % 10 << endl;
            fileSearch >> list_train[i].NumberTrain;
            cout << "Время отправления: " << list_train[i].NumberTrain / 1000 << list_train[i].NumberTrain / 100 % 10 << ':' << list_train[i].NumberTrain % 100 / 10 << list_train[i].NumberTrain % 10 << endl;

        }
        fileSearch.getline(list_train[i].address, 300);
    }

    fileSearch.close();
}
