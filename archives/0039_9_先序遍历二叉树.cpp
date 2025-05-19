// 要求实现函数，输出二叉树的先序遍历序列。

// Sample Input
// HDA**C*B**GF*E***
// -+a**xb**-c**d**/e**f**

// Sample Output
// HDACBGFE
// -+axb-cd/ef

// Prepend Code Start
#include<iostream>
#include<string>
using namespace std;

struct BiTNode {
    char data;
    BiTNode *lchild, *rchild;
};

void PreOrder(BiTNode *T);           //先序遍历
BiTNode *CreateBiTree(string &s);  // 创建二叉树，s存放带虚结点的先序遍历序列

int main() {
    string s;
    while(cin>>s) {
        BiTNode* root=CreateBiTree(s);
        PreOrder(root);
        cout<<endl;
    }    
    return 0;
}

// 按字符串s创建二叉树，返回根结点指针
BiTNode *CreateBiTree(string &s) {
    if(s[0]=='*') {
        s=s.substr(1);
        return NULL; 
    }
    BiTNode *p=new BiTNode;
    p->data=s[0];
    s=s.substr(1);
    p->lchild=CreateBiTree(s);
    p->rchild=CreateBiTree(s);
    return p;
}
// Prepend Code End

void PreOrder(BiTNode *T) {
  if (T) {
    cout << T->data;
    PreOrder(T->lchild);
    PreOrder(T->rchild);
  }
}
