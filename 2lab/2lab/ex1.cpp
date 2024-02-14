#include <stdio.h>
#include <iostream>

//14 вариант

int main() {
    setlocale(LC_ALL, "ru");
    FILE* inputFile, * outputFile;
    int n, i, j, k;
    printf("Введите k-столбец: ");
    scanf_s("%d", &k);

    if (fopen_s(&inputFile, "D:\\labs\\oap1.2\\lab2Files\\ex1.txt", "r") != 0) { // Открываем файл, если файл не открылся(вернул не 0), то вывести на экран ошибку
        perror("Не удалось открыть файл для чтения");
        exit(EXIT_FAILURE);
    }

    fscanf_s(inputFile, "%d", &n); // Т.к первый элемент в файле у нас количество столбцов квадратной матрицы, то считываем его и применяем в своих циклах

    float** arr = new float* [n]; // Создаем динамический массив для записи значений из файла
    int number = n;
    for (int i = 0; i < number; i++)
        arr[i] = new float[number];


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf_s(inputFile, "%f", &arr[i][j]); // С помощью цикла и функции записываем в массив из файла значения матрицы
        }
    }

    fclose(inputFile); // Закрываем файл, их которого брали значения

    if (fopen_s(&outputFile, "D:\\labs\\oap1.2\\lab2Files\\ex2.txt", "w") != 0) { // Открываем файл в который будем записывать наш столбец
        perror("Не удалось открыть файл для записи");
        exit(EXIT_FAILURE);
    }

    fprintf(outputFile, "%d\n", 1); // Записываем в первую строчку 1, т.к по структуре у нас останется 1 столбик
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%.2f\n", arr[i][k - 1]); // С помощью цикла записываем в новый файл значения матрицы
    }

    for (i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    fclose(outputFile); // Закрываем файл, в который записали наши значения

    printf("Столбец успешно извлечен!"); // После всех действий выводим сообщение в консоль

    return 0;
}
