// 整数数组中存储有N个整数，编写函数，找出并返回第k大的数。
// 要求时间复杂度要优于O(NlogN)。题目确保输入的K是合法的（1<=k<=N)。你可以认为k远小于N。
//
// INFO: 手写小根堆实现

// Sample Input
// 100 30

// Sample Output
// 74

// Prepend Code Start
#include <iostream>
using namespace std;

int funKth(int d[], int N, int k);

int main() {
  int N, k;
  cin >> N >> k;

  int d[N];
  srand(2025530);
  for (int i = 0; i < N; i++) {
    d[i] = rand() % 101;
  }

  cout << funKth(d, N, k) << endl;

  return 0;
}
// Prepend Code End

#include <stdlib.h>

typedef struct {
  int *heap;
  int size;
} Heap;

Heap *initHeap(int capacity) {
  Heap *heap = (Heap *)malloc(sizeof(Heap));
  heap->heap = (int *)malloc(capacity * sizeof(int));
  heap->size = 0;
  return heap;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void up(Heap *h, int i) {
  while (i > 0) {
    int p = (i - 1) / 2;
    if (h->heap[i] >= h->heap[p]) {
      break;
    }
    swap(&h->heap[i], &h->heap[p]);
    i = p;
  }
}

void down(Heap *h, int i) {
  int s = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;

  if (l < h->size && h->heap[l] < h->heap[s]) {
    s = l;
  }
  if (r < h->size && h->heap[r] < h->heap[s]) {
    s = r;
  }

  if (s != i) {
    swap(&h->heap[i], &h->heap[s]);
    down(h, s);
  }
}

void enqueue(Heap *h, int n) {
  h->heap[h->size] = n;
  up(h, h->size);
  h->size++;
}

int dequeue(Heap *h) {
  int min = h->heap[0];
  h->heap[0] = h->heap[h->size - 1];
  h->size--;
  down(h, 0);
  return min;
}

int peek(Heap *h) {
  return h->heap[0];
}

int funKth(int d[], int N, int k) {
  Heap *h = initHeap(k);

  int i = 0;
  while (h->size < k)
    enqueue(h, d[i++]);

  for (; i < N; i++) {
    if (d[i] > peek(h)) {
      dequeue(h);
      enqueue(h, d[i]);
    }
  }

  return peek(h);
}
