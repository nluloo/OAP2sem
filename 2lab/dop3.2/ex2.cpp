#include <iostream>
#include <stdio.h>

// 16 вариант

int main() {
	setlocale(LC_ALL, "ru");
	FILE* file1, * file2;
	int number, scan = 0, i = 0, g = 0;
	long fsize = 0L; // Переменная адреса, которую мы будем изменять для каждого блока чисел(10 положительных 10 отрицательных)

	// Открываем два файла(один для чтения, другой для записи)
	if (fopen_s(&file1, "D:\\labs\\oap1.2\\lab2Files\\dop3.2\\file1.txt", "r") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&file2, "D:\\labs\\oap1.2\\lab2Files\\dop3.2\\file2.txt", "w") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}

	fseek(file1, 0L, SEEK_END);
	long fsizeFile = ftell(file1); // Считываем длину файла в байтах для реализации цикла
	fseek(file1, 0L, SEEK_SET);

	for (int i = 0; fsize < fsizeFile; i++) {

		while (g < 20) { // Т.к в первых 20 элементах у нас 10 положительных и 10 отрицательных, проходим по 20 числам и выбираем только положительные
			fscanf_s(file1, "%d ", &number);
			if (number > 0) {
				fprintf(file2, "%d ", number);
			}
			g++;
		}
		g = 0; // Обнуляем иттератор

		fseek(file1, fsize, SEEK_SET); // Возвращаем позицию в файле на ту, с которой проходила проверка положительных элементов

		while (g < 20) { // Теперь проверяем 20 чисел и выбираем из них отрицательные

			fscanf_s(file1, "%d ", &number);
			if (number < 0) {
				fprintf(file2, "%d ", number);
			}
			g++;
		}
		g = 0;

		fsize += ftell(file1); // Вычисляем место, где закончил проверку прошлый цикл
		fseek(file1, fsize, SEEK_SET); // Ставим туда указатель 
	}

	fclose(file1);
	fclose(file2);

	printf("Числа успежно переставлены!\n");
	return 0;
}
