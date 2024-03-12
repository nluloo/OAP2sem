#include<iostream> 
using namespace std;
struct Number
{
    int info;
    Number* next;
};
void create(Number** begin, Number** end, int p); //������������ ��������� �������
void view(Number* begin);                        //����� ��������� ������� 
Number* minElem(Number* begin);               //����������� ������������ �������� 
void DeltoMin(Number** begin, Number** p);    //�������� �� ������������ �������� 
int main()
{
    Number* begin = NULL, * end, * t;
    t = new Number;
    int p, size;
    cout << "\nEnter size queue=";  cin >> size;
    cout << "Enter number= ";       cin >> p;
    t->info = p;        //������ �������
    t->next = NULL;
    begin = end = t;
    for (int i = 1; i < size; i++) //�������� �������
    {
        cout << "Enter number= ";    cin >> p;
        create(&begin, &end, p);
    }
    cout << "\nelements of queue: \n";
    if (begin == NULL)   //����� �� �����
        cout << "No elements" << endl;
    else
        view(begin);
    t = minElem(begin);    //����������� ������������
    cout << "minimum=" << t->info << endl;
    DeltoMin(&begin, &t);   //�������� �� ������������
    cout << "\nnew Queue:\n";
    view(begin);
    return 0;
}
void create(Number** begin, Number** end, int p) //������������ ��������� �������
{
    Number* t = new Number;
    t->next = NULL;
    if (*begin == NULL)
        *begin = *end = t;
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}
void view(Number* begin) //����� ��������� ������� 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Number is empty\n";
        return;
    }
    else
        while (t != NULL)
        {
            cout << t->info << endl;
            t = t->next;
        }
}
Number* minElem(Number* begin) //����������� ������������ ��������
{
    Number* t = begin, * mn = nullptr;
    int min;
    if (t == NULL)
    {
        cout << "Number is empty\n"; return 0;
    }
    else
    {
        min = t->info;
        while (t != NULL)
        {
            if (t->info <= min)
            {
                min = t->info;
                mn = t;
            }
            t = t->next;
        }
    }
    return mn;
}
void DeltoMin(Number** begin, Number** p) //�������� �� ������������ �������� 
{
    Number* t;
    t = new Number;
    while (*begin != *p)
    {
        t = *begin;
        *begin = (*begin)->next;
        delete t;
    }
}
