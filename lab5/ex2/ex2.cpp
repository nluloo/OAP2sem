#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string.h>

#define max_guest 30

int current_amount = 0;

using namespace std;

void read_amount();

enum type {
    ���� = 1, �����������, �����������, �����������, �����������
};

void input_to_file();
void read_from_file();
void search_info();

union Guest {
    int dayIn;
    int monthIn;
    int yearIn;
    int dayO;
    int monthO;
    int yearO;
    int numberRoom;
    char pass[50];
    type accommodation;

    void setState(type State) {
        this->accommodation = State;
    }
};

Guest list_guest[max_guest];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int choise;
    read_amount();

    do {
        cout << "1. ���� ����������" << endl;
        cout << "2. ����� ����������" << endl;
        cout << "3. ����� ����������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> choise;

        switch (choise) {
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
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� ����. ���������� ��� ���." << endl;
            break;
        }

    } while (choise != 0);

    return 0;
}

void input_to_file() {

    ofstream FILE1("D:\\labs\\oap1.2\\lab5files\\FILE1.txt", ios::app);

    if (!FILE1.is_open()) {
        cout << "fail" << endl;
        exit(EXIT_FAILURE);
    }

    int numberGuest, dateInt, dateOutt, typesAccom;
    cout << "������� ���������� ������� ";
    cin >> numberGuest;

    int cur_size = current_amount;

    for (; current_amount < cur_size + numberGuest; current_amount++) {
        system("cls");
        cout << "���������� " << current_amount + 1 << " �����:" << endl;
        cout << "������� ���������� ������: ";
        cin.ignore();
        cin.getline(list_guest[current_amount].pass, 50);
        FILE1 << list_guest[current_amount].pass << '\n';
        cout << "������� ���� ������� (� ������� ��������): ";
        cin >> dateInt;
        list_guest[current_amount].dayIn = dateInt % 100;
        list_guest[current_amount].monthIn = (dateInt / 100) % 100;
        list_guest[current_amount].yearIn = dateInt / 10000;
        FILE1 << list_guest[current_amount].dayIn << ' ' << list_guest[current_amount].monthIn << ' ' << list_guest[current_amount].yearIn << '\t';
        cout << "������� ���� ������� (� ������� ��������): ";
        cin >> dateOutt;
        list_guest[current_amount].dayO = dateOutt % 100;
        list_guest[current_amount].monthO = (dateOutt / 100) % 100;
        list_guest[current_amount].yearO = dateOutt / 10000;
        FILE1 << list_guest[current_amount].dayO << ' ' << list_guest[current_amount].monthO << ' ' << list_guest[current_amount].yearO << '\t';
        cout << "������� ����� �������: ";
        cin >> list_guest[current_amount].numberRoom;
        FILE1 << list_guest[current_amount].numberRoom << '\t';
        cout << "������� ��� ���������� (1 - ����, 2 - �����������, 3 - �����������, 4 - �����������, 5 - �����������): ";
        cin >> typesAccom;
        switch (typesAccom) {
        case 1:
            list_guest[current_amount].accommodation = ����;
            break;
        case 2:
            list_guest[current_amount].accommodation = �����������;
            break;
        case 3:
            list_guest[current_amount].accommodation = �����������;
            break;
        case 4:
            list_guest[current_amount].accommodation = �����������;
            break;
        case 5:
            list_guest[current_amount].accommodation = �����������;
            break;
        default:
            break;
        }
        FILE1 << list_guest[current_amount].accommodation << endl;
    }
    FILE1.close();

}

void read_from_file() {
    system("cls");
    ifstream fileRead("D:\\labs\\oap1.2\\lab5files\\FILE1.txt");
    int buff;
    char c;

    if (!fileRead) {
        cout << "(((" << endl;
        return;
    }

    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " �����: " << endl;
        fileRead.getline(list_guest[i].pass, 300);
        cout << "���������� ������: " << list_guest[i].pass << endl;
        fileRead >> list_guest[i].dayIn;
        cout << "���� ������: " << list_guest[i].dayIn / 10 << list_guest[i].dayIn % 10 << '.';
        fileRead >> list_guest[i].monthIn;
        cout << list_guest[i].monthIn / 10 << list_guest[i].monthIn % 10 << '.';
        fileRead >> list_guest[i].yearIn;
        cout << list_guest[i].yearIn / 1000 << list_guest[i].yearIn / 100 % 10 << list_guest[i].yearIn / 10 % 10 << list_guest[i].yearIn % 10 << endl;
        fileRead >> list_guest[i].dayO;
        cout << "���� ������: " << list_guest[i].dayO / 10 << list_guest[i].dayO % 10 << '.';
        fileRead >> list_guest[i].monthO;

        cout << list_guest[i].monthO / 10 << list_guest[i].monthO % 10 << '.';
        fileRead >> list_guest[i].yearO;
        cout << list_guest[i].yearO / 1000 << list_guest[i].yearO / 100 % 10 << list_guest[i].yearO / 10 % 10 << list_guest[i].yearO % 10 << endl;
        fileRead >> list_guest[i].numberRoom;
        cout << "����� �������: " << list_guest[i].numberRoom << endl;

        fileRead >> buff;
        fileRead.ignore();
        switch (buff) {
        case 1:
            list_guest[i].accommodation = ����;
            break;
        case 2:
            list_guest[i].accommodation = �����������;
            break;
        case 3:
            list_guest[i].accommodation = �����������;
            break;
        case 4:
            list_guest[i].accommodation = �����������;
            break;
        case 5:
            list_guest[i].accommodation = �����������;
            break;
        default:
            break;
        }
        cout << "��� ����������: ";
        switch (list_guest[i].accommodation) {
        case ����:
            cout << "����" << endl;
            break;
        case �����������:
            cout << "�����������" << endl;
            break;
        case �����������:
            cout << "�����������" << endl;
            break;
        case �����������:
            cout << "�����������" << endl;
            break;
        case �����������:
            cout << "�����������" << endl;
            break;
        default:
            break;
        }
    }

    fileRead.close();
    cout << endl;
    system("pause");
}

void read_amount() {
    ifstream file("D:\\labs\\oap1.2\\lab5files\\FILE1.txt", ios::binary);
    char buff[300];

    if (!file) {
        cout << "(((" << endl;
        return;
    }
    while (file.getline(buff, 300)) {
        current_amount++;
    }
    current_amount /= 2;
    file.close();
}

void search_info() {
    system("cls");
    ifstream fileSearch("D:\\labs\\oap1.2\\lab5files\\FILE1.txt");
    string LastNameWrite;
    char buff[50] = { " " }, c;
    int j = 0, h;
    cout << "������� �������, ������� ������ �����: ";
    cin.ignore();
    getline(cin, LastNameWrite);

    for (int i = 0; i < current_amount; i++) {
        fileSearch.getline(list_guest[i].pass, 300);
        j = 0;
        while (list_guest[i].pass[j] != ' ' && list_guest[i].pass[j] != '\0') {
            buff[j] = list_guest[i].pass[j];
            j++;
        }
        if (buff == LastNameWrite) {
            cout << i + 1 << " �����: " << endl;
            cout << "���������� ������: " << list_guest[i].pass << endl;
            fileSearch >> list_guest[i].dayIn;
            cout << "���� ������: " << list_guest[i].dayIn / 10 << list_guest[i].dayIn % 10 << '.';
            fileSearch >> list_guest[i].monthIn;
            cout << list_guest[i].monthIn / 10 << list_guest[i].monthIn % 10 << '.';
            fileSearch >> list_guest[i].yearIn;
            cout << list_guest[i].yearIn / 1000 << list_guest[i].yearIn / 100 % 10 << list_guest[i].yearIn / 10 % 10 << list_guest[i].yearIn % 10 << endl;
            fileSearch >> list_guest[i].dayO;
            cout << "���� ������: " << list_guest[i].dayO / 10 << list_guest[i].dayO % 10 << '.';
            fileSearch >> list_guest[i].monthO;

            cout << list_guest[i].monthO / 10 << list_guest[i].monthO % 10 << '.';
            fileSearch >> list_guest[i].yearO;
            cout << list_guest[i].yearO / 1000 << list_guest[i].yearO / 100 % 10 << list_guest[i].yearO / 10 % 10 << list_guest[i].yearO % 10 << endl;
            fileSearch >> list_guest[i].numberRoom;
            cout << "����� �������: " << list_guest[i].numberRoom << endl;

            fileSearch >> h;
            fileSearch >> c;
            switch (h) {
            case 1:
                list_guest[current_amount].accommodation = ����;
                break;
            case 2:
                list_guest[current_amount].accommodation = �����������;
                break;
            case 3:
                list_guest[current_amount].accommodation = �����������;
                break;
            case 4:
                list_guest[current_amount].accommodation = �����������;
                break;
            case 5:
                list_guest[current_amount].accommodation = �����������;
                break;
            default:
                break;
            }
            cout << "��� ����������: ";
            switch (list_guest[current_amount].accommodation) {
            case ����:
                cout << "����" << endl;
                continue;
            case �����������:
                cout << "�����������" << endl;
                continue;
            case �����������:
                cout << "�����������" << endl;
                continue;
            case �����������:
                cout << "�����������" << endl;
                continue;
            case �����������:
                cout << "�����������" << endl;
                continue;
            default:
                continue;
            }
        }
        fileSearch.getline(list_guest[i].pass, 300);
    }

    fileSearch.close();
}
