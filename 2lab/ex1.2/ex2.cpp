#include <iostream>
#include <stdio.h>
#include <algorithm>

//14 �������

int main() {
    setlocale(LC_ALL, "ru");
    int size = 0;
    FILE* inputFile, * outputFile;
    long fsize;

    if (fopen_s(&inputFile, "D:\\labs\\oap1.2\\lab2Files\\intNumbers.txt", "r") != 0) { // ��������� ���� ��� ������ � �������, ��� �� ������(���� 0, �� �� ��������)
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }

    fseek(inputFile, 0L, SEEK_END); // ������� ������ ����� ��� ������������� �������
    fsize = ftell(inputFile);
    fseek(inputFile, 0L, SEEK_SET);

    int* arr = new int[fsize];

    while (fscanf_s(inputFile, "%d", &arr[size]) == 1) { // ����� �� �������� �� ������� ������ �������, ������� ����� ��������� ����� � ����� ������������������
        size++;
    }
    fclose(inputFile);

    fopen_s(&outputFile, "D:\\labs\\oap1.2\\lab2Files\\Numbers.txt", "w"); // ��������� ������ ���� ��� ������
    std::sort(arr, arr + size); // ��������� ������ ��� ����������� ���������
    for (int i = 0; i < size; ++i) {
        if (arr[i] != arr[i - 1]) {
            fprintf(outputFile, "%d ", arr[i]); // ���� ������� �� ���������, �� �������� �� � ����� ����
        }
    }

    fclose(outputFile);

    printf("������������� ����� �������!\n"); // ����� ���� �������� ������� ��������� � �������

    delete[] arr;
    return 0;
}
