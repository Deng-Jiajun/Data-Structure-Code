#include <iostream>
#include <stdlib.h>
using namespace std;

// 顺序队列 静态分配
// 牺牲一个存储空间做队满判断，rear指向队尾元素的下一个位置
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int front, rear;
} SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q)
{
    Q.front = Q.rear = 0; // front指向队头元素所在位置，rear指向队尾元素的下一个位置
}

// 队空判断
bool QueueEmpty(SqQueue Q)
{
    return Q.front == Q.rear;
}

// 队满判断
bool QueueFull(SqQueue Q)
{
    return (Q.rear + 1) % MaxSize == Q.front; // 队尾再向后一个位置是front，队满
}

// 入队，与队头无关，只需要修改队尾指针rear
bool EnQueue(SqQueue &Q, int x)
{
    if (QueueFull(Q)) // 栈满，无法插入
        return false;

    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize; // 空间抽象为环状使用
    return true;
}

// 出队
bool DeQueue(SqQueue &Q, int &x)
{
    if (QueueEmpty(Q)) // 队空，没得元素出队
        return false;
    x = Q.data[Q.front];               // 通过x传回队头元素
    Q.front = (Q.front + 1) % MaxSize; // 并且让front向后一格

    return true;
}

// 获取队头元素
bool GetHead(SqQueue Q, int &x)
{
    if (QueueEmpty(Q)) // 队空，没得元素
        return false;
    x = Q.data[Q.front]; // 通过x传回队头元素
    return true;
}

// 测试入队
void TestEnQueue(SqQueue &Q, int x)
{
    cout << "EnQueue(" << x << "): " << EnQueue(Q, x) << ", ";
    cout << "x=" << x << endl;
}

// 测试出栈
void TestDeQueue(SqQueue &Q)
{
    int x=-1;
    cout << "DeQueue( ): " << DeQueue(Q, x) << ", ";
    cout << "x=" << x << endl;
}
int main(void)
{
    SqQueue Queue;    // 声明
    InitQueue(Queue); // 初始化

    cout << "QueueEmpty( ): " << QueueEmpty(Queue) << endl; // 栈空
    cout << "QueueFull( ): " << QueueFull(Queue) << endl;   // 栈满

    // 入栈
    TestEnQueue(Queue, 0);
    TestEnQueue(Queue, 1);
    TestEnQueue(Queue, 2);
    TestEnQueue(Queue, 3);
    TestEnQueue(Queue, 4);
    TestEnQueue(Queue, 5);
    TestEnQueue(Queue, 6);
    TestEnQueue(Queue, 7);
    TestEnQueue(Queue, 8);
    TestEnQueue(Queue, 9);
    TestEnQueue(Queue, 10); // error

    int x;
    // 栈顶
    cout << "GetHead( ): " << GetHead(Queue, x) << ", ";
    cout << "x=" << x << endl;

    // 出栈
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue);
    TestDeQueue(Queue); // error

    return 0;
}