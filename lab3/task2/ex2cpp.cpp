#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void writing_to_file(string);

void line_splitting(int, vector<char>&, vector<char>&);

int main() {
    setlocale(LC_ALL, "ru");
    string words;
    int k;

    cout << "Введите строку: ";
    getline(cin, words);

    writing_to_file(words);

    cout << "Введите число k: ";
    cin >> k;
    vector<char> arr1(k), arr2;
    
    line_splitting(k, arr1, arr2);

    cout << "Первая подстрока: ";
    for (char symbol : arr1) {
        cout << symbol;
    }
    cout << endl;

    cout << "Вторая подстрока: ";
    for (char symbol : arr2) {
        cout << symbol;
    }
    cout << endl;

    return 0;
}

void writing_to_file(string words) {
    ofstream fout("D:\\labs\\oap1.2\\lab3Files\\task2\\FILE1.txt");
    fout << words;
    fout.close();
}

void line_splitting(int k, vector<char>& arr1, vector<char>& arr2) {
    ifstream fin("D:\\labs\\oap1.2\\lab3Files\\task2\\FILE1.txt");

    if (!fin.is_open()) {
        cout << "Ошибка((" << endl;
        exit(EXIT_FAILURE);
    }

    char symbol;
    int count = 0;
    while (count < k) {
        fin.get(symbol);
        arr1[count] = symbol;
        count++;
    }

    while (fin.get(symbol)) {
        arr2.push_back(symbol);
    }

    fin.close();
}
