#include <iostream>
#define MAX 100
int* p;              // ��������� �� ������� ��������� ������ 
int* tos, * bos;      // ��������� �� ������� � ��� ����� 
void push(int i);    //��������
int pop(void);       //�������� 
void main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int a, b;  char s[80];
	p = new int[MAX * sizeof(int)];
	if (!p)
	{
		printf("������ ��� ��������� ������\n");
		exit(1);
	}
	tos = p; bos = p + MAX - 1;
	printf("����������� \n ��� ������ ������ 'q'\n");
	do
	{
		printf(": ");  gets_s(s); //���� ������� �����, ������� � ����� ��������

		switch (*s)
		{
		case '+': 	a = pop(); b = pop();   //��������
			printf("%d\n", a + b);
			push(a + b); break;
		case '-':  a = pop(); b = pop();   //���������
			printf("%d\n", b - a);
			push(b - a);  break;
		case '*': 	a = pop(); b = pop();   //���������
			printf("%d\n", b * a);
			push(b * a);  break;
		case '/': 	a = pop(); b = pop();   //�������
			if (a == 0) { printf("������� �� 0\n"); break; }
			printf("%d\n", b / a);
			push(b / a);  break;
		case '.': 	a = pop(); push(a); //����� ������� �����
			printf("������� �������� �� ������� �����: %d\n", a);
			break;
		default:  	push(atoi(s)); //����������� �� ������� � �����
		}
	} while (*s != 'q');
}
void push(int i)     // ��������� �������� � ����
{
	if (p > bos) { printf("���� �����\n"); return; }
	*p = i;  p++;
}
int pop(void)        // ��������� �������� �������� �� �����
{
	p--;
	if (p < tos) { printf("���� ����\n"); return 0; }
	return *p;
}
