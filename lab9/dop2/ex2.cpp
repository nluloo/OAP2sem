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
                {"������",
                "�������",
                "��������"},
                2001,
                9,
                3,
                {5,5,5,5,5},
                &stud2,
                nullptr
            };

            stud2 = {
                {"�������",
                "���������",
                "����������"},
                2002,
                7,
                3,
                {5,4,5,3,4},
                &stud3,
                &stud1
            };

            stud3 = {
                {"�������",
                "������",
                "���������"},
                2000,
                8,
                1,
                {3,4,5,4,5},
                &stud4,
                &stud2
            };

            stud4 = {
                {"�������",
                "�����",
                "�������������"},
                2001,
                9,
                4,
                {4,5,3,4,5},
                &stud5,
                &stud3
            };

            stud5 = {
                {"��������",
                "�����",
                "��������"},
                2002,
                8,
                3,
                {5,4,5,4,5},
                &stud6,
                &stud4
            };

            stud6 = {
                {"�������",
                "�������",
                "����������"},
                2001,
                7,
                4,
                {4,5,4,3,4},
                &stud7,
                &stud5
            };

            stud7 = {
                {"������",
                "���������",
                "��������"},
                2000,
                9,
                2,
                {5,4,5,4,5},
                &stud8,
                &stud6
            };

            stud8 = {
                {"���������",
                "�����",
                "����������"},
                2010,
                7,
                2,
                {4,5,4,3,4},
                &stud9,
                &stud7
            };

            stud9 = {
                {"���������",
                "���������",
                "����������"},
                2001,
                9,
                3,
                {5,4,5,4,5},
                &stud10,
                &stud8
            };

            stud10 = {
                {"��������",
                "�����",
                "�������������"},
                2000,
                8,
                1,
                {4,5,4,3,4},
                &stud11,
                &stud9
            };

            stud11 = {
                {"�������",
                "�������",
                "��������"},
                2002,
                7,
                4,
                {5,4,3,5,4},
                &stud12,
                &stud10
            };

            stud12 = {
                {"��������",
                "�����",
                "����������"},
                2001,
                9,
                2,
                {4,5,4,3,5},
                &stud13,
                &stud11
            };

            stud13 = {
                {"������",
                "������",
                "��������"},
                2000,
                8,
                1,
                {5,4,5,3,4},
                &stud14,
                &stud12
            };

            stud14 = {
                {"������",
                "������",
                "���������"},
                2001,
                7,
                2,
                {4,3,4,5,4},
                &stud15,
                &stud13
            };

            stud15 = {
                {"����������",
                "�����",
                "������������"},
                1950,
                9,
                4,
                {5,4,5,4,5},
                &stud16,
                &stud14
            };

            stud16 = {
                {"��������",
                "����",
                "����������"},
                2001,
                8,
                1,
                {4,5,4,3,4},
                &stud17,
                &stud15
            };

            stud17 = {
                {"��������",
                "�������",
                "��������"},
                2000,
                7,
                2,
                {5,4,5,4,5},
                &stud18,
                &stud16
            };

            stud18 = {
                {"�������",
                "�����",
                "����������"},
                2002,
                9,
                1,
                {4,5,4,3,4},
                &stud19,
                &stud17
            };

            stud19 = {
                {"�������",
                "���������",
                "�������������"},
                2001,
                8,
                4,
                {5,4,5,4,5},
                &stud20,
                &stud18
            };

            stud20 = {
                {"��������",
                "���������",
                "���������"},
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
	cout << "1/11. ���� ���������� � ��������/������� ����" << endl;
	cout << "2. ������� ���������� � ���������" << endl;
	cout << "3. ����������� ���������" << endl;
	cout << "4. ����� ������� ���� ������ ������" << endl;
	cout << "5. ���������� ������ �������� � ������ �������� ��������" << endl;
	cout << '?';
}

void input_info(Student** head, Student** last) {
    Student* newStudent = new Student;
    if (*last == nullptr) {
        cout << "������� ��� ��������:";
        cin.getline(newStudent->name.firstName, 20);
        cout << "������� ������� ��������:";
        cin.getline(newStudent->name.lastName, 20);
        cout << "������� �������� ��������:";
        cin.getline(newStudent->name.patronomyc, 20);
        cout << "������� ��� ��������: ";
        cin >> newStudent->birthdayYear;
        cin.ignore();
        cout << "������� ����� ������: ";
        cin >> newStudent->numberGroup;
        cin.ignore();
        cout << "������� 5 ������ ��������: ";
        for (int i = 0; i < 5; i++) {
            cin >> newStudent->assesment[i];
        }
        newStudent->next = nullptr;
        newStudent->prev = nullptr;
        *last = newStudent;
        *head = newStudent;
    }
    else {
        cout << "������� ��� ��������:";
        cin.getline(newStudent->name.firstName, 20);
        cout << "������� ������� ��������:";
        cin.getline(newStudent->name.lastName, 20);
        cout << "������� �������� ��������:";
        cin.getline(newStudent->name.patronomyc, 20);
        cout << "������� ��� ��������: ";
        cin >> newStudent->birthdayYear;
        cin.ignore();
        cout << "������� ����� ������: ";
        cin >> newStudent->numberGroup;
        cin.ignore();
        cout << "������� 5 ������ ��������: ";
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
    cout << "\t���\t\t\t��� ��������\t\t����\t\t����� ������\t������" << endl;
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



void insertInOrder(Student** head, Student** last) { // ��� ����� � ������ ����� ��� ���������� ���� ������ ����, �� ������ ���� 
    if (*head == nullptr || (*head)->next == nullptr)
        return; // ������ ������ ��� ���� �������

    Student* sorted = nullptr; // ������������� ���������������� ������

    Student* current = *head; // ������ �� ������ head
    while (current != nullptr) {
        Student* next = current->next; // ��������� ��������� ���� ����� ����������

        // ��������� ������� ���� � ��������������� ������
        if (sorted == nullptr || sorted->course >= current->course) {
            // ��������� � ������ ���������������� ������
            current->next = sorted;
            if (sorted != nullptr)
                sorted->prev = current;
            sorted = current;
            sorted->prev = nullptr;
        }
        else {
            // ������ ����� ��� ������� � �������� ��� � ����� ������
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

        // ��������� � ���������� ����
        current = next;
    }

    // ��������� ��������� head � last
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
            cout << "����: " << ccc[i] << "      ������: " << ggg[j] << endl;
            for (int g = 0; g < 5; g++) {
                cout   << "   �������:" << g + 1 << "     ������� ����: " << sum[j][g] / index[j] << endl;
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
    cout << "����� ������ ������� " << oldest_student->name.lastName << ' ' << oldest_student->name.firstName << '\t' << "����: " << oldest_student->course << '\t' << "������: " << oldest_student->numberGroup << '\t' << "���� ��������: " << oldest_student->birthdayYear << endl;
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
    cout << "����� ������� ������� " << oldest_student->name.lastName << ' ' << oldest_student->name.firstName << '\t' << "����: " << oldest_student->course << '\t' << "������: " << oldest_student->numberGroup << '\t' << "���� ��������: " << oldest_student->birthdayYear << endl;
}

void find_top_student(Student* head, Student* last) {
    Student* cur = head;
    Student* last_cur = last;
    Student* top_stud = last;
    for (int i = 1; cur != nullptr && i != 5; i++) { // ���������� ������ 
        for (int g = 7; cur != nullptr && g != 10; g++) { // ����������� �� ����������(���������� �����) � ����� �����
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
            cout << "������ ������� " << i << " ����� " << g << " ������ " << top_stud->name.lastName;
            cout << " ������: ";
            for (int j = 0; j < 5; j++) {
                cout << top_stud->assesment[j] << ' ';
            }
            cout << endl;
            cur = cur->next;
        }

        last_cur = last;

    }
}