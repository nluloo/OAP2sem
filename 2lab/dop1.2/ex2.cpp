#include <iostream>
#include <stdio.h>

//4 �������

int main() {
	setlocale(LC_ALL, "ru");

	FILE* f, * g;
	int number, k;
	printf("������� �����: ");
	scanf_s("%d", &k);

	// ��������� ��� �����, �� ������ ����� ����� ��������, � ������ ����������
	if (fopen_s(&f, "D:\\labs\\oap1.2\\lab2Files\\f.txt", "r") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&g, "D:\\labs\\oap1.2\\lab2Files\\g.txt", "w") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; !feof(f); i++) {
		fscanf_s(f, "%d", &number); // ������� �� ������� ����� ��������� �����
		if (number > k) // ���� ��� ������ ��������� �����, �� �������� �� ������ ����
			fprintf(g, "%d ", number);
	}

	// ��������� �����
	fclose(f);
	fclose(g);

	printf("����� ������ ���������� ���������!\n"); // ����� ���� �������� ������� ��������� � �������

	return 0;
}
