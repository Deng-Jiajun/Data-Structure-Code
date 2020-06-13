#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 建立

// 按位插入
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) // 最后一次执行该判断时，j==i-2
    {
        p = p->next;
        j++;
    } // 走出循环时，若p！= NULL， p将指向第i-1个结点

    /**
    if (p == NULL) // 表长<i-1，i值不合法
        return false;

    // 创建结点并赋值
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false; // 内存分配失败，直接返回false
    s->data = e;

    // 在结点p后插入结点s
    s->next = p->next;
    p->next = s;
    return true;
    */
    return InsertNextNode(p, e); // 替换上方代码块（重复代码提取）
}

// XXX
// 按位插入(不带头结点)
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    if (i == 1) // 创建结点，连上原头结点
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL)
            return false; // 内存分配失败，直接返回false
        s->data = e;
        s->next = L;
        L = s; // 新结点作为头结点
        return true;
    }
    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) // 最后一次执行该判断时，j==i-2
    {
        p = p->next;
        j++;
    } // 走出循环时，若p！= NULL， p将指向第i-1个结点

    /**
    if (p == NULL) // 表长<i-1，i值不合法
        return false;

    // 创建结点并赋值
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false; // 内存分配失败，直接返回false
    s->data = e;

    // 在结点p后插入结点s
    s->next = p->next;
    p->next = s;
    return true;
    */
    return InsertNextNode(p, e); // 替换上方代码块（重复代码提取）
}

// 在结点p *后* 插入结点，data值为e
bool InsertNextNode(LNode *p, int e)
{
    if (p == NULL)
        return false;

    // 创建结点
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false; // 内存分配失败，直接返回false
    s->data = e;

    // 插入结点
    s->next = p->next;
    p->next = s;
    return true;
}

// 在结点p *前* 插入结点，data值为e
/**
 * 方案1：遍历找到p的前驱结点，在它的前驱结点后插入，时间复杂度O(n)；附加条件：需要传入链表头指针
 * 方案2：在p后插入结点s，将s->data设为p->data，将p->data设为e，时间复杂度O(1)；无附加条件
 */

// 方案1
bool InsertPriorNode(LinkList &L, LNode *p, int e)
{
    if (L == NULL || p == NULL)
        return false;

    LNode *current = L;
    while (current != NULL && current->next != p)
    {
        current = current->next;
    } // 出循环时，若current != NULL，current将指向p的前驱结点

    if (current == NULL) // 找了一溜下来，没找到结点p，说明p不在L上
        return false;

    // 反之，找到了p的前驱结点，在p的前驱结点后插入结点，data值为e
    return InsertNextNode(current, e);
}

// 方案2
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    int temp = p->data;
    InsertNextNode(p, temp);
    p->data = e;
    return true;
}
// ↑ 方案2 参数不同的版本，在结点p *前* 插入结点s
bool InsertPriorNode(LNode *p, LNode *s)
{
    if (p == NULL || s == NULL)
        return false;

    // 后插法接入
    s->next = p->next;
    p->next = s;

    // 交换data
    int temp = p->data;
    p->data = s->data;
    s->data = temp;
    return true;
}

// 按位删除
bool ListDelete(LinkList &L, int i, int &e)
{
    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    } // 出循环时，若p！= NULL，则p指向第i-1个结点，记第i个结点的前驱结点

    if (p == NULL) // p值为空，说明表长length<i，i值不合法
        return false;

    // 找到第i-1个结点并不代表第i个结点存在
    if (p->next == NULL) // 第i个结点不存在
        return false;

    LNode *deleted = p->next;
    p->next = deleted->next;

    e = deleted->data; // 别忘了还要返回data值
    free(deleted);     // 释放空间
    return true;
}

/**
 *  删除指定结点p
 * 方案1：通过头结点L遍历找到p的 *前驱结点*q，然后 q->next=p->next;
 * 方案2：把p的 *后继结点*q的data赋给p->data，然后把q删掉
 */

// 删除指定结点p，不给你头结点L
// 方案1 （“我自己杀自己”）；限制条件：若p为最后一个结点，此方案*无效*
bool DeleteNode(LNode *p)
{
    if (p == NULL || p->next == NULL) // p值不合法||情况不适用
        return false;
        
    LNode *q = p->next;
    p->data = q->data;
    p->next = q->next;
    free(q);
    return true;
}