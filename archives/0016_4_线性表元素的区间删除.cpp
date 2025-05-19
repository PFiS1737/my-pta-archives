// 给定一个顺序存储的线性表，请设计一个函数删除所有值大于min而且小于max的元素。
// 删除后表中剩余元素保持顺序存储，并且相对位置不能改变。

// Sample Input
// 10
// 4 -8 2 12 1 5 9 3 3 10
// 0 4

// Sample Output
// 4 -8 12 5 9 10 

// Prepend Code Start
#include <stdio.h>

#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}
// Prepend Code End

// 补充定义
#include <stdlib.h>
List ReadInput() {
  List L = (List)malloc(sizeof(struct LNode));
  if (!L)
    return NULL;

  int n;
  scanf("%d", &n);
  L->Last = n - 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", &L->Data[i]);
  }
  return L;
}
void PrintList(List L) {
  for (int i = 0; i <= L->Last; i++) {
    printf("%d ", L->Data[i]);
  }
}

List Delete(List L, ElementType minD, ElementType maxD) {
  int i, j;
  for (i = 0, j = 0; i <= L->Last; i++) {
    if (L->Data[i] <= minD || L->Data[i] >= maxD) {
      L->Data[j++] = L->Data[i];
    }
  }
  L->Last = j - 1;
  return L;
}
