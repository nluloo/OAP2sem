#include <iostream>
#include <fstream>
using namespace std;

struct list
{
    char symbol;
    list* next;
};

void insert(list*& p, char value); // Add character to the beginning of the list
void printList(list* p);           // Print the list
void toFile(list* p);              // Write to file
void fromFile(list*& p);           // Read from file
void menu();                       // Display menu

int main()
{
    setlocale(LC_CTYPE, "Russian");
    list* first = nullptr;
    int choice;
    char value;
    menu(); // Display menu
    cout << " ? ";
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
            cout << "Введите символ ";
            cin >> value;
            insert(first, value);
            printList(first);
            break;
        case 2:
            toFile(first);
            break;
        case 3:
            fromFile(first);
            printList(first); // Print the list after reading from file
            break;
        default:
            cout << "Неправильный выбор" << endl;
            break;
        }
        cout << "?  ";
        cin >> choice;
    }
    return 0;
}

void insert(list*& p, char value)
{
    list* newP = new list;
    if (newP != nullptr)
    {
        newP->symbol = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p)
{
    if (p == nullptr)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != nullptr)
        {
            cout << "-->" << p->symbol;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list* p)
{
    ofstream frm("mList.dat", ios::binary);
    if (!frm)
    {
        cout << "\nОшибка открытия файла";
        return;
    }

    while (p != nullptr)
    {
        frm.write(reinterpret_cast<char*>(p), sizeof(list));
        p = p->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p)
{
    ifstream frm("mList.dat", ios::binary);
    if (!frm)
    {
        cout << "\nОшибка открытия файла";
        return;
    }

    list* temp = nullptr;
    list buf;

    while (frm.read(reinterpret_cast<char*>(&buf), sizeof(list)))
    {
        temp = new list;
        temp->symbol = buf.symbol;
        temp->next = p;
        p = temp;
    }
    frm.close();
    cout << "Список считан из файла mList.dat\n";
}

void menu()
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод символа" << endl;
    cout << " 2 - Запись списка в файл" << endl;
    cout << " 3 - Чтение списка из файла" << endl;
    cout << " 4 - Выход" << endl;
}
