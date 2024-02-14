#include <stdio.h>
#include <iostream>

//14 �������

int main() {
    setlocale(LC_ALL, "ru");
    FILE* inputFile, * outputFile;
    int n, i, j, k;
    printf("������� k-�������: ");
    scanf_s("%d", &k);

    if (fopen_s(&inputFile, "D:\\labs\\oap1.2\\lab2Files\\ex1.txt", "r") != 0) { // ��������� ����, ���� ���� �� ��������(������ �� 0), �� ������� �� ����� ������
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }

    fscanf_s(inputFile, "%d", &n); // �.� ������ ������� � ����� � ��� ���������� �������� ���������� �������, �� ��������� ��� � ��������� � ����� ������

    float** arr = new float* [n]; // ������� ������������ ������ ��� ������ �������� �� �����
    int number = n;
    for (int i = 0; i < number; i++)
        arr[i] = new float[number];


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            fscanf_s(inputFile, "%f", &arr[i][j]); // � ������� ����� � ������� ���������� � ������ �� ����� �������� �������
        }
    }

    fclose(inputFile); // ��������� ����, �� �������� ����� ��������

    if (fopen_s(&outputFile, "D:\\labs\\oap1.2\\lab2Files\\ex2.txt", "w") != 0) { // ��������� ���� � ������� ����� ���������� ��� �������
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }

    fprintf(outputFile, "%d\n", 1); // ���������� � ������ ������� 1, �.� �� ��������� � ��� ��������� 1 �������
    for (i = 0; i < n; i++) {
        fprintf(outputFile, "%.2f\n", arr[i][k - 1]); // � ������� ����� ���������� � ����� ���� �������� �������
    }

    for (i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    fclose(outputFile); // ��������� ����, � ������� �������� ���� ��������

    printf("������� ������� ��������!"); // ����� ���� �������� ������� ��������� � �������

    return 0;
}
