/*7 - 3 数据结构实验一 顺序表的删除
分数 20
作者 王群芳
单位 合肥师范学院
以顺序表作存储结构，实现线性表的创建、删除。

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
第三行 待删除元素位置
具体格式参看输入样例

输出格式 :
输出分两行

第一行 删除前的线性表

第二行 删除后的线性表。如因删除位置错误失败，输出Delete position error!。

具体格式参看输出样例

输入样例 :
5
2 4 6 8 10
3
输出样例 :
	Before : (2, 4, 6, 8, 10)
	After : (2, 4, 8, 10)
	输入样例 :
	5
	2 4 6 8 10
	6
	输出样例 :
	Before : (2, 4, 6, 8, 10)
	Delete position error!*/
#include<iostream>
using namespace std;
#define MAXSIZE 10     // MAXSIZE为最大数据元素数目
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

    }//在 DeleteList 函数中，虽然有判断语句 if (!p)，但是当 deletenum > n 时，由于 p 已经指向了链表末尾的 NULL，而 p->next 为 NULL，所以 q 为 NULL，从而导致 free(q) 出现段错误。需要在判断语句中加入 deletenum <= n 的条件。
    else if (deletenum <= n)
    {
        LinkList q = p->next;//有可能p指向最后一个元素此时p不为NULL,p->next为NULL,q=p->next为NULL,此时free(q)会出现段错误
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