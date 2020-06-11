#include <iostream>
using namespace std;

// 顺序表 静态分配
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqList;

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

int GetElem(SqList L,int i){
    
}
int main(void)
{

    return 0;
}