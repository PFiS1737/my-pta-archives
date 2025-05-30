// 用孩子兄弟法表示一棵树或者一个森林，编写函数输出其叶子数

// Sample Input
// ABH**CE*FG***D***
// *
// AB*C*D***

// Sample Output
// 4
// 0
// 3

// Prepend Code Start
//头文件包含
#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;

//函数状态码定义
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define OVERFLOW   -1
#define INFEASIBLE -2
typedef int Status;

char s[31];
int cnt=0;

//树和森林的孩子兄弟法存储结构定义
typedef char TElemType;
typedef struct CSNode
{
    TElemType data;
    struct CSNode *firstChild;
    struct CSNode *nextSibling;
}CSTNode,*CSTree;

Status CreateCSTree(CSTree &CST)
{
    TElemType e;
    e=s[cnt++];
    if(e=='*')
        CST=NULL;
    else
    {
        CST=(CSTNode*)malloc(sizeof(CSTNode));
        if(!CST)
            exit(OVERFLOW);
        CST->data=e;
        CreateCSTree(CST->firstChild);
        CreateCSTree(CST->nextSibling);
    }
    return OK;
}

//下面是需要实现的函数的声明
int LeafCountOfCSTree(CSTree CST);
//下面是主函数
int main()
{
   CSTree CST;
    while(cin>>s)
    {
        CreateCSTree(CST);
        cout << LeafCountOfCSTree(CST);
        cout << endl;
        cnt=0;
        
    }
    return 0;
}
// Prepend Code End

int LeafCountOfCSTree(CSTree CST) {
  if (!CST)
    return 0;

  int leavesSubForest = LeafCountOfCSTree(CST->nextSibling);

  if (!CST->firstChild)
    return leavesSubForest + 1;

  return leavesSubForest + LeafCountOfCSTree(CST->firstChild);
}
