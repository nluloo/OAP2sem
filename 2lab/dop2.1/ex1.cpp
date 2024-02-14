#include <iostream>
#include <stdio.h>

//5 �������

int main() {
    setlocale(LC_ALL, "ru");
    FILE* A, * B, * C;
    int n, j;

    //��������� ��� ����� ��� ������
    if (fopen_s(&A, "D:\\labs\\oap1.2\\lab2Files\\A.txt", "r") != 0) {
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }
    if (fopen_s(&B, "D:\\labs\\oap1.2\\lab2Files\\B.txt", "r") != 0) {
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }

    fscanf_s(A, "%d", &n); // ��������� ������ ����� �����(���������� �������� ���������� �������)

    int** arr1 = new int* [n];
    for (int i = 0; i < n; i++) // �.� � ��� ���������� �������, ���������� �������� n ��� ��� ��������, ��� � ��� �����
        arr1[i] = new int[n];

    fscanf_s(B, "%d", &n); // ��������� ������ ����� �����(���������� �������� ���������� �������)

    int** arr2 = new int* [n];
    for (int i = 0; i < n; i++)
        arr2[i] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf_s(A, "%d", &arr1[i][j]); // ���������� � ������ ������(��������� � ����� A.txt) ������ ������� �������
            fscanf_s(B, "%d", &arr2[i][j]); // ���������� �� ������ ������(��������� � ����� B.txt) ������ ������� �������
        }
    }
    //��������� �����
    fclose(A);
    fclose(B);

    if (fopen_s(&C, "D:\\labs\\oap1.2\\lab2Files\\�.txt", "w") != 0) { // ��������� ���� ��� ������
        perror("�� ������� ������� ���� ��� ������");
        exit(EXIT_FAILURE);
    }

    fprintf(C, "%d\n", n); // ���������� ����� ������� ������� � ������ ������

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(C, "%d ", arr1[i][j] * arr2[i][j]); // ���������� ������������ ������� �������� ���������� ������
        }
        fprintf(C, "\n");
    }

    for (int i = 0; i < n; i++) {
        delete[] arr1[i];
        delete[] arr2[i];
    }

    delete[] arr1;
    delete[] arr2;

    fclose(C); // ��������� 3 ����

    printf("������� ��������!\n"); // ����� ���� �������� ������� ��������� � �������
    return 0;
}
