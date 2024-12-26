// BigInt 法 (最高位在第一个元素)
//
// Description
// 求出一些整数中的最大值和最小值。
//
// Input
// 输入为多行，以EOF结束。每行为一个十进制的数字，全部由0～9组成，每行最长不超过1000个字符。有些数字会以0开头（不影响数值大小的前导0）。
//
// Output
// 输出为输入中的最大值和最小值，格式见sample。

// Sample Input
// 02
// 010
// 0012
// 012
// 23

// Sample Output
// The maximum value is : 23
// The minimum value is : 2

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

typedef struct {
  int data[MAX_LENGTH];
  int length;
} BigInt;

BigInt *create_bigint() {
  BigInt *bigint = (BigInt *)malloc(sizeof(BigInt));
  bigint->length = 0;
  return bigint;
}

void free_bigint(BigInt *bigint) {
  free(bigint);
}

BigInt *scan_bigint() {
  BigInt *bigint = create_bigint();

  char str[MAX_LENGTH + 1];

  if (scanf("%s", str) == EOF)
    return NULL;

  int has_nonzero = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] != '0' || has_nonzero) {
      bigint->data[bigint->length++] = str[i] - '0';
      has_nonzero = 1;
    }
  }

  return bigint;
}

void print_bigint(const BigInt *bigint) {
  if (bigint->length == 0) {
    printf("0");
  } else {
    for (int i = 0; i < bigint->length; i++) {
      printf("%d", bigint->data[i]);
    }
  }
}

int cmp_bigint(const BigInt *bigint1, const BigInt *bigint2) {
  if (bigint1->length != bigint2->length) {
    return (bigint1->length - bigint2->length) > 0 ? 1 : -1;
  }

  for (int i = 0; i < bigint1->length; i++) {
    if (bigint1->data[i] != bigint2->data[i]) {
      return (bigint1->data[i] - bigint2->data[i]) > 0 ? 1 : -1;
    }
  }

  return 0;
}

void copy_bigint(const BigInt *from, BigInt **to) {
  if (*to != NULL) {
    free_bigint(*to);
  }

  *to = create_bigint();

  (*to)->length = from->length;

  for (int i = 0; i < from->length; i++) {
    (*to)->data[i] = from->data[i];
  }
}

int main() {
  BigInt *max = scan_bigint();
  BigInt *min = create_bigint();

  copy_bigint(max, &min);

  while (1) {
    BigInt *bigint = scan_bigint();

    if (bigint == NULL) {
      free_bigint(bigint);
      break;
    }

    if (cmp_bigint(bigint, max) > 0) {
      copy_bigint(bigint, &max);
    }
    if (cmp_bigint(bigint, min) < 0) {
      copy_bigint(bigint, &min);
    }

    free_bigint(bigint);
  }

  printf("The maximum value is : ");
  print_bigint(max);
  printf("\n");

  printf("The minimum value is : ");
  print_bigint(min);
  printf("\n");

  return 0;
}
