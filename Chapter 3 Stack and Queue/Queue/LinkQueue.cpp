#include <iostream>
#include <stdlib.h>
using namespace std;

// 链式队列（带头结点）

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

typedef struct
{
    LNode *front, *rear;
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q)
{
    // 初始化时，将front和rear都指向头结点
    Q.front = Q.rear = (LNode *)malloc(sizeof(LNode));
    Q.front->next = NULL; // front 指向头结点，front->next 指向队头元素
}

// 队空判断
bool QueueEmpty(LinkQueue Q)
{
    return Q.front == Q.rear; //  Q.front->next == NULL 应该也行
}

// 队满判断
bool QueueFull(LinkQueue Q)
{
    return false; // 链式队列原则上不会满
}

// 入队，与队头无关，只需要修改队尾指针rear
bool EnQueue(LinkQueue &Q, int x)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if (p == NULL)
        return false;
    p->data = x;
    p->next = NULL;   // p为新的队尾结点，下个位置是空的
    Q.rear->next = p; // 第一次插入时，会将头结点（即front）的next域指向第一个元素p
    Q.rear = p;       // 将rear指向p
    return true;
}

// 出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (QueueEmpty(Q)) // 队空，没得元素出队
        return false;

    LNode *p = Q.front->next; // 取点
    x = p->data;              // 通过x传回队头元素
    Q.front->next = p->next;  // 摘链
    if (Q.rear == p)          // *如果队列上只剩结点p，需要将rear指向front，
        Q.rear = Q.front;     //  以满足队空判定条件，同时避免rear成为野指针*
    free(p);                  // 销毁

    return true;
}

// 获取队头元素
bool GetHead(LinkQueue Q, int &x)
{
    if (QueueEmpty(Q)) // 队空，没得元素
        return false;
    x = Q.front->next->data; // 通过x传回队头元素
    return true;
}

// 测试入队
void TestEnQueue(LinkQueue &Q, int x)
{
    cout << "EnQueue(" << x << "): " << EnQueue(Q, x) << ", ";
    cout << "x=" << x << endl;
}

// 测试出栈
void TestDeQueue(LinkQueue &Q)
{
    int x = -1;
    cout << "DeQueue( ): " << DeQueue(Q, x) << ", ";
    cout << "x=" << x << endl;
}
int main(void)
{
    LinkQueue Queue;  // 声明
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
    // TestEnQueue(Queue, 10);

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

// int main(void)
// {
//     LinkQueue Queue;
//     InitQueue(Queue);
//     EnQueue(Queue,1);
//     return 0;
// }