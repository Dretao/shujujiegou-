/*7 - 3 ���ݽṹʵ��һ ˳����ɾ��
���� 20
���� ��Ⱥ��
��λ �Ϸ�ʦ��ѧԺ
��˳������洢�ṹ��ʵ�����Ա�Ĵ�����ɾ����

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
������ ��ɾ��Ԫ��λ��
�����ʽ�ο���������

�����ʽ :
���������

��һ�� ɾ��ǰ�����Ա�

�ڶ��� ɾ��������Ա�����ɾ��λ�ô���ʧ�ܣ����Delete position error!��

�����ʽ�ο��������

�������� :
5
2 4 6 8 10
3
������� :
	Before : (2, 4, 6, 8, 10)
	After : (2, 4, 8, 10)
	�������� :
	5
	2 4 6 8 10
	6
	������� :
	Before : (2, 4, 6, 8, 10)
	Delete position error!*/
#include<iostream>
using namespace std;
#define MAXSIZE 10     // MAXSIZEΪ�������Ԫ����Ŀ
typedef int ElemType;
typedef struct SqList
{
    ElemType data;
    SqList* next;
}*LinkList;
void CreateList(LinkList& L, int n)
{
    L = new SqList;
    LinkList p = L;
    for (int i = 0; i < n; i++)
    {
        p->next = new SqList;
        cin >> p->next->data;
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
        {
            cout << ",";
        }
    }
    cout << ")" << endl;
}
void DeleteList(LinkList L, int deletenum, int n)
{
    int j = 0;
    LinkList p = L;
    while (p && j < deletenum - 1)
    {
        p = p->next;
        j++;
    }
    if (!p)
    {

    }//�� DeleteList �����У���Ȼ���ж���� if (!p)�����ǵ� deletenum > n ʱ������ p �Ѿ�ָ��������ĩβ�� NULL���� p->next Ϊ NULL������ q Ϊ NULL���Ӷ����� free(q) ���ֶδ�����Ҫ���ж�����м��� deletenum <= n ��������
    else if (deletenum <= n)
    {
        LinkList q = p->next;//�п���pָ�����һ��Ԫ�ش�ʱp��ΪNULL,p->nextΪNULL,q=p->nextΪNULL,��ʱfree(q)����ֶδ���
        p->next = q->next;
        free(q);
    }
}
void PrintList2(LinkList L, int deletenum, int n)
{
    int j = 1;
    LinkList p = L;
    while (p && j < deletenum)
    {
        p = p->next;
        j++;
    }
    if (deletenum <= n)
    {
        cout << "After:(";
        while (L->next != NULL)
        {
            cout << L->next->data;
            L = L->next;
            if (L->next != NULL)
            {
                cout << ",";
            }
        }
        cout << ")" << endl;
    }
    else if (deletenum > n)
    {
        cout << "Delete position error!";
    }
}
int main()
{
    int n;
    cin >> n;
    LinkList L;
    CreateList(L, n);
    PrintList1(L);
    int deletenum;
    cin >> deletenum;
    DeleteList(L, deletenum, n);
    PrintList2(L, deletenum, n);
    return 0;
}