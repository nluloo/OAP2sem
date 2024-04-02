#include "Heap.h"
#include <iostream>
using namespace std;
heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1 
}
//-------------------------------
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	void** temp;
	int** t;
	AAA* b;

	for (;;)
	{
		cout << "1 // 11 - ����� 1 ���� �� ����� // 2 ����" << endl;
		cout << "2 // 22 - �������� ������� � 1 ���� // �� 2" << endl;
		cout << "3 - ������� ������������ ������� 1 ����" << endl;
		cout << "4 - ������� ����������� ������� 1 ����" << endl;
		cout << "5 - ������� i-������� 1 ����" << endl;
		cout << "6 - ���������� 2 ����" << endl;
		cout << "0 - �����" << endl;
		cout << "�������� �����" << endl;  cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 1:  h1.scan(0);
			break;
		case 11:
			h2.scan(0);
			break;
		case 2: {	AAA* a = new AAA;
			cout << "������� ����" << endl; 	cin >> k;
			a->x = k;
			h1.insert(a);
		}
			  break;
		case 3:
			h1.extractMax(); // ����� ������� ������������ ��������
			break;
		case 4:
			h1.extractMin(h1.find_min());
			break;
		case 5:
			cout << "������� ������ ��������, ������� �� ������ �������: ";
			cin >> k;
			if (k > h1.size) {
				cout << "��������� �������� ���������� �������." << endl;
				exit(EXIT_FAILURE);
			}
			h1.extractI(k);
			break;
		case 22:
			b = new AAA;
			cout << "������� ����" << endl; 	cin >> k;
			b->x = k;
			h2.insert(b);
			break;
		case 6:
			temp = h2.extract_heap();
			t = reinterpret_cast<int**>(temp);
			for (int i = 0; i < h2.size; i++) {
				h1.insert(t[i]);
			}
			break;
		default:  cout << endl << "������� �������� �������!" << endl;
		}
	} return 0;
}

