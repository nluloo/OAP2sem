#include <iostream>
#include <stdio.h>

// 16 �������

int main() {
	setlocale(LC_ALL, "ru");
	FILE* file1, * file2;
	int number, scan = 0, i = 0, g = 0;
	long fsize = 0L; // ���������� ������, ������� �� ����� �������� ��� ������� ����� �����(10 ������������� 10 �������������)

	// ��������� ��� �����(���� ��� ������, ������ ��� ������)
	if (fopen_s(&file1, "D:\\labs\\oap1.2\\lab2Files\\dop3.2\\file1.txt", "r") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&file2, "D:\\labs\\oap1.2\\lab2Files\\dop3.2\\file2.txt", "w") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}

	fseek(file1, 0L, SEEK_END);
	long fsizeFile = ftell(file1); // ��������� ����� ����� � ������ ��� ���������� �����
	fseek(file1, 0L, SEEK_SET);

	for (int i = 0; fsize < fsizeFile; i++) {

		while (g < 20) { // �.� � ������ 20 ��������� � ��� 10 ������������� � 10 �������������, �������� �� 20 ������ � �������� ������ �������������
			fscanf_s(file1, "%d ", &number);
			if (number > 0) {
				fprintf(file2, "%d ", number);
			}
			g++;
		}
		g = 0; // �������� ���������

		fseek(file1, fsize, SEEK_SET); // ���������� ������� � ����� �� ��, � ������� ��������� �������� ������������� ���������

		while (g < 20) { // ������ ��������� 20 ����� � �������� �� ��� �������������

			fscanf_s(file1, "%d ", &number);
			if (number < 0) {
				fprintf(file2, "%d ", number);
			}
			g++;
		}
		g = 0;

		fsize += ftell(file1); // ��������� �����, ��� �������� �������� ������� ����
		fseek(file1, fsize, SEEK_SET); // ������ ���� ��������� 
	}

	fclose(file1);
	fclose(file2);

	printf("����� ������� ������������!\n");
	return 0;
}
