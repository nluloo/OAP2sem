#include <iostream>
using namespace std;

struct Tree {
    int key;
    char str[5];
    Tree* left, * right;
};

Tree* create_tree(Tree*);
Tree* add_list(Tree*, int, char*);
Tree* create_list(int, char*);
Tree* Root = nullptr;

Tree* create_tree(Tree* Root) {
    int key;
    char data[5];
    if (Root == nullptr) {
        cout << "Введите ключ: ";
        cin >> key;
        cout << "Введите строку(до 5 символов): ";
        cin.ignore();
        cin.getline(data, 5);
        Root = create_list(key, data);
    }
    else {
        cout << "Введите ключ: ";
        cin >> key;
        cout << "Введите строку(до 5 символов): ";
        cin.ignore();
        cin.getline(data, 5);
        add_list(Root, key, data);
    }
    return Root;
}

Tree* create_list(int key, char* data) {
    Tree* t = new Tree();
    t->key = key;
    for (int i = 0; data[i] != '\0'; i++) {
        t->str[i] = data[i];
    }
    t->left = t->right = nullptr;
    return t;
}

Tree* add_list(Tree* root, int key, char* data) {
    if (root == nullptr)
        return create_list(key, data);

    if (key < root->key)
        root->left = add_list(root->left, key, data);
    else if (key > root->key)
        root->right = add_list(root->right, key, data);

    return root;
}

int view(Tree* t, int level) {
    if (t) {
        view(t->right, level + 1);
        for (int i = 0; i < level; i++)
            cout << "   ";
        int tm = t->key;
        cout << tm << ' ';
        cout << t->str << endl;
        view(t->left, level + 1);
        return 0;
    }
    return 1;
}

int count_elements_rigth(Tree* Root) {
    int count = 0;
    if (Root != nullptr) {
        count++; 
        count += count_elements_rigth(Root->right);
        count += count_elements_rigth(Root->left);
    }
    return count;
}

void menu() {
    cout << "1. Создание дерева" << endl;
    cout << "2. Добавление нового элемента" << endl;
    cout << "3. Вывод дерева " << endl;
    cout << "4. Количество элементов правого поддерева" << endl;
    cout << "5. Выход" << endl; 
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice, key;
    char data[5];
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            Root = create_tree(Root);
            break;
        case 2:
            cin >> key;
            cin.ignore();
            cin.getline(data, 5);
            Root = add_list(Root, key, data);
            break;
        case 3:
            view(Root, 0);
            break;
        case 4:
            if (Root == nullptr) continue;
            cout << "Количество элементов правого поддерева: " << count_elements_rigth(Root->right) << endl;
            break;
        case 5:
            cout << "Выход из программы." << endl;
            return 0;
        default:
            break;
        }
    } while (true);
    return 0;
}
