#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <string.h>

#define max_books 30

int current_amount = 0;

using namespace std;

void read_amount();

enum chapterLibrary {
    �������������� = 1, �����, �������������, ������������, ��������������, �������
};
enum originBook
{
    ������� = 1, �����, �������
};

void input_to_file();
void read_from_file();
void search_info();

union library {
    char author[100];
    chapterLibrary chapter;
    originBook origin;

    int getStateChap() {
        return chapter;
    }
    int getStateOr() {
        return origin;
    }

    void setStateChap(chapterLibrary State) {
        this->chapter = State;
    }
    void setStateOr(originBook State) {
        this->origin = State;
    }
    bool presence;
};

library list_books[max_books];

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru");
    int choice;
    read_amount();

    do {
        cout << "1. ���� ����������" << endl;
        cout << "2. ����� ����������" << endl;
        cout << "3. ����� ����������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
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
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "�������� ����. ���������� ��� ���." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}

void input_to_file() {

    ofstream FILE1("D:\\labs\\oap1.2\\lab5files\\dop2.2\\FILE1.txt", ios::app);

    if (!FILE1.is_open()) {
        cout << "fail" << endl;
        exit(EXIT_FAILURE);
    }

    int numberGuest, dateInt, dateOutt, typesAccom;
    int amountPeople, chpLibrary, origBook, precenseBook;
    cout << "������� ���������� ���� ";
    cin >> numberGuest;

    int cur_size = current_amount;

    for (; current_amount < cur_size + numberGuest; current_amount++) {
        system("cls");
        cout << "���������� " << current_amount + 1 << " �����:" << endl;
        cout << "������� ������: ";
        cin.ignore();
        cin.getline(list_books[current_amount].author, 100);
        FILE1 << list_books[current_amount].author << '\n';
        cout << "������� �������� �����: ";
        cin.getline(list_books[current_amount].author, 100);
        FILE1 << list_books[current_amount].author << '\n';
        cout << "������� ������������ �����: ";
        cin.getline(list_books[current_amount].author, 100);
        FILE1 << list_books[current_amount].author << '\n';
        cout << "������� ����� ������� ����������: ";
        cin >> chpLibrary;
        switch (chpLibrary)
        {
        case 1:
            list_books[current_amount].setStateChap(chapterLibrary::��������������);
            break;
        case 2:
            list_books[current_amount].setStateChap(chapterLibrary::�������������);
            break;
        case 3:
            list_books[current_amount].setStateChap(chapterLibrary::������������);
            break;
        case 4:
            list_books[current_amount].setStateChap(chapterLibrary::��������������);
            break;
        case 5:
            list_books[current_amount].setStateChap(chapterLibrary::�������);
            break;
        default:
            break;
        }
        FILE1 << list_books[current_amount].chapter << '\t';
        cout << "������� �������������: ";
        cin >> origBook;
        switch (origBook)
        {
        case 1:
            list_books[current_amount].setStateOr(originBook::�������);
            break;
        case 2:
            list_books[current_amount].setStateOr(originBook::�����);
            break;
        case 3:
            list_books[current_amount].setStateOr(originBook::�������);
            break;
        default:
            break;
        }
        FILE1 << list_books[current_amount].origin << '\t';
        cout << "�������, ���� �� ����� � �������.";
        cin >> list_books[current_amount].presence;
        FILE1 << list_books[current_amount].presence << '\n';
    }
    FILE1.close();

}

void read_from_file() {
    system("cls");
    ifstream fileRead("D:\\labs\\oap1.2\\lab5files\\dop2.2\\FILE1.txt");
    int buff;
    char c;

    if (!fileRead) {
        cout << "(((" << endl;
        return;
    }

    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " �����: " << endl;
        fileRead.getline(list_books[i].author, 100);
        cout << "����� �����: " << list_books[i].author << endl;
        fileRead.getline(list_books[i].author, 100);
        cout << "�������� �����: " << list_books[i].author << endl;
        fileRead.getline(list_books[i].author, 100);
        cout << "������������ �����: " << list_books[i].author << endl;
        fileRead >> buff;
        fileRead.ignore();
        switch (buff) {
        case 1:
            list_books[i].chapter = ��������������;
            break;
        case 2:
            list_books[i].chapter = �������������;
            break;
        case 3:
            list_books[i].chapter = ������������;
            break;
        case 4:
            list_books[i].chapter = ��������������;
            break;
        case 5:
            list_books[i].chapter = �������;
            break;
        default:
            break;
        }
        cout << "����� ������� ����������: ";
        switch (list_books[i].chapter) {
        case ��������������:
            cout << "��������������" << endl;
            break;
        case �������������:
            cout << "�������������" << endl;
            break;
        case ������������:
            cout << "������������" << endl;
            break;
        case ��������������:
            cout << "��������������" << endl;
            break;
        case �������:
            cout << "�������" << endl;
            break;
        default:
            break;
        }
        ////////////
        fileRead >> buff;
        fileRead.ignore();
        switch (buff) {
        case 1:
            list_books[i].origin = �������;
            break;
        case 2:
            list_books[i].origin = �����;
            break;
        case 3:
            list_books[i].origin = �������;
            break;
        default:
            break;
        }
        cout << "������������� �����: ";
        switch (list_books[i].chapter) {
        case �������:
            cout << "�������" << endl;
            break;
        case �����:
            cout << "�����" << endl;
            break;
        case �������:
            cout << "�������" << endl;
            break;
        default:
            break;
        }
        fileRead >> list_books[i].presence;
        fileRead.ignore();
        cout << "�������� �����: ";
        switch (list_books[i].presence)
        {
        case 0:
            cout << "�� � �������." << endl;
            break;
        case 1:
            cout << "� �������." << endl;
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
    ifstream file("D:\\labs\\oap1.2\\lab5files\\dop2.2\\FILE1.txt", ios::binary);
    char buff[300];

    if (!file) {
        cout << "(((" << endl;
        return;
    }
    while (file.getline(buff, 300)) {
        current_amount++;
    }
    current_amount /= 4;
    file.close();
}

void search_info() {
    system("cls");
    ifstream fileSearch("D:\\labs\\oap1.2\\lab5files\\dop2.2\\FILE1.txt");
    string LastNameWrite;
    char buff[50] = { " " }, c;
    int j = 0, h;
    cout << "������� �������, ������� ������ �����: ";
    cin.ignore();
    getline(cin, LastNameWrite);

    for (int i = 0; i < current_amount; i++) {
        fileSearch.getline(list_books[i].author, 300);
        j = 0;
        if (list_books[i].author == LastNameWrite) {
            cout << i + 1 << " �����: " << endl;
            cout << "����� �����: " << list_books[i].author << endl;
            fileSearch.getline(list_books[i].author, 100);
            cout << "�������� �����: " << list_books[i].author << endl;
            fileSearch.getline(list_books[i].author, 100);
            cout << "������������ �����: " << list_books[i].author << endl;
            fileSearch >> h;
            fileSearch.ignore();
            switch (h) {
            case 1:
                list_books[i].chapter = ��������������;
                break;
            case 2:
                list_books[i].chapter = �������������;
                break;
            case 3:
                list_books[i].chapter = ������������;
                break;
            case 4:
                list_books[i].chapter = ��������������;
                break;
            case 5:
                list_books[i].chapter = �������;
                break;
            default:
                break;
            }
            cout << "����� ������� ����������: ";
            switch (list_books[i].chapter) {
            case ��������������:
                cout << "��������������" << endl;
                break;
            case �������������:
                cout << "�������������" << endl;
                break;
            case ������������:
                cout << "������������" << endl;
                break;
            case ��������������:
                cout << "��������������" << endl;
                break;
            case �������:
                cout << "�������" << endl;
                break;
            default:
                break;
            }
            ////////////
            fileSearch >> h;
            fileSearch.ignore();
            switch (h) {
            case 1:
                list_books[i].origin = �������;
                break;
            case 2:
                list_books[i].origin = �����;
                break;
            case 3:
                list_books[i].origin = �������;
                break;
            default:
                break;
            }
            cout << "������������� �����: ";
            switch (list_books[i].chapter) {
            case �������:
                cout << "�������" << endl;
                break;
            case �����:
                cout << "�����" << endl;
                break;
            case �������:
                cout << "�������" << endl;
                break;
            default:
                break;
            }
            fileSearch >> list_books[i].presence;
            fileSearch.ignore();
            cout << "�������� �����: ";
            switch (list_books[i].presence)
            {
            case 0:
                cout << "�� � �������." << endl;
                continue;
            case 1:
                cout << "� �������." << endl;
                continue;
            default:
                continue;
            }
        }
        for (int g = 0; g < 3; g++) {
            fileSearch.getline(list_books[i].author, 100);
        }
    }

    fileSearch.close();
}