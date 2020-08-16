#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

// 函数前置声明
bool InsertNextNode(LNode *p, int e);
LNode *GetElem(LinkList L, int i);

// 按位插入
bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;

    /*
    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) // 最后一次执行该判断时，j==i-2
    {
        p = p->next;
        j++;
    } // 走出循环时，若p！= NULL， p将指向第i-1个结点
    */
    LNode *p = GetElem(L, i - 1); // 替换上方代码块（重复代码提取）

    /*
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

// TODO 按位插入(不带头结点) 思路：处理insert逻辑

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
 * 方案1：遍历找到p的前驱结点，在它的前驱结点后插入，时间复杂度O(n)；
 * 附加条件：需要传入链表头指针
 * 
 * 方案2：在p后插入结点s，将s->data设为p->data，将p->data设为e，时间复杂度O(1)；
 * 无附加条件
 */

// 方案1
bool InsertPriorNode(LinkList &L, LNode *p, int e)
{
    if (L == NULL || p == NULL)
        return false;

    LNode *q = L;
    while (q != NULL && q->next != p)
    {
        q = q->next;
    } // 出循环时，若q != NULL，q将指向p的前驱结点

    if (q == NULL) // 找了一溜下来，没找到结点p，说明p不在L上
        return false;

    // 反之，找到了p的前驱结点，在p的前驱结点后插入结点，data值为e
    return InsertNextNode(q, e);
}

// 方案2
bool InsertPriorNode(LNode *p, int e)
{
    if (p == NULL)
        return false;
    int temp = p->data;
    if (!InsertNextNode(p, temp)) // 插入失败
        return false;
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

    /*
    LNode *p = L;
    int j = 0;

    while (p != NULL && j < i - 1) // 最后一次执行该判断时，j==i-2
    {
        p = p->next;
        j++;
    } // 走出循环时，若p！= NULL， p将指向第i-1个结点
    */
    LNode *p = GetElem(L, i - 1); // 替换上方代码块（重复代码提取）

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
 * 方案1：通过头结点L遍历找到p的 *前驱结点*q，然后 q->next=p->next;时间复杂度O(n)
 * 方案2：把p的 *后继结点*q的data赋给p->data，然后把q删掉；时间复杂度O(1)
 */

// 方案1
bool DeleteNode(LinkList &L, LNode *p)
{
    if (L == NULL || p == NULL) // 指针合法性判断
        return false;

    LNode *q = L;
    while (q != NULL && q->next != p)
    {
        q = q->next;
    } // 出循环时，若q != NULL，q将指向p的前驱结点

    if (q == NULL) // 找了一溜下来，没找到结点p，说明p不在L上
        return false;

    // 反之，找到了p的前驱结点q
    q->next = p->next;
    free(p);
    return true;
}

// 方案2 （“我自己杀自己”）无头指针L；限制条件：若p为最后一个结点，此方案*无效*
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

// 按位查找
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
        return NULL;

    LNode *p = L; // 如果i=0，返回头指针
    int j = 0;

    while (p != NULL && j < i) // 最后一次执行该判断时，j==i-1
    {
        p = p->next;
        j++;
    } // 走出循环时，若p！= NULL， p将指向第i个结点

    return p; // 若返回NULL，说明length<i
}

// 按值查找
LNode *GetElemByValue(LinkList L, int e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }

    return p; // 找到了，返回结点指针，没找到，返回NULL
}

// 表长
int Length(LinkList L)
{
    int length = 0;
    LNode *p = L;
    while (p->next != NULL)
    {
        p = p->next;
        length++;
    }
    return length;
}

// TODO 表长(不带头结点)  思路：直接从头结点开始算第一个

// 单链表初始化
bool InitList(LinkList &L)
{
    /**
     * LinkList 只是一个指向LNode的指针，所以,
     * LinkList L; 这样的语句只是声明了一个指针
     */
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL) // 内存分配失败
        return false;
    L->next = NULL;
    return true;
}

/**
 * 尾插法建立单链表（含初始化）
 * 方案1 土办法，循环使用ListInsert()，时间复杂度O(n^2)
 * 方案2 保持一个指向尾部的指针r，每次在r的后面插入结点
 */

// 方案1
/*
LinkList ListTailInsert(LinkList &L)
{
    InitList(L); // 初始化
    int arr[6] = {3, 5, 7, 2, 4, 9999};
    int length = 0;
    int x=arr[0];
    while (x != 9999)
    {
        ListInsert(L,length+1,x);
        x=arr[++length];
    }
    return L;
}
*/

// 方案2
LinkList ListTailInsert(LinkList &L)
{
    InitList(L);                        // 初始化
    int arr[6] = {3, 5, 7, 2, 4, 9999}; // 测试数据
    int length = 0;
    int x = arr[0];
    LNode *r = L;
    while (x != 9999)
    {
        InsertNextNode(r, x);
        x = arr[++length];
        r = r->next;
    }
    r->next = NULL;
    return L;

    // ----------------------------------------------------------------

    /*
    // 王道给出的写法，我看着觉得听别扭
    InitList(L); // 初始化
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s; // s接到r后面

        r = s; // 始终保持r是最后一个结点
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
    */
}

// 头插法建立单链表
LinkList ListHeadInsert(LinkList &L)
{
    InitList(L);                        // 初始化
    int arr[6] = {3, 5, 7, 2, 4, 9999}; // 测试数据
    int length = 0;
    int x = arr[0];
    while (x != 9999)
    {
        InsertNextNode(L, x); // 每次都往头结点后面插入
        x = arr[++length];
    }
    return L;
} // 使用头插法插入时，会将 *数据逆置*

// TODO 头插法建立单链表(不带头结点) 思路：直接创建一个结点作为头结点，next 连接原表

// 补充：PrintList
void PrintList(LinkList L)
{
    if (Length(L) == 0)
        cout << "The list is empty." << endl;
    else
    {
        cout << "List: ";
        LNode *p = L->next; // p指向第一个结点
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
}

int main(void)
{
    LinkList L;  // 声明
    InitList(L); // 初始化
    PrintList(L);

    ListTailInsert(L);
    PrintList(L);

    DeleteNode(L->next); // 指向头一个结点
    PrintList(L);

    DeleteNode(L, L->next); // 再删一个
    PrintList(L);

    cout << "GetElem(L,2)->data: " << GetElem(L, 2)->data << endl;
    cout << "GetElemByValue(L,5): " << GetElemByValue(L, 5) << endl;

    InsertNextNode(L->next, 8);
    PrintList(L);

    InsertPriorNode(L->next, 8);
    PrintList(L);

    int deleted;
    ListDelete(L,1,deleted);
    cout<<"deleted: "<<deleted<<endl;
    PrintList(L);

    ListHeadInsert(L);
    PrintList(L);

    ListInsert(L,3,99);
    PrintList(L);


    return 0;
}