#include <iostream>
#include <string>
#define maxGost 30

int current_amount = 0;

using namespace std;

enum type {
	Люкс = 1, Одноместный, Двухместный, Трехместный, Апартаменты
};

void input_info();
void output_info();
void delete_info();
void search_info();

struct listGoust {
	string pass;
    int dateDayIn : 6;
	int dateMonthIn : 5;
	int dateYearIn : 16;
	int dateDayOut : 6;
	int dateMonthOut : 5;
	int dateYearOut : 16;
	int numberRoom;
	type accommodation;

    int getState() {
        return accommodation;
    }

    void setState(type State) {
        this->accommodation = State;
    }

	};

listGoust list_guest[maxGost];

int main() {
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
    int amountPeople, typesAccom, dateIn, dateOut;
    
    cout << "Введите количество человек ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        system("cls");
        cout << "Информация " << current_amount + 1 << " гостя:" << endl;
        cout << "Введите паспортный данные: ";
        cin.ignore();
        cin >> list_guest[current_amount].pass;
        cout << "Введите дату приезда: ";
        cin >> dateIn;
        list_guest[current_amount].dateDayIn = dateIn / 10000000 * 10 + dateIn / 1000000 % 10;
        list_guest[current_amount].dateMonthIn = (dateIn / 100000) % 10 * 10 + (dateIn / 10000) % 10;
        list_guest[current_amount].dateYearIn = dateIn % 10000;
        cout << "Введите дату отъезда: ";
        cin >> dateOut;
        list_guest[current_amount].dateDayOut = dateOut / 10000000 * 10 + dateOut / 1000000 % 10;
        list_guest[current_amount].dateMonthOut = (dateOut / 100000) % 10 * 10 + (dateOut / 10000) % 10;
        list_guest[current_amount].dateYearOut = dateOut % 10000;
        cout << "Введите номер комнаты: ";
        cin >> list_guest[current_amount].numberRoom;
        cout << "Введите тип размещения: ";
        cin >> typesAccom;
        switch (typesAccom)
        {
        case 1:
            list_guest[current_amount].setState(type::Люкс);
            break;
        case 2:
            list_guest[current_amount].setState(type::Одноместный);
            break;
        case 3:
            list_guest[current_amount].setState(type::Двухместный);
            break;
        case 4:
            list_guest[current_amount].setState(type::Трехместный);
            break;
        case 5:
            list_guest[current_amount].setState(type::Апартаменты);
            break;
        default:
            break;
        }
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " гость: " << endl;
        cout << "Паспортные данные: " << list_guest[i].pass << endl;
        cout << "Дата заезда: " << list_guest[i].dateDayIn / 10 << list_guest[i].dateDayIn % 10 << '.' << list_guest[i].dateMonthIn / 10 << list_guest[i].dateMonthIn % 10 << '.' << list_guest[i].dateYearIn / 1000 << list_guest[i].dateYearIn / 100 % 10 << list_guest[i].dateYearIn / 10 % 10 << list_guest[i].dateYearIn % 10 << endl;
        cout << "Дата выезда: " << list_guest[i].dateDayOut / 10 << list_guest[i].dateDayOut % 10 << '.' << list_guest[i].dateMonthOut / 10 << list_guest[i].dateMonthOut % 10 << '.' << list_guest[i].dateYearOut / 1000 << list_guest[i].dateYearOut / 100 % 10 << list_guest[i].dateYearOut / 10 % 10 << list_guest[i].dateYearOut % 10 << endl;
        cout << "Номер комнаты: " << list_guest[i].numberRoom << endl;
        cout << "Тип расположения: ";
        switch (list_guest[i].getState())
        {
        case type::Люкс:
            cout << "Люкс" << endl;
        break;
        case type::Одноместный:
            cout << "Одноместный" << endl;
            break;
        case type::Двухместный:
            cout << "Двухместный" << endl;
            break;
        case type::Трехместный:
            cout << "Трехместный" << endl;
            break;
        case type::Апартаменты:
            cout << "Апартаменты" << endl;
            break;
        default:
            break;
        }
    }
}

void delete_info() {
    system("cls");
    int numberGuest;
    cout << "Введите номер гостя, которого вы хотите удалить: ";
    cin >> numberGuest;
    for (int del = numberGuest - 1; del < current_amount; del++) {
        list_guest[del] = list_guest[del + 1];
    }
    current_amount--;
}

void search_info() {
    system("cls");
    int date, day, month, year;
    int count = 0;
    cout << "Введите дату приезда: ";
    cin >> date;
    day = date / 10000000 * 10 + date / 1000000 % 10;
    month = (date / 100000) % 10 * 10 + (date / 10000) % 10;
    year = date % 10000;
    cout << "Найденные гости: ";
    for (int i = 0; i < current_amount; i++) {
        count = 0;
        if (list_guest[i].dateDayIn == day) count++;
        if (list_guest[i].dateMonthIn == month) count++;
        if (list_guest[i].dateYearIn == year) count++;
        if (count == 3) {
            cout << i + 1 << " гость: " << endl;
            cout << "Паспортные данные: " << list_guest[i].pass << endl;
            cout << "Дата заезда: " << list_guest[i].dateDayIn / 10 << list_guest[i].dateDayIn % 10 <<  '.' << list_guest[i].dateMonthIn / 10 << list_guest[i].dateMonthIn % 10 << '.' << list_guest[i].dateYearIn / 1000 << list_guest[i].dateYearIn / 100 % 10 << list_guest[i].dateYearIn / 10 % 10 << list_guest[i].dateYearIn % 10 << endl;
            cout << "Дата заезда: " << list_guest[i].dateDayOut / 10 << list_guest[i].dateDayOut % 10 << '.' << list_guest[i].dateMonthOut / 10 << list_guest[i].dateMonthOut % 10 << '.' << list_guest[i].dateYearOut / 1000 << list_guest[i].dateYearOut / 100 % 10 << list_guest[i].dateYearOut / 10 % 10 << list_guest[i].dateYearOut % 10 << endl;
            cout << "Номер комнаты: " << list_guest[i].numberRoom << endl;
            cout << "Тип расположения: ";
            switch (list_guest[i].getState())
            {
            case type::Люкс:
                cout << "Люкс" << endl;
                break;
            case type::Одноместный:
                cout << "Одноместный" << endl;
                break;
            case type::Двухместный:
                cout << "Двухместный" << endl;
                break;
            case type::Трехместный:
                cout << "Трехместный" << endl;
                break;
            case type::Апартаменты:
                cout << "Апартаменты" << endl;
                break;
            default:
                break;
            }
        }
    }

}