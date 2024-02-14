#include <iostream>
#include <stdio.h>

//5 вариант

int main() {
    setlocale(LC_ALL, "ru");
    FILE* A, * B, * C;
    int n, j;

    //Открываем два файла для чтения
    if (fopen_s(&A, "D:\\labs\\oap1.2\\lab2Files\\A.txt", "r") != 0) {
        perror("Не удалось открыть файл для чтения");
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&B, "D:\\labs\\oap1.2\\lab2Files\\B.txt", "r") != 0) {
        perror("Не удалось открыть файл для чтения");
        exit(EXIT_FAILURE);
    }

    fscanf_s(A, "%d", &n); // Считываем первое целое число(количество столбцов квадратной матрицы)

    int** arr1 = new int* [n];
    for (int i = 0; i < n; i++) // Т.к у нас квадратная матрица, используем значение n как для столбцов, так и для строк
        arr1[i] = new int[n];

    fscanf_s(B, "%d", &n); // Считываем первое целое число(количество столбцов квадратной матрицы)

    int** arr2 = new int* [n];
    for (int i = 0; i < n; i++)
        arr2[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf_s(A, "%d", &arr1[i][j]); // Записываем в первый массив(относится к файлу A.txt) каждый элемент матрицы
            fscanf_s(B, "%d", &arr2[i][j]); // Записываем во второй массив(относится к файлу B.txt) каждый элемент матрицы
        }
    }
    //Закрываем файлы
    fclose(A);
    fclose(B);

    if (fopen_s(&C, "D:\\labs\\oap1.2\\lab2Files\\С.txt", "w") != 0) { // Открываем файл для записи
        perror("Не удалось открыть файл для записи");
        exit(EXIT_FAILURE);
    }

    fprintf(C, "%d\n", n); // Записываем число колонок матрицы в первую строку

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(C, "%d ", arr1[i][j] * arr2[i][j]); // Записываем произведение каждого элемента предыдущих матриц
        }
        fprintf(C, "\n");
    }

    for (int i = 0; i < n; i++) {
        delete[] arr1[i];
        delete[] arr2[i];
    }

    delete[] arr1;
    delete[] arr2;

    fclose(C); // Закрываем 3 файл

    printf("Матрица изменена!\n"); // После всех действий выводим сообщение в консоль
    return 0;
}
