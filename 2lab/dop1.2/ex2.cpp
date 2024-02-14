#include <iostream>
#include <stdio.h>

//4 вариант

int main() {
	setlocale(LC_ALL, "ru");

	FILE* f, * g;
	int number, k;
	printf("Введите число: ");
	scanf_s("%d", &k);

	// Открываем два файла, из одного будем брать значения, в другой записывать
	if (fopen_s(&f, "D:\\labs\\oap1.2\\lab2Files\\f.txt", "r") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}
	if (fopen_s(&g, "D:\\labs\\oap1.2\\lab2Files\\g.txt", "w") != 0) {
		perror("Не удалось открыть файл для чтения");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; !feof(f); i++) {
		fscanf_s(f, "%d", &number); // Сначала из первого файла считываем число
		if (number > k) // Если оно больше введеного числа, то записать во второй файл
			fprintf(g, "%d ", number);
	}

	// Закрываем файлы
	fclose(f);
	fclose(g);

	printf("Числа меньше введенного извлечены!\n"); // После всех действий выводим сообщение в консоль

	return 0;
}
