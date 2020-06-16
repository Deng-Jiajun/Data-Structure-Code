#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

// 循环双链表初始化
bool InitLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = L; // 空的循环双链表，头结点的prior域和next域都指向头结点本身
    L->next = L;

    return true;
}

// 循环双链表判空
bool Empty(DLinkList L)
{
    return (L->next == L);
}

// 结点p是否是循环双链表的表尾结点
bool isTail(DLinkList L, DNode *p)
{
    return (p->next == L);
}

// 在结点p之后插入结点s
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
        return false;

    s->next = p->next;
    s->prior = p;
    p->next->prior = s; // 循环链表，不需要判断 p->next 是否为空
    p->next = s;
}

// 删除结点p的后继结点
// 注意：p不能是表尾结点，p若是表尾结点，它的下一个结点是表头结点L，而不是第一个结点
// 解决方案：给表头结点data赋个特殊值，做一个区别
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
        return false;

    DNode *q = p->next;
    p->next=q->next;
    q->next->prior=p;

    free(q);
    return true;
}