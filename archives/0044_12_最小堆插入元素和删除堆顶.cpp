// 对于给定的最小堆（优先队列），分别实现插入元素和删除堆顶的函数。
//
// NOTE: 堆元素从data[1]开始存放，data[0]不使用，无哨兵元素

// Sample Input
// 6
// 1 10
// 1 20
// 1 5
// 1 20
// 1 50
// 1 1
// 1 40
// -1
// -1
// -1
// -1
// -1
// -1
// -1
// 0

// Sample Output
// Insertion succeeded. 10, 
// Insertion succeeded. 10, 20, 
// Insertion succeeded. 5, 20, 10, 
// Insertion succeeded. 5, 20, 10, 20, 
// Insertion succeeded. 5, 20, 10, 20, 50, 
// Insertion succeeded. 1, 20, 5, 20, 50, 10, 
// Insertion failed. 1, 20, 5, 20, 50, 10, 
// 1 deleted. 5, 20, 10, 20, 50, 
// 5 deleted. 10, 20, 50, 20, 
// 10 deleted. 20, 20, 50, 
// 20 deleted. 20, 50, 
// 20 deleted. 50, 
// 50 deleted. 
// Deletion failed. 

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>
struct Heap{
    int *data;
    int capacity;
    int size;
};
struct Heap* initHeap(int capacity){   // 初始化堆
    struct Heap* h;
    h = (struct Heap*)malloc(sizeof(struct Heap));
    if(!h) return NULL;
    h->data = (int*)malloc(sizeof(int)*capacity+1);
    if(h->data == NULL){
        free(h);
        return NULL;
    }
    h->capacity = capacity;
    h->size = 0;
    return h;
};
void printHeap(struct Heap* h);  // 打印堆元素，细节省略
int insertIntoHeap(struct Heap* h, int x);
int deleteMin(struct Heap* h, int* pElement);
int main(){
    struct Heap *h;
    int n;
    scanf("%d", &n);   // 输入堆容量
    h = initHeap(n);
    int op, x;
    scanf("%d", &op);
    while(op){    // 输入操作： -1表示删除   1表示插入   0表示结束
        if(op == 1){
            scanf("%d", &x);
            printf("Insertion %s. ", insertIntoHeap(h, x) ? "succeeded" : "failed" );
            printHeap(h);
        }
        else{
            if (deleteMin(h, &x) ) printf("%d deleted. ", x);
            else printf("Deletion failed. ");
            printHeap(h);
        }
        scanf("%d", &op);
    }
    return 0;
}
// Prepend Code End

// 补充定义
void printHeap(struct Heap *h) {
  for (int i = 1; i <= h->size; i++) {
    printf("%d, ", h->data[i]);
  }
  putchar(10);
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int insertIntoHeap(struct Heap *h, int x) {
  if (h->size >= h->capacity)
    return 0;

  h->data[++h->size] = x;

  int i = h->size;
  while (i > 1) {
    int parent = i / 2;

    if (h->data[parent] <= h->data[i])
      break;

    swap(&h->data[parent], &h->data[i]);

    i = parent;
  }

  return 1;
}

int deleteMin(struct Heap *h, int *pElement) {
  if (h->size == 0)
    return 0;

  *pElement = h->data[1];

  swap(&h->data[1], &h->data[h->size]);

  int i = 1;
  while (1) {
    int left = 2 * i;
    int right = 2 * i + 1;
    int j = i;

    if (left < h->size && h->data[left] < h->data[j])
      j = left;
    if (right < h->size && h->data[right] < h->data[j])
      j = right;

    if (j == i)
      break;

    swap(&h->data[i], &h->data[j]);

    i = j;
  }

  h->size--;

  return 1;
}
