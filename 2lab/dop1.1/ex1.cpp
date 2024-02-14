#include <iostream>
#include <stdio.h>

//4 вариант

int main() {
	FILE* fileA, * fileB;
	int number;

	// Открываем два файла(один для чтения, другой для записи)
	if (fopen_s(&fileA, "D:\\labs\\oap1.2\\lab2Files\\fileA.txt", "r") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&fileB, "D:\\labs\\oap1.2\\lab2Files\\fileB.txt", "w") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; !feof(fileA); i++) { // С помощью функции feof организовываем цикл. Данный цикл продолжается до того момента, пока не встретит значение EOF(конец данных)
		fscanf_s(fileA, "%d", &number); // Считываем каждую цифру в fileA
		if (number > 0) // И если эта цифра положительная, то записать ее в новыый файл
			fprintf(fileB, "%d ", number);
	}

	// Закрываем оба файла
	fclose(fileB);
	fclose(fileA);

	printf("В новом файле остались только положителбные элементы!\n"); // После всех действий выводим сообщение в консоль

	return 0;
}
