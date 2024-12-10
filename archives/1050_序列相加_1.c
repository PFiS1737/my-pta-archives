// Input
// 输入为多行，直到文件末尾结束。每行第一个整数为N(N<=1000)，后接一个长度为N的整数序列。
//
// Output
// 对输入的整数序列两两相加：第1行和第2行相加、第3行和第4行相加……按顺序输出结果：每行输出一个整数序列，每两个整数之间用一个空格分隔。若序列数目不为偶数，则视作补一个长度为0的整数序列相加。
//
// 值得注意的是一个长度为0的整数序列也应该有输出，即使没有整数输出，也应该占有一行，因为“每行输出一个整数序列”。

// Sample Input
// 3 1 2 3
// 5 10 15 20 30 50
// 0
// 0
// 4 100 200 300 400
// 0

// Sample Output
// 11 17 23 30 50
//
// 100 200 300 400

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *seq;
  int len;
} Sequence;

Sequence *new_sequence(int len) {
  Sequence *seq = (Sequence *)malloc(sizeof(Sequence));

  seq->seq = (int *)malloc(sizeof(int) * len);
  seq->len = len;

  return seq;
}

void free_sequence(Sequence *seq) {
  free(seq->seq);
  free(seq);
}

Sequence *scan_sequence(int len) {
  Sequence *seq = new_sequence(len);

  for (int i = 0; i < len; i++) {
    scanf("%d", &seq->seq[i]);
  }

  return seq;
}

void print_sequence(Sequence *seq) {
  for (int i = 0; i < seq->len; i++) {
    if (i > 0)
      printf(" ");

    printf("%d", seq->seq[i]);
  }

  printf("\n");
}

Sequence *add_sequence(Sequence *seq1, Sequence *seq2) {
  int max_len = seq1->len > seq2->len ? seq1->len : seq2->len;

  Sequence *result = new_sequence(max_len);

  for (int i = 0; i < max_len; i++) {
    int val1 = (i < seq1->len) ? seq1->seq[i] : 0;
    int val2 = (i < seq2->len) ? seq2->seq[i] : 0;

    result->seq[i] = val1 + val2;
  }

  return result;
}

int main() {
  int len1;

  while (scanf("%d", &len1) != EOF) {
    Sequence *seq1 = scan_sequence(len1);

    int len2;
    Sequence *seq2;

    if (scanf("%d", &len2) == EOF) {
      seq2 = new_sequence(0);
    } else {
      seq2 = scan_sequence(len2);
    }

    Sequence *result = add_sequence(seq1, seq2);
    print_sequence(result);

    free_sequence(seq1);
    free_sequence(seq2);
    free_sequence(result);
  }

  return 0;
}
