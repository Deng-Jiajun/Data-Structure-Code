#include <iostream>
#include <stdlib.h>
using namespace std;

// 共享栈
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top0; // 0号栈栈顶指针
    int top1; // 1号栈栈顶指针
} ShStack;

/**
 * 0号栈：0->1->2->3->4->···
 * 1号栈：9->8->7->6->5->···
 */

// 初始化栈
void InitStack(ShStack &S)
{
    S.top0=-1;
    S.top1=MaxSize;
}

// 栈满判断
bool StackFull(ShStack S)
{
    return S.top0+1==S.top1;
}

