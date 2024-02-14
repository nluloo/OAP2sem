#include <iostream>
#include <stdio.h>

//4 �������

int main() {
	FILE* fileA, * fileB;
	int number;

	// ��������� ��� �����(���� ��� ������, ������ ��� ������)
	if (fopen_s(&fileA, "D:\\labs\\oap1.2\\lab2Files\\fileA.txt", "r") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileB, "D:\\labs\\oap1.2\\lab2Files\\fileB.txt", "w") != 0) {
		perror("�� ������� ������� ���� ��� ������");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; !feof(fileA); i++) { // � ������� ������� feof �������������� ����. ������ ���� ������������ �� ���� �������, ���� �� �������� �������� EOF(����� ������)
		fscanf_s(fileA, "%d", &number); // ��������� ������ ����� � fileA
		if (number > 0) // � ���� ��� ����� �������������, �� �������� �� � ������ ����
			fprintf(fileB, "%d ", number);
	}

	// ��������� ��� �����
	fclose(fileB);
	fclose(fileA);

	printf("� ����� ����� �������� ������ ������������� ��������!\n"); // ����� ���� �������� ������� ��������� � �������

	return 0;
}
