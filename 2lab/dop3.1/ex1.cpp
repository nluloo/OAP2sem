#include <iostream>
#include <stdio.h>

// 16 �������

int main() {
	setlocale(LC_ALL, "ru");
	FILE* fileA, * fileB, * fileC;
	int numberA, numberB;

	// ��������� ��� �����(��� ��� ������, ������ ��� ������)
	if (fopen_s(&fileA, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileA.txt", "r") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileB, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileB.txt", "r") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileC, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileC.txt", "w") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}

	while (!feof(fileA)) { // ���� ������������, ���� ������ �� �����������
		// ��������� ������� � ��� ���������� ������(��� ����, ����� ��������� ����� �� �������������)
		fscanf_s(fileA, "%d ", &numberA); // ��������� ������ ����� �� fileA � ���������� �������� � ���������� numberA
		fscanf_s(fileB, "%d ", &numberB); // ��������� ������ ����� �� fileB � ���������� �������� � ���������� numberB
		fprintf(fileC, "%d ", numberA + numberB); // ���������� ����� ������ ���������� � ����� ����
	}

	// ��������� �����
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);

	printf("����� ��������� �� fileA � fileB �������� � ����� C!\n");
	return 0;
}
