#include <iostream>
#include <Windows.h>
#include <string>
#define max_people 30
using namespace std;
int current_amount = 0;

//12

struct notebook {
	string pass;
	int dateDay : 6;
	int dateMonth : 5;
	int dateYear : 16;
	string address;
	long long numberTelephone;
};

void input_info();
void output_info();
void delete_info();
void search_info();

notebook list_people[max_people];


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

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
    int amountPeople, birthdayDate;

    cout << "������� ���������� ������� ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        cout << current_amount + 1 << " �������:" << endl;
        cout << "������� ���: ";
        cin.ignore();
        getline(cin, list_people[current_amount].pass);
        cout << "������� ���� ��������: ";
        cin >> birthdayDate;
        list_people[current_amount].dateDay = birthdayDate / 10000000 * 10 + birthdayDate / 1000000 % 10;
        list_people[current_amount].dateMonth = (birthdayDate / 100000) % 10 * 10 + (birthdayDate / 10000) % 10;
        list_people[current_amount].dateYear = birthdayDate % 10000;
        cout << "������� �����: ";
        cin.ignore();
        getline(cin, list_people[current_amount].address);
        cout << "������� �������: ";
        cin >> list_people[current_amount].numberTelephone;
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " �������:" << endl;
        cout << "���: " << list_people[i].pass << endl;
        cout << "���� ��������: " << list_people[i].dateDay / 10 << list_people[i].dateDay % 10 << '.' << list_people[i].dateMonth / 10 << list_people[i].dateMonth % 10 << '.' << list_people[i].dateYear / 1000 << list_people[i].dateYear / 100 % 10 << list_people[i].dateYear / 10 % 10 << list_people[i].dateYear % 10 << endl;
        cout << "�����: " << list_people[i].address << endl;
        cout << "�������: " << '+' << list_people[i].numberTelephone << endl;
    }
}
void delete_info() {
    system("cls");
    int numberGuest;
    cout << "������� ����� ��������, �������� �� ������ �������: ";
    cin >> numberGuest;
    for (int del = numberGuest - 1; del < current_amount; del++) {
        list_people[del] = list_people[del + 1];
    }
    current_amount--;
}
void search_info() {
    system("cls");
    string LastNameWrite;
    char buff[50] = {" "};
    int j = 0;
    cout << "������� �������, ������� ������ �����: ";
    cin.ignore();
    getline(cin, LastNameWrite);

    for (int i = 0; i < current_amount; i++) {
        j = 0;
        while (list_people[i].pass[j] != ' ') {
            buff[j] = list_people[i].pass[j];
            j++;
        }
        if (buff == LastNameWrite) {
            cout << i + 1 << " �������:" << endl;
            cout << "���: " << list_people[i].pass << endl;
            cout << "���� ��������: " << list_people[i].dateDay / 10 << list_people[i].dateDay % 10 << '.' << list_people[i].dateMonth / 10 << list_people[i].dateMonth % 10 << '.' << list_people[i].dateYear / 1000 << list_people[i].dateYear / 100 % 10 << list_people[i].dateYear / 10 % 10 << list_people[i].dateYear % 10 << endl;
            cout << "�����: " << list_people[i].address << endl;
            cout << "�������: " << '+' << list_people[i].numberTelephone << endl;
        }
    }
}