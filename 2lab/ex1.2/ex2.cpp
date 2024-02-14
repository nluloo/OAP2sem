#include <iostream>
#include <stdio.h>
#include <algorithm>

//14 вариант

int main() {
    setlocale(LC_ALL, "ru");
    int size = 0;
    FILE* inputFile, * outputFile;
    long fsize;

    if (fopen_s(&inputFile, "D:\\labs\\oap1.2\\lab2Files\\intNumbers.txt", "r") != 0) { // Открываем файл для чтения и смотрим, что он вернет(если 0, то он открылся)
        perror("Не удалось открыть файл для чтения");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0L, SEEK_END); // Считаем размер файла для динамического массива
    fsize = ftell(inputFile);
    fseek(inputFile, 0L, SEEK_SET);

    int* arr = new int[fsize];

    while (fscanf_s(inputFile, "%d", &arr[size]) == 1) { // Чтобы не заходить за пределы памяти считаем, сколько целых элементов будет в нашей последовательности
        size++;
    }
    fclose(inputFile);

    fopen_s(&outputFile, "D:\\labs\\oap1.2\\lab2Files\\Numbers.txt", "w"); // Открываем второй файл для записи
    std::sort(arr, arr + size); // Сортируем массив для дальнейшего сравнения
    for (int i = 0; i < size; ++i) {
        if (arr[i] != arr[i - 1]) {
            fprintf(outputFile, "%d ", arr[i]); // Если символы не совпадают, то записать их в новый файл
        }
    }

    fclose(outputFile);

    printf("Повторяющиеся числа удалены!\n"); // После всех действий выводим сообщение в консоль

    delete[] arr;
    return 0;
}
