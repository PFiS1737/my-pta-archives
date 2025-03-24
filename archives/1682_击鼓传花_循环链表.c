// 循环链表解法
//
// Description
// 设有N个人围成一个圈，每人手里都握着一个令牌写明一个数字（随机生成的）。从第一个人开始玩“击鼓传花”游戏，第一个击的次数为其令牌上写明的数字数（假设为m1）。第m1个人出列。下次再从第m1+1个人开始新的“击鼓传花”击的次数也为其令牌上写明的次数，等于该次数的人出列。重复以上过程直到所有人都出列为止。
// Input
// 输入第一行为测试数据组数。每组测试数据2行，第1行一个整数n（1<=n<=10000），代表人数，第2行有n个空格隔开的整数代表mi（1<=mi<=5000）。
// Output
// 对每组测试数据输出2行，第1行为数据组数，第2行为所有人顺序出队的序列，格式见样例。

// Sample Input
// 1
// 10
// 1 2 3 4 5 6 7 8 9 10

// Sample Output
// Case #1:
// 2 6 5 7 10 3 4 1 8

// tnnd，这个题是输出被删掉的那个人的初始位置，而不是他的 m 的值
// 你这个示例真 tmd...

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int value;
  int index;
  struct Node *next;
} Node;

Node *newNode(int value, int index) {
  Node *list = (Node *)malloc(sizeof(Node));
  list->value = value;
  list->index = index;
  list->next = NULL;
  return list;
}

Node *createCircularFromArray(int *array, int size) {
  Node *list = newNode(array[0], 1);
  Node *current = list;
  for (int i = 1; i < size; i++) {
    current->next = newNode(array[i], i + 1);
    current = current->next;
  }
  current->next = list;
  return list;
}

typedef struct {
  Node *newBase;
  int deletedIndex;
} DeleteResult;

/**
 * Delete the nth node after the base node
 */
DeleteResult deleteNNext(Node *base, int n) {
  while (--n) {
    base = base->next;
  }
  Node *toDelete = base->next;
  int index = toDelete->index;
  base->next = toDelete->next;
  free(toDelete);
  return (DeleteResult){
      .newBase = base->next,
      .deletedIndex = index,
  };
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    int len;
    scanf("%d", &len);

    int arr[len];
    for (int j = 0; j < len; j++) {
      scanf("%d", &arr[j]);
    }

    Node *list = createCircularFromArray(arr, len);

    printf("Case #%d:\n", i);
    int isFirst = 1;
    while (list->next != list) {
      DeleteResult result = deleteNNext(list, list->value);
      list = result.newBase;
      printf("%s%d", isFirst ? (isFirst = 0, "") : " ", result.deletedIndex);
    }

    printf("\n");

    free(list);
  }

  return 0;
}
