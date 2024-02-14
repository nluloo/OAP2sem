#include <iostream>
#include <stdio.h>

// 16 вариант

int main() {
	setlocale(LC_ALL, "ru");
	FILE* fileA, * fileB, * fileC;
	int numberA, numberB;

	// Открываем два файла(два для чтения, третий для записи)
	if (fopen_s(&fileA, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileA.txt", "r") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileB, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileB.txt", "r") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileC, "D:\\labs\\oap1.2\\lab2Files\\dop3\\fileC.txt", "w") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}

	while (!feof(fileA)) { // Цикл продолжается, пока данные не закончаться
		// Добавляем пробелы и при считывании данных(для того, чтобы последнее число не дублировалось)
		fscanf_s(fileA, "%d ", &numberA); // Считываем первую цифру из fileA и записываем значение в переменную numberA
		fscanf_s(fileB, "%d ", &numberB); // Считываем первую цифру из fileB и записываем значение в переменную numberB
		fprintf(fileC, "%d ", numberA + numberB); // Записываем сумму данных переменных в новый файл
	}

	// Закрываем файлы
	fclose(fileA);
	fclose(fileB);
	fclose(fileC);

	printf("Сумма элементов из fileA и fileB записана в файле C!\n");
	return 0;
}
