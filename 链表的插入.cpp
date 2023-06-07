/*7 - 2 ���ݽṹʵ��һ ˳���Ĳ���
���� 19
���� ��Ⱥ��
��λ �Ϸ�ʦ��ѧԺ
��˳������洢�ṹ��ʵ�����Ա�Ĵ��������롣

˳������������

#define MAXSIZE 10     // MAXSIZEΪ�������Ԫ����Ŀ
typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int length;
} SqList;
�����ʽ:
���������

��һ�� Ԫ�ظ���
�ڶ��� Ԫ�ص�ֵ��Ԫ�ؼ��Կո�ָ���
������ �������λ�ú�Ԫ��ֵ
�����ʽ�ο���������

�����ʽ :
���������

��һ�� ����ǰ�����Ա�
�ڶ��� ���������Ա� �������λ�ô���ʧ�ܣ����Insert position error!����Ϊ��������ʧ�ܣ����OVERFLOW!
�����ʽ�ο��������

�������� :
5
1 3 5 7 9
3 4
������� :
	Before : (1, 3, 5, 7, 9)
	After : (1, 3, 4, 5, 7, 9)
	�������� :
	5
	1 3 5 7 9
	7 10
	������� :
	Before : (1, 3, 5, 7, 9)
	Insert position error!
	�������� :
	10
	1 2 3 4 5 6 7 8  9 10
	6 7
	������� :
	Before : (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
	OVERFLOW!*/
    #include<iostream>
using namespace std;

typedef int ElemType;
typedef struct SqList
{
    ElemType data;
    SqList* next;
} *LinkList;

void CreateList(LinkList& L,int n)
{
    L = new SqList;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        p->next = new SqList;
        cin >> p->next->data; // ����Ԫ�ص�ֵ
        p = p->next;
    }
    p->next = NULL;
}

void PrintList1(LinkList L)
{
    cout << "Before:(";
    while (L->next != NULL)
    {
        cout << L->next->data;
        L = L->next;
        if (L->next != NULL)
            cout << ",";
    }
    cout << ")" << endl;
}
void PrintList2(LinkList L,int i,int n)
{
    int j = 0;
    LinkList p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }//��Ϊ������Ԫ�ش�������ԭ��Ԫ�ظ���ʱѭ�����������!p,P=NULL
    if (p==NULL)//������λ�ô���
    {
        cout << "Insert position error!";
    }
    else if (n == 10)
    {
        cout << "OVERFLOW!";
    }
    else {
        cout << "After:(";
        while (L->next != NULL)
        {
            cout << L->next->data;
            L = L->next;
            if (L->next != NULL)
                cout << ",";
        }
        cout << ")" << endl;
    }
}

void ListInsert(LinkList L, int i, ElemType e)
{
    int j = 0;
    LinkList p = L;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {
    }
    else
    {
        LinkList s = new SqList;
        s->data = e;
        s->next = p->next;
        p->next = s;
    }
}

int main()
{
    int n;//Ԫ�ظ���
    cin>>n;
    LinkList L;
    CreateList(L,n);
    PrintList1(L);
    int insertnum, insertdata;
    cin >> insertnum >> insertdata;
    ListInsert(L, insertnum, insertdata);
    PrintList2(L,insertnum,n);
    return 0;
}