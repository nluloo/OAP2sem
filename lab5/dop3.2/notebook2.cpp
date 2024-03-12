#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string.h>

#define max_people 30

int current_amount = 0;

using namespace std;

void read_amount();

void input_to_file();
void read_from_file();
void search_info();

union RailWay {
    int NumberTrain;
    char address[300];
    int date;
};

RailWay list_people[max_people];

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

    ofstream FILE1("D:\\labs\\oap1.2\\lab5files\\dop3.2\\FILE1.txt", ios::app);
    int date;

    if (!FILE1.is_open()) {
        cout << "fail" << endl;
        exit(EXIT_FAILURE);
    }

    int numberTrains;
    cout << "Введите количество человек ";
    cin >> numberTrains;

    int cur_size = current_amount;

    for (; current_amount < cur_size + numberTrains; current_amount++) {
        system("cls");
        cout << "Информация " << current_amount + 1 << " человека:" << endl;
        cout << "Введите ФИО: ";
        cin.ignore();
        cin.getline(list_people[current_amount].address, 100);
        FILE1 << list_people[current_amount].address << '\n';
        cout << "Введите дату рождения: ";
        cin >> date;
        list_people[current_amount].date = date / 10000000;
        FILE1 << list_people[current_amount].date;
        list_people[current_amount].date = date / 1000000 % 10;
        FILE1 << list_people[current_amount].date << ' ';
        list_people[current_amount].date = date / 100000 % 10;
        FILE1 << list_people[current_amount].date;
        list_people[current_amount].date = date / 10000 % 10;
        FILE1 << list_people[current_amount].date << ' ';
        list_people[current_amount].date = date / 1000 % 10;
        FILE1 << list_people[current_amount].date;
        list_people[current_amount].date = date / 100 % 10;
        FILE1 << list_people[current_amount].date;
        list_people[current_amount].date = date / 10 % 10;
        FILE1 << list_people[current_amount].date;
        list_people[current_amount].date = date % 10;
        FILE1 << list_people[current_amount].date << '\n';
        cout << "Введите адрес: ";
        cin.ignore();
        cin.getline(list_people[current_amount].address, 100);
        FILE1 << list_people[current_amount].address << '\n';
        cout << "Введите телефон: ";
        cin.getline(list_people[current_amount].address, 100);
        FILE1 << list_people[current_amount].address << '\n';
        cout << "Введите место учебы/работы: ";
        cin.getline(list_people[current_amount].address, 100);
        FILE1 << list_people[current_amount].address << '\n';
        cout << "Введите должность: ";
        cin.getline(list_people[current_amount].address, 100);
        FILE1 << list_people[current_amount].address << '\n';
    }
    FILE1.close();
}



void read_amount() {
    ifstream file("D:\\labs\\oap1.2\\lab5files\\dop3.2\\FILE1.txt", ios::binary);
    char buff[300];

    if (!file) {
        cout << "(((" << endl;
        return;
    }
    while (file.getline(buff, 300)) {
        current_amount++;
    }
    current_amount /= 6;
    file.close();
}


void read_from_file() {
    system("cls");
    ifstream fileRead("D:\\labs\\oap1.2\\lab5files\\dop3.2\\FILE1.txt");
    int buff;
    char c;

    if (!fileRead) {
        cout << "(((" << endl;
        return;
    }

    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " человек: " << endl;
        fileRead.getline(list_people[i].address, 100);
        cout << "ФИО: " << list_people[i].address << endl;
        fileRead >> list_people[i].date;
        cout << "Дата рождения: " << list_people[i].date / 10 << list_people[i].date % 10 << '.';
        fileRead >> list_people[i].date;
        cout << list_people[i].date / 10 << list_people[i].date % 10 << '.';
        fileRead >> list_people[i].date;
        cout << list_people[i].date << endl;
        fileRead.ignore();
        fileRead.getline(list_people[i].address, 100);
        cout << "Адрес: " << list_people[i].address << endl;
        fileRead.getline(list_people[i].address, 100);
        cout << "Телефон: " << list_people[i].address << endl;
        fileRead.getline(list_people[i].address, 100);
        cout << "Место работы/учебы: " << list_people[i].address << endl;
        fileRead.getline(list_people[i].address, 100);
        cout << "Должность: " << list_people[i].address << endl;
    }

    fileRead.close();
    cout << endl;
    system("pause");
}

void search_info() {
    system("cls");
    ifstream fileSearch("D:\\labs\\oap1.2\\lab5files\\dop3.2\\FILE1.txt");
    string LastNameWrite;
    char buff[50] = { " " }, c;
    int j = 0, h;
    cout << "Введите фамилию, которую хотите найти: ";
    cin.ignore();
    getline(cin, LastNameWrite);

    for (int i = 0; i < current_amount; i++) {
        memset(buff, 0, 50);
        fileSearch.getline(list_people[i].address, 300);
        j = 0;
        while (list_people[i].address[j] != ' ' && list_people[i].address[j] != '\0') {
            buff[j] = list_people[i].address[j];
            j++;
        }
        if (buff == LastNameWrite) {
            cout << i + 1 << " человек: " << endl;
            cout << "ФИО: " << list_people[i].address << endl;
            fileSearch >> list_people[i].date;
            cout << "Дата рождения: " << list_people[i].date / 10 << list_people[i].date % 10 << '.';
            fileSearch >> list_people[i].date;
            cout << list_people[i].date / 10 << list_people[i].date % 10 << '.';
            fileSearch >> list_people[i].date;
            cout << list_people[i].date << endl;
            fileSearch.ignore();
            fileSearch.getline(list_people[i].address, 100);
            cout << "Адрес: " << list_people[i].address << endl;
            fileSearch.getline(list_people[i].address, 100);
            cout << "Телефон: " << list_people[i].address << endl;
            fileSearch.getline(list_people[i].address, 100);
            cout << "Место работы/учебы: " << list_people[i].address << endl;
            fileSearch.getline(list_people[i].address, 100);
            cout << "Должность: " << list_people[i].address << endl;
        }
        for(int g = 0; g < 5; g++)
            fileSearch.getline(list_people[i].address, 300);
    }

    fileSearch.close();
}