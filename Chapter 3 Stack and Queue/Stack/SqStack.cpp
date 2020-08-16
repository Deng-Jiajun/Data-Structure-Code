#include <iostream>
#include <stdlib.h>
using namespace std;

// 顺序栈 静态分配
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1; // 栈顶指针即栈顶元素在数组中的下标,初始化为-1
}

// 栈空判断
bool StackEmpty(SqStack S)
{
    return S.top == -1; // 栈顶指针为-1，栈空
}

// 栈满判断
bool StackFull(SqStack S)
{
    return S.top == MaxSize - 1; // S.top∈[-1,MaxSize-1]
}

// 入栈
bool Push(SqStack &S, int x)
{
    if (StackFull(S)) // 栈满，无法插入
        return false;
    S.data[++S.top] = x;
    return true;
}

// 出栈
bool Pop(SqStack &S, int &x)
{
    if (StackEmpty(S)) // 栈空，没得元素出栈
        return false;
    x = S.data[S.top--]; // 通过x传回栈顶元素，并且让top向下一格
    return true;
}

// 获取栈顶元素
bool Top(SqStack S, int &x)
{
    if (StackEmpty(S)) // 栈空，没得元素
        return false;
    x = S.data[S.top]; // 通过x传回栈顶元素
    return true;
}

// 测试入栈
void TestPush(SqStack &S,int x)
{
cout << "Push("<<x<<"): " << Push(S, x)<<", ";
cout << "x=" << x << endl;
}

// 测试出栈
void TestPop(SqStack &S)
{
    int x;
    cout << "Pop( ): " << Pop(S, x) << ", ";
    cout << "x=" << x << endl;
}
int main(void)
{
    SqStack stack;    // 声明
    InitStack(stack); // 初始化

    cout << "StackEmpty( ): " << StackEmpty(stack) << endl; // 栈空
    cout << "StackFull( ): " << StackFull(stack) << endl;   // 栈满

    // 入栈
    TestPush(stack, 0);
    TestPush(stack, 1);
    TestPush(stack, 2);
    TestPush(stack, 3);
    TestPush(stack, 4);
    TestPush(stack, 5);
    TestPush(stack, 6);
    TestPush(stack, 7);
    TestPush(stack, 8);
    TestPush(stack, 9);
    TestPush(stack, 10); // error

    int x;
    // 栈顶
    cout << "Top( ): " << Top(stack, x) << ", ";
    cout << "x=" << x << endl;

    // 出栈
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);
    TestPop(stack);  // error
    

    return 0;
}