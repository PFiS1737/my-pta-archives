// 编写函数计算二叉树的深度以及叶子节点数。二叉树采用二叉链表存储结构

// Sample Input
// 1 3 0 0 5 7 0 0 0

// Sample Output
// 3 2

// Prepend Code Start
//头文件包含
#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>

//函数状态码定义
#define TRUE       1
#define FALSE      0
#define OK         1
#define ERROR      0
#define OVERFLOW   -1
#define INFEASIBLE -2
#define NULL  0
typedef int Status;

//二叉链表存储结构定义
typedef int TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode  *lchild, *rchild; 
} BiTNode, *BiTree;

//创建二叉树各结点，输入零代表创建空树
//采用递归的思想创建
//递归边界：空树如何创建呢：直接输入0；
//递归关系：非空树的创建问题，可以归结为先创建根节点，输入其数据域值；再创建左子树；最后创建右子树。左右子树递归即可完成创建！

Status CreateBiTree(BiTree &T){
   TElemType e;
   scanf("%d",&e);
   if(e==0)T=NULL;
   else{
     T=(BiTree)malloc(sizeof(BiTNode));
     if(!T)exit(OVERFLOW);
     T->data=e;
     CreateBiTree(T->lchild);
     CreateBiTree(T->rchild);
   }
   return OK;  
}

//下面是需要实现的函数的声明
int GetDepthOfBiTree ( BiTree T);
int LeafCount(BiTree T);
//下面是主函数
int main()
{
   BiTree T;
   int depth, numberOfLeaves;
   CreateBiTree(T);
   depth= GetDepthOfBiTree(T);
     numberOfLeaves=LeafCount(T);
   printf("%d %d\n",depth,numberOfLeaves);
}
// Prepend Code End


int GetDepthOfBiTree(BiTree T) {
  if (T == NULL)
    return 0;

  int left = GetDepthOfBiTree(T->lchild);
  int right = GetDepthOfBiTree(T->rchild);
  return (left > right ? left : right) + 1;
}
int LeafCount(BiTree T) {
  if (!T)
    return 0;

  if (!T->lchild && !T->rchild)
    return 1;

  return LeafCount(T->lchild) + LeafCount(T->rchild);
}
