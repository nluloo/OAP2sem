#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#define SR(a,b,c,d,f) (a+b+c+d+f) / 5
using namespace std;

struct NAME
{
	char lastName[20];
	char firstName[20];
	char patronomyc[20];
};

struct Student
{
	NAME name;
	int birthdayYear;
	int numberGroup;
    int course;
	int assesment[5];
	Student* next;
	Student* prev;
};
void input_info(Student** head, Student** last);
void output_info(Student** head, Student** last);
void insertInOrder(Student** head, Student**);
int compareNames(const char* str1, const char* str2);
void srb(Student* head, Student* last);
void swap(Student** head, Student** last, Student* current, Student* cur);
void find_oldest(Student* head, Student* last);
void find_youngest(Student* head, Student* last);
void find_top_student(Student* head, Student* last);
void menu();

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Student* head = nullptr;
	Student* last = nullptr;
    Student stud1, stud2, stud3, stud4, stud5, stud6, stud7, stud8, stud9, stud10, stud11, stud12, stud13, stud14, stud15, stud16, stud17, stud18, stud19, stud20;
    
    int choice;
    do
    {
        menu();
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            input_info(&head, &last); // or
            break;
        case 11: // or
            stud1 = {
                {"Иванов",
                "Алексей",
                "Игоревич"},
                2001,
                9,
                3,
                {5,5,5,5,5},
                &stud2,
                nullptr
            };

            stud2 = {
                {"Петрова",
                "Екатерина",
                "Дмитриевна"},
                2002,
                7,
                3,
                {5,4,5,3,4},
                &stud3,
                &stud1
            };

            stud3 = {
                {"Сидоров",
                "Андрей",
                "Сергеевич"},
                2000,
                8,
                1,
                {3,4,5,4,5},
                &stud4,
                &stud2
            };

            stud4 = {
                {"Козлова",
                "Мария",
                "Александровна"},
                2001,
                9,
                4,
                {4,5,3,4,5},
                &stud5,
                &stud3
            };

            stud5 = {
                {"Васильев",
                "Игорь",
                "Петрович"},
                2002,
                8,
                3,
                {5,4,5,4,5},
                &stud6,
                &stud4
            };

            stud6 = {
                {"Никитин",
                "Евгений",
                "Алексеевич"},
                2001,
                7,
                4,
                {4,5,4,3,4},
                &stud7,
                &stud5
            };

            stud7 = {
                {"Белова",
                "Анастасия",
                "Ивановна"},
                2000,
                9,
                2,
                {5,4,5,4,5},
                &stud8,
                &stud6
            };

            stud8 = {
                {"Григорьев",
                "Павел",
                "Николаевич"},
                2010,
                7,
                2,
                {4,5,4,3,4},
                &stud9,
                &stud7
            };

            stud9 = {
                {"Кузнецова",
                "Валентина",
                "Алексеевна"},
                2001,
                9,
                3,
                {5,4,5,4,5},
                &stud10,
                &stud8
            };

            stud10 = {
                {"Алексеев",
                "Артем",
                "Александрович"},
                2000,
                8,
                1,
                {4,5,4,3,4},
                &stud11,
                &stud9
            };

            stud11 = {
                {"Антонов",
                "Дмитрий",
                "Иванович"},
                2002,
                7,
                4,
                {5,4,3,5,4},
                &stud12,
                &stud10
            };

            stud12 = {
                {"Смирнова",
                "Елена",
                "Викторовна"},
                2001,
                9,
                2,
                {4,5,4,3,5},
                &stud13,
                &stud11
            };

            stud13 = {
                {"Павлов",
                "Сергей",
                "Петрович"},
                2000,
                8,
                1,
                {5,4,5,3,4},
                &stud14,
                &stud12
            };

            stud14 = {
                {"Громов",
                "Максим",
                "Сергеевич"},
                2001,
                7,
                2,
                {4,3,4,5,4},
                &stud15,
                &stud13
            };

            stud15 = {
                {"Коновалова",
                "Ольга",
                "Владимировна"},
                1950,
                9,
                4,
                {5,4,5,4,5},
                &stud16,
                &stud14
            };

            stud16 = {
                {"Михайлов",
                "Илья",
                "Алексеевич"},
                2001,
                8,
                1,
                {4,5,4,3,4},
                &stud17,
                &stud15
            };

            stud17 = {
                {"Назарова",
                "Евгения",
                "Ивановна"},
                2000,
                7,
                2,
                {5,4,5,4,5},
                &stud18,
                &stud16
            };

            stud18 = {
                {"Борисов",
                "Павел",
                "Николаевич"},
                2002,
                9,
                1,
                {4,5,4,3,4},
                &stud19,
                &stud17
            };

            stud19 = {
                {"Воронов",
                "Александр",
                "Александрович"},
                2001,
                8,
                4,
                {5,4,5,4,5},
                &stud20,
                &stud18
            };

            stud20 = {
                {"Федорова",
                "Анастасия",
                "Сергеевна"},
                2000,
                7,
                1,
                {4,5,4,3,4},
                nullptr,
                &stud19
            };
            head = &stud1;
            last = &stud20;
            break;
            case 2:
                output_info(&head, &last);
                break;
            case 3:
                insertInOrder(&head, &last);
                break;
            case 4:
                srb(head, last);
                break;
            case 5:
                find_oldest(head, last);
                find_youngest(head, last);
                break;
            case 6:
                find_top_student(head, last);
                break;
        default:
            break;
        }
        system("pause");
        system("cls");
    } while (choice != 7);
	return 0;
}

void menu() {
	cout << "1/11. Ввод информации о студенте/Готовый лист" << endl;
	cout << "2. Вывести информацию о студентах" << endl;
	cout << "3. Упорядочить студентов" << endl;
	cout << "4. Найти средний балл каждой группы" << endl;
	cout << "5. Нахождение самого старшего и самого младшего студента" << endl;
	cout << '?';
}

void input_info(Student** head, Student** last) {
    Student* newStudent = new Student;
    if (*last == nullptr) {
        cout << "Введите имя студента:";
        cin.getline(newStudent->name.firstName, 20);
        cout << "Введите фамилию студента:";
        cin.getline(newStudent->name.lastName, 20);
        cout << "Введите отчество студента:";
        cin.getline(newStudent->name.patronomyc, 20);
        cout << "Введите год рождения: ";
        cin >> newStudent->birthdayYear;
        cin.ignore();
        cout << "Введите номер группы: ";
        cin >> newStudent->numberGroup;
        cin.ignore();
        cout << "Введите 5 оценок студента: ";
        for (int i = 0; i < 5; i++) {
            cin >> newStudent->assesment[i];
        }
        newStudent->next = nullptr;
        newStudent->prev = nullptr;
        *last = newStudent;
        *head = newStudent;
    }
    else {
        cout << "Введите имя студента:";
        cin.getline(newStudent->name.firstName, 20);
        cout << "Введите фамилию студента:";
        cin.getline(newStudent->name.lastName, 20);
        cout << "Введите отчество студента:";
        cin.getline(newStudent->name.patronomyc, 20);
        cout << "Введите год рождения: ";
        cin >> newStudent->birthdayYear;
        cin.ignore();
        cout << "Введите номер группы: ";
        cin >> newStudent->numberGroup;
        cin.ignore();
        cout << "Введите 5 оценок студента: ";
        for (int i = 0; i < 5; i++) {
            cin >> newStudent->assesment[i];
        }
        newStudent->next = nullptr;
        newStudent->prev = *last;
        (*last)->next = newStudent;
        *last = newStudent;
    }
}

void output_info(Student** head, Student** last) {
    Student* phead = *head;
    cout << "\tФИО\t\t\tГод рождения\t\tКурс\t\tНомер группы\tОценки" << endl;
    int i = 0;
    while (phead != NULL) {
        cout << i + 1 << ". ";
        cout << phead->name.lastName << ' ' << phead->name.firstName << ' ' << phead->name.patronomyc << "\t\t" << phead->birthdayYear << "\t\t"<< phead->course << "\t\t" << phead->numberGroup << "\t\t";
        for (int i = 0; i < 5; i++) {
            cout << phead->assesment[i] << ' ';
        }
        cout << endl;
        phead = phead->next;
        i++;
    }
}

int compareNames(const char* str1, const char* str2) {
    return strcmp(str1, str2);
}

void swap(Student** head, Student** last, Student* current, Student* cur) {
    if (current == nullptr || cur == nullptr || current == cur)
        return;

    if (current->next == cur) {
        if (current->prev)
            current->prev->next = cur;
        if (cur->next)
            cur->next->prev = current;

        current->next = cur->next;
        cur->prev = current->prev;
        cur->next = current;
        current->prev = cur;
    }
    else {
        if (current->prev)
            current->prev->next = cur;
        if (cur->next)
            cur->next->prev = current;
        if (cur->prev)
            cur->prev->next = current;
        if (current->next)
            current->next->prev = cur;

        Student* tempNext = current->next;
        current->next = cur->next;
        cur->next = tempNext;

        Student* tempPrev = current->prev;
        current->prev = cur->prev;
        cur->prev = tempPrev;
    }

    if (*head == current)
        *head = cur;
    if (*last == cur)
        *last = current;
}



void insertInOrder(Student** head, Student** last) { // ЭТУ ЧАСТЬ Я СДЕЛАЛ ЧЕРЕЗ ГПТ РАЗБИРАЙТЕ САМИ ДАННУЮ ТЕМУ, НЕ БУДЬТЕ МНОЙ 
    if (*head == nullptr || (*head)->next == nullptr)
        return; // пустой список или один элемент

    Student* sorted = nullptr; // инициализация отсортированного списка

    Student* current = *head; // начнем со списка head
    while (current != nullptr) {
        Student* next = current->next; // сохраняем следующий узел перед изменением

        // Вставляем текущий узел в отсортированный список
        if (sorted == nullptr || sorted->course >= current->course) {
            // Вставляем в начало отсортированного списка
            current->next = sorted;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
            sorted->prev = nullptr;
        }
        else {
            // Найдем место для вставки в середину или в конец списка
            Student* temp = sorted;
            while (temp->next != nullptr && temp->next->course < current->course) {
                temp = temp->next;
            }
            current->next = temp->next;
            if (temp->next != nullptr)
                temp->next->prev = current;
            temp->next = current;
            current->prev = temp;
        }

        // Переходим к следующему узлу
        current = next;
    }

    // Обновляем указатели head и last
    *head = sorted;
    *last = sorted;
    while ((*last)->next != nullptr) {
        *last = (*last)->next;
    }
}



void srb(Student* head, Student* last) {
    Student* temp = head;
    float sum[3][5] = { { 0,0,0,0,0 }, { 0,0,0,0,0 }, { 0,0,0,0,0 } };
    int index[3] = { 0,0,0 };
    int ccc[4] = { 1,2,3,4 };
    int ggg[3] = { 7,8,9 };

    while (temp != nullptr) {
        if (temp->course == 1) {
            for (int i = 0; i < 5; i++) {
                if (temp->numberGroup == 7) {
                    sum[0][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 8) {
                    sum[1][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 9) {
                    sum[2][i] += temp->assesment[i];
                }
            }
            if(temp->numberGroup == 7) index[0]++;
            if (temp->numberGroup == 8) index[1]++;
            if (temp->numberGroup == 9) index[2]++;

        }
        if (temp->course == 2) {
            for (int i = 0; i < 5; i++) {
                if (temp->numberGroup == 7) {
                    sum[0][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 8) {
                    sum[1][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 9) {
                    sum[2][i] += temp->assesment[i];
                }
            }
            if (temp->numberGroup == 7) index[0]++;
            if (temp->numberGroup == 8) index[1]++;
            if (temp->numberGroup == 9) index[2]++;
        }
        if (temp->course == 3) {
            for (int i = 0; i < 5; i++) {
                if (temp->numberGroup == 7) {
                    sum[0][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 8) {
                    sum[1][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 9) {
                    sum[2][i] += temp->assesment[i];
                }
            }
            if (temp->numberGroup == 7) index[0]++;
            if (temp->numberGroup == 8) index[1]++;
            if (temp->numberGroup == 9) index[2]++;
        }
        if (temp->course == 4) {
            for (int i = 0; i < 5; i++) {
                if (temp->numberGroup == 7) {
                    sum[0][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 8) {
                    sum[1][i] += temp->assesment[i];
                }
                if (temp->numberGroup == 9) {
                    sum[2][i] += temp->assesment[i];
                }
            }
            if (temp->numberGroup == 7) index[0]++;
            if (temp->numberGroup == 8) index[1]++;
            if (temp->numberGroup == 9) index[2]++;
        }
        temp = temp->next;

    }
    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 3; j++) {
            cout << "Курс: " << ccc[i] << "      Группа: " << ggg[j] << endl;
            for (int g = 0; g < 5; g++) {
                cout   << "   Предмет:" << g + 1 << "     Средний балл: " << sum[j][g] / index[j] << endl;
            }
            cout<< setfill('-') << setw(100) << '\n';
        }
    }
}

void find_oldest(Student* head, Student* last) {
    Student* cur = head;
    Student* oldest_student = cur;
    cur = cur->next;
    while (cur != nullptr) {
        if (cur->birthdayYear < oldest_student->birthdayYear) {
            oldest_student = cur;
        }
        cur = cur->next;
    }
    cout << "Самый старый студент " << oldest_student->name.lastName << ' ' << oldest_student->name.firstName << '\t' << "Курс: " << oldest_student->course << '\t' << "Группа: " << oldest_student->numberGroup << '\t' << "Дата рождения: " << oldest_student->birthdayYear << endl;
}

void find_youngest(Student* head, Student* last) {
    Student* cur = head;
    Student* oldest_student = cur;
    cur = cur->next;
    while (cur != nullptr) {
        if (cur->birthdayYear > oldest_student->birthdayYear) {
            oldest_student = cur;
        }
        cur = cur->next;
    }
    cout << "Самый молодой студент " << oldest_student->name.lastName << ' ' << oldest_student->name.firstName << '\t' << "Курс: " << oldest_student->course << '\t' << "Группа: " << oldest_student->numberGroup << '\t' << "Дата рождения: " << oldest_student->birthdayYear << endl;
}

void find_top_student(Student* head, Student* last) {
    Student* cur = head;
    Student* last_cur = last;
    Student* top_stud = last;
    for (int i = 1; cur != nullptr && i != 5; i++) { // Количество курсов 
        for (int g = 7; cur != nullptr && g != 10; g++) { // Ограничение по выполнению(количество групп) в одном курсе
            top_stud = cur;
            while (last_cur != nullptr) {

                if (i == cur->course && g == cur->numberGroup)
                {

                    if (SR(last_cur->assesment[0], last_cur->assesment[1], last_cur->assesment[2], last_cur->assesment[3], last_cur->assesment[4]) > SR(top_stud->assesment[0], top_stud->assesment[1], top_stud->assesment[2], top_stud->assesment[3], top_stud->assesment[4])) {
                        top_stud = last_cur;
                    }
                }
                last_cur = last_cur->prev;
            }
            cout << "Лучший студент " << i << " курса " << g << " группы " << top_stud->name.lastName;
            cout << " Оценки: ";
            for (int j = 0; j < 5; j++) {
                cout << top_stud->assesment[j] << ' ';
            }
            cout << endl;
            cur = cur->next;
        }

        last_cur = last;

    }
}