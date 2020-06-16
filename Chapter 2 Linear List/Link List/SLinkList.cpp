#include <iostream>
#include <stdlib.h>
using namespace std;

#define MaxSize 10
typedef struct
{
    int data;
    int next; // 下个元素的*数组下标*
} SLinkList[MaxSize];

// L[0] 是头结点，不存值
void InitList(SLinkList &L)
{
    L[0].next = -1; // next==-1 表示这是表尾，若L[0].next==-1 表示是空表
    for (int i = 1; i < MaxSize; i++)
    {
        L[i].data = -2; // 为测试效果，将其初始化为-2，实际场景不需要
        L[i].next = -2; // next==-1 表示这个位置未分配
    }
    // next: -1 -2 -2 -2 -2 -2 -2 -2 -2 -2
}

void PrintDataList(SLinkList L)
{
    cout << "data\t\t\tnext" << endl;
    for (int i = 0; i < MaxSize; i++)
        cout << L[i].data << "\t\t\t" << L[i].next << endl;
}

// 测试函数，传入数据
void SLinkListTest(SLinkList &L)
{
    L[0].data = -9; // 头结点data域设为-9，以作区别
    L[0].next = 2;
    L[1].data = 02;
    L[1].next = 6;
    L[2].data = 01;
    L[2].next = 1;
    L[3].data = 04;
    L[3].next = -1;
    L[6].data = 03;
    L[6].next = 3;

    /**
     * index data next
     *  0     头    2
     *  1     e2    6
     *  2     e1    1
     *  3     e4   -1
     *  4
     *  5
     *  6     e3    3
     *  7
     *  8
     *  9
     */
}

void PrintList(SLinkList L)
{
    if (L[0].next == -1)
        cout << "This is empty" << endl;
    else
    {
        cout << "List: ";
        // L[0] 就是头结点
        int next = L[0].next; // L[0].next 就是第一个结点的数组下标
        while (next != -1)
        {
            cout << "e"<<L[next].data << " "; // 这边加了个e,表示是第几个元素
            next = L[next].next;
        }
        cout << endl;
    }
}

// TODO 查找算法    思路：通过next，挨个遍历

// TODO 插入位序为i的结点   思路：找到空的位置(next=-2)，写入data，修改next的值

// TODO 删除某个结点    思路：修改next的值

int main(void)
{
    SLinkList L;
    InitList(L);
    PrintDataList(L);

    SLinkListTest(L);
    PrintDataList(L);

    PrintList(L);

    return 0;
}