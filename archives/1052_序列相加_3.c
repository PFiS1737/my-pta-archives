// Input
// 输入的第一行为一个整数M(M>0)，后面有M行输入。每行第一个整数为N(N<=1000)，后接一个长度为N的整数序列。
//
// Output
// 对输入的整数序列两两相加：第1行和第2行相加、第2行和第3行相加……按顺序输出结果：每行输出一个整数序列，每两个整数之间用一个空格分隔。若最后序列不足两个，则视作补一个长度为0的整数序列相加。
// 值得注意的是一个长度为0的整数序列也应该有输出，即使没有整数输出，也应该占有一行，因为“每行输出一个整数序列”。

// Sample Input
// 3
// 3 1 2 3
// 5 10 15 20 30 50
// 4 100 200 300 400

// Sample Output
// 11 17 23 30 50
// 110 215 320 430 50
// 100 200 300 400

#include <stdio.h>
#include <stdlib.h>

void add(int *seq1, int len1, int *seq2, int len2) {
  int max_len = len1 > len2 ? len1 : len2;

  for (int i = 0; i < max_len; i++) {
    int val1 = (i < len1) ? seq1[i] : 0;
    int val2 = (i < len2) ? seq2[i] : 0;

    if (i > 0)
      printf(" ");

    printf("%d", val1 + val2);
  }

  printf("\n");
}

int main() {
  int n;
  scanf("%d", &n);

  int len1, seq1[1000] = {0};
  int len2, seq2[1000] = {0};

  scanf("%d", &len1);
  for (int i = 0; i < len1; i++) {
    scanf("%d", &seq1[i]);
  }

  while (n--) {
    if (scanf("%d", &len2) == EOF) {
      add(seq1, len1, NULL, 0);
      break;
    }

    for (int i = 0; i < len2; i++) {
      scanf("%d", &seq2[i]);
    }

    add(seq1, len1, seq2, len2);

    len1 = len2;
    for (int i = 0; i < len2; i++) {
      seq1[i] = seq2[i];
    }
  }

  return 0;
}
