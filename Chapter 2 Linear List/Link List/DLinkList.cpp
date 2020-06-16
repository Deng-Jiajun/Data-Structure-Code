#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 双链表初始化
bool InitDlinklist(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode)); // 建立头结点
    if (L == NULL)                      // 内存分配失败
        return false;

    L->prior = NULL; // 头结点的前驱永远指向NULL
    L->next = NULL;

    return true;
}

// 双链表判空（带头结点）
bool Empty(DLinkList L)
{
    return (L->next == NULL);
}

// 在结点p之后插入结点s
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;

    s->next = p->next;
    s->prior = p;
    if (p->next != NULL) // 判断p的后继结点存在
        p->next->prior = s;
    p->next = s;
}

// 删除结点p的后继结点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;

    DNode *q = p->next;
    if (q == NULL) // p没有后继结点
        return false;

    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;

    free(q);
    return true;
}

// 链表销毁
void DestroyList(DLinkList &L)
{
    while (L->next != NULL)
        DeleteNextDNode(L);
    free(L);
    // 这里传入的不是指针，而是指针的引用，为防止野指针，需将其设NULL
    // 若传入的参数为指针，对其设NULL无意义（传入的为指针指向的地址的值）
    L = NULL;
}

// 前向遍历
void ForwardTraverse(DLinkList &L)
{
    DNode *p = L->next;
    if (p == NULL)
        return; // 空表，直接返回。下方运行的代码前提为：表内至少有一个元素

    while (p->next != NULL) // 遍历至最后一个结点
    {
        p = p->next;
    } // 出循环，p指向表尾

    while (p->prior != NULL) // 若p->prior== NULL，则 p为头结点
    {
        cout << p->data << " ";
        p = p->prior;
    }
}

// 后向遍历
void BackwardTraverse(DLinkList &L)
{
    DNode *p = L->next;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}