#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define MaxSize 10
typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

// 括号匹配：依次扫描表达式，左括号入栈，碰到右括号就弹出栈顶的括号，检查是否匹配
bool BracketMatching(const char str[], int length)
{
    // 栈初始化
    SqStack S;
    S.top = -1; // 栈顶指针为栈顶元素数组下标

    // 开始匹配

    for (int i = 0; i < length; ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            S.data[++S.top] = str[i]; // 左括号，入栈
        }
        else
        {
            if (S.top == -1)  // 扫描到右括号，栈空
                return false; // 匹配失败

            char topElem = S.data[S.top--]; // 栈顶元素出栈

            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }

    return S.top == -1; // 若栈空，说明全部括号成功匹配完毕
}
int main(void)
{
    const char *right = "{(())[]}";
    const char *error = "{(()][]}";
    cout << right << " : " << BracketMatching(right, sizeof(right)) << endl;
    cout << error << " : " << BracketMatching(error, sizeof(error)) << endl;
    return 0;
}