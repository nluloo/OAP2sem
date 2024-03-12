#include <iostream>
#include <string>
#define AMOUNTSTUDENT 30
#define MAXEXAMS 5

void input_info();
void results_exams();
void all_results();

using namespace std;

struct listExams {

	string nameStudent;
	int amountExams;
	int assessment[MAXEXAMS];

};

int current_size;

listExams list_exams[AMOUNTSTUDENT];	

int main(){
	setlocale(LC_ALL, "ru");
	int choise;

	do {
		cin >> choise;
		switch (choise)
		{
		case 1:
			input_info();
			break;
		case 2:
			results_exams();
			break;
		case 3:
			all_results();
			break;
		default:
			break;
		}


	} while (choise != 4);


	return 0;
}

void input_info() {
	int amountStudents;
	cout << "Введите количество студентов, которых вы хотите добавить: ";
	cin >> amountStudents;
	int amountSize = current_size;
	if (amountSize + amountStudents > AMOUNTSTUDENT) {
		cout << "lox";
		return;
	}
	for (current_size; current_size < amountSize + amountStudents; current_size++) {
		cout << "Введите ФИО " << current_size + 1 << " студента: ";
		cin.ignore();
		getline(cin, list_exams[current_size].nameStudent);
		cout << "Введите количество экзаменов(не больше 5): ";
		cin >> list_exams[current_size].amountExams;
		for (int j = 0; j < list_exams[current_size].amountExams; j++) {
			cout << "Оценка за " << j + 1 << " экзамен: ";
			cin >> list_exams[current_size].assessment[j];
		}
	}
}

void results_exams() {
	int numberStudent, correctNumber;
	cout << "Введите номер студента, у которого вы хотите проверить успеваймость: ";
	cin >> numberStudent;
	correctNumber = numberStudent - 1;
	cout << "ФИО: " << list_exams[correctNumber].nameStudent << endl;
	for (int i = 0; i < list_exams[correctNumber].amountExams; i++) {
		if (list_exams[correctNumber].assessment[i] >= 4) {
			cout << i + 1 << " экзамен сдан!" << endl;
		}
		else {
			cout << i + 1 << " экзамен не сдан((" << endl;
		}
	}
}

void all_results() {
	int buff = 0;
	float amStudent = 0;
	for (int i = 0; i < current_size; i++) {
		buff = 0;
		for (int j = 0; j < list_exams[i].amountExams; j++) {
			if (list_exams[i].assessment[j] >= 4) {
				buff++;
			}
		}
		if (buff == list_exams[i].amountExams) {
			amStudent++;
		}
	}
	cout << amStudent / current_size * 100 << "%" << endl;
}