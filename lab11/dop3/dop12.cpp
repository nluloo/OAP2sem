#include <iostream>
using namespace std;

struct Tree {
    int key;
    int data;
    Tree* left, * right;
};

Tree* create_tree(Tree*);
Tree* add_list(Tree*, int, int);
Tree* create_list(int, int);
Tree* Root = nullptr;

Tree* create_tree(Tree* Root) {
    int key, data;
    if (Root == nullptr) {
        cout << "������� ����: ";
        cin >> key;
        cout << "������� ������: ";
        cin >> data;
        Root = create_list(key, data);
    }
    else {
        cout << "������� ����: ";
        cin >> key;
        cout << "������� ������: ";
        cin >> data;
        add_list(Root, key, data);
    }
    return Root;
}

Tree* create_list(int key, int data) {
    Tree* t = new Tree;
    t->key = key;
    t->data = data;
    t->left = t->right = nullptr;
    return t;
}

Tree* add_list(Tree* t, int key, int data) { // ������� �� ������� ����� ��� ������ ���������� � ��������� ���� ����� ����
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
int elements_tree(Tree* Root) {
    int count = 0;

    if (Root != nullptr) {
        count += elements_tree(Root->right);
        count += elements_tree(Root->left);
        if (Root->key % 2 == 0) count++;
    }
    return count;
}
void menu() {
    cout << "1. �������� ������" << endl;
    cout << "2. ���������� ������ ��������" << endl;
    cout << "3. ����� ������ " << endl;
    cout << "4. ���������� ���������, � ������� ���� ������ 2" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int choice, key, data;
    do {
        menu();
        cin >> choice;
        switch (choice) {
        case 1:
            Root = create_tree(Root);
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
            cout << "���������� ���������: " << elements_tree(Root) << endl;
            break;
        default:
            break;
        }
    } while (true);
    return 0;
}
