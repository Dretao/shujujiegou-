/*7 - 2 数据结构实验一 顺序表的插入
分数 19
作者 王群芳
单位 合肥师范学院
以顺序表作存储结构，实现线性表的创建、插入。

顺序表的类型描述

#define MAXSIZE 10     // MAXSIZE为最大数据元素数目
typedef int ElemType;
typedef struct
{
	ElemType* elem;
	int length;
} SqList;
输入格式:
输入分三行

第一行 元素个数
第二行 元素的值。元素间以空格分隔。
第三行 待插入的位置和元素值
具体格式参看输入样例

输出格式 :
输出分两行

第一行 插入前的线性表
第二行 插入后的线性表。 如因插入位置错误失败，输出Insert position error!如因为表满插入失败，输出OVERFLOW!
具体格式参看输出样例

输入样例 :
5
1 3 5 7 9
3 4
输出样例 :
	Before : (1, 3, 5, 7, 9)
	After : (1, 3, 4, 5, 7, 9)
	输入样例 :
	5
	1 3 5 7 9
	7 10
	输出样例 :
	Before : (1, 3, 5, 7, 9)
	Insert position error!
	输入样例 :
	10
	1 2 3 4 5 6 7 8  9 10
	6 7
	输出样例 :
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
        cin >> p->next->data; // 输入元素的值
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
    }//因为当插入元素大于链表原有元素个数时循环还会继续既!p,P=NULL
    if (p==NULL)//当插入位置错误
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
    int n;//元素个数
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