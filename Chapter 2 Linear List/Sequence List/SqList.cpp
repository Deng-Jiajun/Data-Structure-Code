#include <iostream>
#include <stdlib.h>
using namespace std;

// ----------------------------------------------------------------
// // 补充：动态分配版本
// #define InitSize 10
// typedef struct
// {
//     int *data;
//     int MaxSize;
//     int length;
// } SeqList;

// // 动态分配版本初始化
// void InitList(SeqList &L)
// {
//     L.data = (int *)malloc(InitSize * sizeof(int));
//     L.length = 0;
//     L.MaxSize = InitSize;
// }

// // 增加顺序表长度
// void IncreaseSize(SeqList &L, int len)
// {
//     int *p = L.data;
//     L.data = (int *)malloc((L.MaxSize + len) * sizeof(int));
//     for (int i = 0; i < L.length; ++i)
//     {
//         L.data[i] = p[i];
//     }
//     L.MaxSize += len;
//     free(p);
// }
// ----------------------------------------------------------------

// 顺序表 静态分配
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

void InitList(SqList &L)
{
    L.length = 0;
}

// 按位插入
bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1) // 判断i的范围是否有效，i∈[1,length+1],线性表是连续的序列，没有空值
        return false;
    if (L.length == MaxSize) // 表已经满了
        return false;

    for (int j = L.length; j >= i; j--) // data[index],index∈[i-1,length-1]，依次往后挪一格
        L.data[j] = L.data[j - 1];

    L.data[i - 1] = e; // i-1,位序∈[1,length],数组下标∈[1,length-1]
    L.length++;
    return true;
}

// 按位删除
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) // 判断i的范围是否有效（i∈[1,length]
        return false;
    e = L.data[i - 1]; // 把值先传回去

    for (int j = i; j < L.length; j++) // data[index],index∈[i-1,length-1]，依次往前挪一格
        L.data[j - 1] = L.data[j];

    L.length--;
    return true;
}
// 按位查找，返回第i个元素
int GetElem(SqList L, int i)
{
    if (i <= L.length)
        return L.data[i - 1];
    else
        return -1;
}

// 按值查找，返回e所在的 *位序*
int LocateElem(SqList L, int e)
{
    for (int i = 0; i < L.length; ++i)
        if (L.data[i] == e)
            return i + 1;
    return 0;
}

// ----------------------------------------------------------------
// 补充：PrintList
void PrintList(SqList L)
{
    cout << "The SqList:" << ends;
    for (int i = 0; i < L.length; ++i)
        cout << L.data[i] << " ";
    if (L.length > 0)
        cout << endl;
    else
        cout << "is empty" << endl;
}
// ----------------------------------------------------------------

int main(void)
{
    SqList sqList;
    InitList(sqList);

    cout << "After initialization:";
    PrintList(sqList);

    // 插入
    ListInsert(sqList, 1, 3);
    ListInsert(sqList, 1, 4);
    ListInsert(sqList, 1, 5);

    cout << "After insert:";
    PrintList(sqList);

    // 按位查找
    cout << "run GetElem: "
         << "L1:" << GetElem(sqList, 1) << " L2:" << GetElem(sqList, 2) << " L3:" << GetElem(sqList, 3) << endl;

    // 按值查找
    int searched=5;
    cout<<searched<<" in L["<<LocateElem(sqList,searched)<<"]"<<endl;
    
    // 删除
    int deleted;
    ListDelete(sqList, 2, deleted);

    cout << "After delete:";
    PrintList(sqList);

    return 0;
}