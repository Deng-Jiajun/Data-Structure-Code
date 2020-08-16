#include <iostream>
#include <stdlib.h>
using namespace std;

// 链栈（带头结点）
// head -> Stack[top] -> ···
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkStack;

bool InitStack(LinkStack &S)
{
    S = (LNode *)malloc(sizeof(LNode)); // 分配头结点内存空间
    if (S == NULL)
        return false;
    S->next = NULL;
    return true;
}

// 栈空判断
bool StackEmpty(LinkStack S)
{
    return S->next == NULL; // 头结点后无元素，栈空
}

// 栈满判断
bool StackFull(LinkStack S)
{
    return false; // 链栈原则上没有容量限制
}

// 入栈
bool Push(LinkStack &S, int x)
{
    // 链栈无栈满
    LNode *p = (LNode *)malloc(sizeof(LNode)); // 创建结点
    if (p == NULL)
        return false;
    p->data = x;

    p->next = S->next; // 结点插入头结点之后
    S->next = p;
    return true;
}

// 出栈
bool Pop(LinkStack &S, int &x)
{
    if (StackEmpty(S)) // 栈空，没得元素出栈
        return false;

    LNode *p = S->next;      // 取点
    x = p->data;             // 通过x传回栈顶元素
    S->next = S->next->next; // 摘链
    free(p);                 // 销毁
    return true;
}

// 获取栈顶元素
bool Top(LinkStack S, int &x)
{
    if (StackEmpty(S)) // 栈空，没得元素
        return false;
    x = S->next->data; // 通过x传回栈顶元素
    return true;
}

// 测试入栈
void TestPush(LinkStack &S, int x)
{
    cout << "Push(" << x << "): " << Push(S, x) << ", ";
    cout << "x=" << x << endl;
}

// 测试出栈
void TestPop(LinkStack &S)
{
    int x;
    cout << "Pop( ): " << Pop(S, x) << ", ";
    cout << "x=" << x << endl;
}

int main(void)
{
    LinkStack stack;  // 声明
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
    // TestPush(stack, 10);

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
    TestPop(stack); // error

    return 0;
}
