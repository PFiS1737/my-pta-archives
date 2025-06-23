// 本题要求实现二分查找算法。
//
// NOTE: 查找失败时返回 `NotFound`

// Sample Input
// 5
// 12 31 55 89 101
// 31

// Sample Output
// 2

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
// Prepend Code End

Position BinarySearch(List L, ElementType X) {
  int low = 1, high = L->Last, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (L->Data[mid] < X) {
      low = mid + 1;
    } else if (L->Data[mid] > X) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return NotFound;
}
