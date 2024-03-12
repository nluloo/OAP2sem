#include <iostream>
#include <string>
#define maxBook 30

//5
int current_amount = 0;

using namespace std;

enum chapterLibrary {
    Спецлитература = 1, хобби, беллетристика, саморазвитие, художественная, научная
};
enum originBook
{
    Покупка = 1, Кража, Подарок
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
    int amountPeople, chpLibrary, origBook, precenseBook;

    cout << "Введите количество книг ";
    cin >> amountPeople;

    int cur_size = current_amount;

    for (; current_amount < cur_size + amountPeople; current_amount++) {
        system("cls");
        cout << "Информация " << current_amount + 1 << " книги:" << endl;
        cout << "Введите автора: ";
        cin.ignore();
        getline(cin, library_list[current_amount].author);
        cout << "Введите название книги: ";
        getline(cin, library_list[current_amount].name);
        cout << "Введите издательство книги: ";
        getline(cin, library_list[current_amount].publishing);
        cout << "Введите номер раздела библиотеки: ";
        cin >> chpLibrary;
        switch (chpLibrary)
        {
        case 1:
            library_list[current_amount].setStateChap(chapterLibrary::Спецлитература);
            break;
        case 2:
            library_list[current_amount].setStateChap(chapterLibrary::беллетристика);
            break;
        case 3:
            library_list[current_amount].setStateChap(chapterLibrary::саморазвитие);
            break;
        case 4:
            library_list[current_amount].setStateChap(chapterLibrary::художественная);
            break;
        case 5:
            library_list[current_amount].setStateChap(chapterLibrary::научная);
            break;
        default:
            break;
        }
        cout << "Введите происхождение: ";
        cin >> origBook;
        switch (origBook)
        {
        case 1:
            library_list[current_amount].setStateOr(originBook::Покупка);
            break;
        case 2:
            library_list[current_amount].setStateOr(originBook::Кража);
            break;
        case 3:
            library_list[current_amount].setStateOr(originBook::Подарок);
            break;
        default:
            break;
        }
        cout << "Введите, есть ли книга в наличии.";
        cin >> library_list[current_amount].presence;
    }
}

void output_info() {
    system("cls");
    for (int i = 0; i < current_amount; i++) {
        cout << i + 1 << " книга: " << endl;
        cout << "Автор книги: " << library_list[i].author << endl;
        cout << "Название книги: " << library_list[i].name << endl;
        cout << "Издательство: " << library_list[i].publishing << endl;

        cout << "Раздел библиотеки : ";
        switch (library_list[i].getStateChap())
        {
        case chapterLibrary::Спецлитература:
            cout << "Спецлитература" << endl;
            break;
        case chapterLibrary::беллетристика:
            cout << "беллетристика" << endl;
            break;
        case chapterLibrary::саморазвитие:
            cout << "саморазвитие" << endl;
            break;
        case chapterLibrary::художественная:
            cout << "художественная" << endl;
            break;
        case chapterLibrary::научная:
            cout << "научная" << endl;
            break;
        default:
            break;
        }
        cout << "Происхождение : ";
        switch (library_list[i].getStateOr())
        {
        case originBook::Покупка:
            cout << "Покупка" << endl;
            break;
        case originBook::Кража :
            cout << "Кража" << endl;
            break;
        case originBook::Подарок:
            cout << "Подарок" << endl;
            break;
        default:
            break;
        }
        if (library_list[i].presence) {
            cout << "Книга есть в наличии!" << endl;
        }
        else
            cout << "Книги нет(" << endl;
    }
}

void delete_info() {
    system("cls");
    int numberGuest;
    cout << "Введите номер книги, которого вы хотите удалить: ";
    cin >> numberGuest;
    for (int del = numberGuest - 1; del < current_amount; del++) {
        library_list[del] = library_list[del + 1];
    }
    current_amount = current_amount - 1;
}

void search_info() {
    system("cls");
    int presenceBook;
    cout << "Введите, что хотите сделать: ";
    cin >> presenceBook;
    for (int i = 0; i < current_amount; i++) {
        if (library_list[i].presence == presenceBook) {
            cout << i + 1 << " книга: " << endl;
            cout << "Автор книги: " << library_list[i].author << endl;
            cout << "Название книги: " << library_list[i].name << endl;
            cout << "Издательство: " << library_list[i].publishing << endl;

            cout << "Раздел библиотеки : ";
            switch (library_list[i].getStateChap())
            {
            case chapterLibrary::Спецлитература:
                cout << "Спецлитература" << endl;
                break;
            case chapterLibrary::беллетристика:
                cout << "беллетристика" << endl;
                break;
            case chapterLibrary::саморазвитие:
                cout << "саморазвитие" << endl;
                break;
            case chapterLibrary::художественная:
                cout << "художественная" << endl;
                break;
            case chapterLibrary::научная:
                cout << "научная" << endl;
                break;
            default:
                break;
            }
            cout << "Происхождение : ";
            switch (library_list[i].getStateOr())
            {
            case originBook::Покупка:
                cout << "Покупка" << endl;
                break;
            case originBook::Кража:
                cout << "Кража" << endl;
                break;
            case originBook::Подарок:
                cout << "Подарок" << endl;
                break;
            default:
                break;
            }
        }
    }
}