#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 循环单链表初始化
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) // 内存分配失败
        return false;

    L->next = L; // 尾结点指向头结点，当循环单链表为空时，L->next==L;
    return true;
}

// 循环单链表是否为空
bool Empty(LinkList L)
{
    return (L->next == L);
}

// 结点p是否是表尾结点
bool isTail(LinkList L, LNode *p)
{
    if (p->next == L)
        return true;
    else
        return false;
}

