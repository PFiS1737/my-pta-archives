// Input
// 输入的第一行为一个整数M(M>0)，后面有M行输入。每行输入为不超过1000个整数的整数序列，每个整数序列的输入均以0结束。
//
// Output
// 对输入的整数序列两两相加：第1行和第2行相加、第3行和第4行相加……按顺序输出结果：每行输出一个整数序列，每两个整数之间用一个空格分隔。若序列数目不为偶数，则视作补一个长度为0的整数序列相加。
//
// 值得注意的是一个长度为0的整数序列也应该有输出，即使没有整数输出，也应该占有一行，因为“每行输出一个整数序列”。

// Sample Input
// 3
// 1 2 3 0
// 10 15 20 30 50 0
// 100 200 300 400 0

// Sample Output
// 11 17 23 30 50
// 100 200 300 400

#include <stdio.h>

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

  while (n--) {
    int len1 = 0, seq1[1000] = {0};

    while (scanf("%d", &seq1[len1++]) && seq1[len1 - 1] != 0) {
    }

    if (n == 0) {
      add(seq1, len1 - 1, NULL, 0);
      break;
    }

    n--;
    int len2 = 0, seq2[1000] = {0};
    while (scanf("%d", &seq2[len2++]) && seq2[len2 - 1] != 0) {
    }

    add(seq1, len1 - 1, seq2, len2 - 1);
  }
}
