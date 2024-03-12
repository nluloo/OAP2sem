#include <iostream>
#include <string>
#define maxBook 30

//5
int current_amount = 0;

using namespace std;

enum chapterLibrary {
    �������������� = 1, �����, �������������, ������������, ��������������, �������
};
enum originBook
{
    ������� = 1, �����, �������
};

void input_info();
void output_info();
void delete_info();
void search_info();

struct library {
    string author;
    string name;
    string publishing;
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

library library_list[maxBook];

int main() {
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
    int amountPeople, chpLibrary, origBook, precenseBook;

    cout << "������� ���������� ���� ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        system("cls");
        cout << "���������� " << current_amount + 1 << " �����:" << endl;
        cout << "������� ������: ";
        cin.ignore();
        getline(cin, library_list[current_amount].author);
        cout << "������� �������� �����: ";
        getline(cin, library_list[current_amount].name);
        cout << "������� ������������ �����: ";
        getline(cin, library_list[current_amount].publishing);
        cout << "������� ����� ������� ����������: ";
        cin >> chpLibrary;
        switch (chpLibrary)
        {
        case 1:
            library_list[current_amount].setStateChap(chapterLibrary::��������������);
            break;
        case 2:
            library_list[current_amount].setStateChap(chapterLibrary::�������������);
            break;
        case 3:
            library_list[current_amount].setStateChap(chapterLibrary::������������);
            break;
        case 4:
            library_list[current_amount].setStateChap(chapterLibrary::��������������);
            break;
        case 5:
            library_list[current_amount].setStateChap(chapterLibrary::�������);
            break;
        default:
            break;
        }
        cout << "������� �������������: ";
        cin >> origBook;
        switch (origBook)
        {
        case 1:
            library_list[current_amount].setStateOr(originBook::�������);
            break;
        case 2:
            library_list[current_amount].setStateOr(originBook::�����);
            break;
        case 3:
            library_list[current_amount].setStateOr(originBook::�������);
            break;
        default:
            break;
        }
        cout << "�������, ���� �� ����� � �������.";
        cin >> library_list[current_amount].presence;
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " �����: " << endl;
        cout << "����� �����: " << library_list[i].author << endl;
        cout << "�������� �����: " << library_list[i].name << endl;
        cout << "������������: " << library_list[i].publishing << endl;

        cout << "������ ���������� : ";
        switch (library_list[i].getStateChap())
        {
        case chapterLibrary::��������������:
            cout << "��������������" << endl;
            break;
        case chapterLibrary::�������������:
            cout << "�������������" << endl;
            break;
        case chapterLibrary::������������:
            cout << "������������" << endl;
            break;
        case chapterLibrary::��������������:
            cout << "��������������" << endl;
            break;
        case chapterLibrary::�������:
            cout << "�������" << endl;
            break;
        default:
            break;
        }
        cout << "������������� : ";
        switch (library_list[i].getStateOr())
        {
        case originBook::�������:
            cout << "�������" << endl;
            break;
        case originBook::����� :
            cout << "�����" << endl;
            break;
        case originBook::�������:
            cout << "�������" << endl;
            break;
        default:
            break;
        }
        if (library_list[i].presence) {
            cout << "����� ���� � �������!" << endl;
        }
        else
            cout << "����� ���(" << endl;
    }
}

void delete_info() {
    system("cls");
    int numberGuest;
    cout << "������� ����� �����, �������� �� ������ �������: ";
    cin >> numberGuest;
    for (int del = numberGuest - 1; del < current_amount; del++) {
        library_list[del] = library_list[del + 1];
    }
    current_amount = current_amount - 1;
}

void search_info() {
    system("cls");
    int presenceBook;
    cout << "�������, ��� ������ �������: ";
    cin >> presenceBook;
    for (int i = 0; i < current_amount; i++) {
        if (library_list[i].presence == presenceBook) {
            cout << i + 1 << " �����: " << endl;
            cout << "����� �����: " << library_list[i].author << endl;
            cout << "�������� �����: " << library_list[i].name << endl;
            cout << "������������: " << library_list[i].publishing << endl;

            cout << "������ ���������� : ";
            switch (library_list[i].getStateChap())
            {
            case chapterLibrary::��������������:
                cout << "��������������" << endl;
                break;
            case chapterLibrary::�������������:
                cout << "�������������" << endl;
                break;
            case chapterLibrary::������������:
                cout << "������������" << endl;
                break;
            case chapterLibrary::��������������:
                cout << "��������������" << endl;
                break;
            case chapterLibrary::�������:
                cout << "�������" << endl;
                break;
            default:
                break;
            }
            cout << "������������� : ";
            switch (library_list[i].getStateOr())
            {
            case originBook::�������:
                cout << "�������" << endl;
                break;
            case originBook::�����:
                cout << "�����" << endl;
                break;
            case originBook::�������:
                cout << "�������" << endl;
                break;
            default:
                break;
            }
        }
    }
}