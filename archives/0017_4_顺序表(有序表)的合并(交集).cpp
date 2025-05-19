// 目标顺序表中只保存两个源表中相同的元素。

// Sample Input
// 5
// 1 3 4 6 7
// 7
// 1 2 3 5 6 8 9

// Sample Output
// 1 3 6

// Prepend Code Start
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int size, length;
  long long *element;
} LIST;

void Create(LIST *L);
void Destroy(LIST *L);
void Input(LIST *L);
void Output(LIST *L);

void Mul(LIST *dst, const LIST *src1, const LIST *src2);

int main() {
  LIST a, b, c;
  Create(&a);
  Create(&b);
  Create(&c);
  Input(&a);
  Input(&b);
  Mul(&c, &a, &b);
  Output(&c);
  putchar('\n');
  Destroy(&c);
  Destroy(&b);
  Destroy(&a);
  return 0;
}
// Prepend Code End

void Mul(LIST *dst, const LIST *src1, const LIST *src2) {
  int i = 0, j = 0, k = 0;

  while (i < src1->length && j < src2->length) {
    if (src1->element[i] < src2->element[j]) {
      i++;
    } else if (src1->element[i] > src2->element[j]) {
      j++;
    } else {
      if (k == dst->size) {
        dst->size = (dst->size + 1) * 2;
        dst->element = (long long *)realloc(dst->element, dst->size * sizeof(long long));
      }
      dst->element[k++] = src1->element[i];
      i++;
      j++;
    }
  }

  dst->length = k;
}
