#include <iostream>
using namespace std;

struct Tree {
    int key;
    int data;
    Tree* left, * right;
};

Tree* create_tree();
Tree* add_list(Tree*, int, int);
Tree* create_list(int, int);
Tree* Root = nullptr;

Tree* create_tree() {
    int key, data;
    cout << "Введите ключ: ";
    cin >> key;
    cout << "Введите значение: ";
    cin >> data;
    Root = create_list(key, data);
    return Root;
}

Tree* create_list(int key, int data) {
    Tree* t = new Tree;
    t->key = key;
    t->data = data;
    t->left = t->right = nullptr;
    return t;
}

Tree* add_list(Tree* t, int key, int data) { // Дазодим до нужного места без всяких переменных и вставляем туда новый узел
    if (t == nullptr)
        return create_list(key, data);

    if (key < t->key)
        t->left = add_list(t->left, key, data);
    else if (key > t->key)
        t->right = add_list(t->right, key, data);

    return t;
}

int view(Tree* t, int level) {
    if (t) {
        view(t->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        int tm = t->key;
        cout << tm << ' ';
        cout << t->data << endl;
        view(t->left, level + 1);
        return 0;
    }
    return 1;
}

int sum_elements_tree(Tree* Root) {
    if (Root == nullptr)
        return 0;

    int sum = Root->data;
    sum += sum_elements_tree(Root->right);
    sum += sum_elements_tree(Root->left);

    return sum;
}

int elements_tree(Tree* Root) {
    if (Root == nullptr)
        return 0;

    int count = 1;
    count += elements_tree(Root->right);
    count += elements_tree(Root->left);

    return count;
}

void menu() {
    cout << "1. Создание дерева" << endl;
    cout << "2. Добавление нового элемента" << endl;
    cout << "3. Вывод дерева " << endl;
    cout << "4. Нахождение среднего арифметического" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice, key, data;
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            Root = create_tree();
            break;
        case 2:
            cin >> key;
            cin >> data;
            Root = add_list(Root, key, data);
            break;
        case 3:
            view(Root, 0);
            break;
        case 4:
            cout << "Среднее арифметическое: " << sum_elements_tree(Root) / elements_tree(Root) << endl;
            break;
        default:
            break;
        }
    } while (choice != 0); // Выход из цикла при выборе 0
    return 0;
}
