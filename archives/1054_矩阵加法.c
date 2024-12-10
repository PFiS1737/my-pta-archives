// Description
// 求两个矩阵A、B的和。根据矩阵加法的定义，只有同阶的矩阵才能相加。可以确保所有运算结果都在int类型的范围之内。
//
// Input
// 输入数据为多个矩阵，每个矩阵以两个正整数m和n开始，满足0<m,n<=100，接下来为一个m行n列的矩阵A。当输入的m和n均为0时，表示输入数据结束
//
// Output
// 对输入的矩阵两两相加：第1个和第2个相加、第3个和第4个相加……按顺序输出矩阵相加的结果：每行两个元素之间用一个空格分开，每行最后一个元素之后为一个换行，在下一行开始输出矩阵的下一行。
//
// 若输入的矩阵不为偶数个，最后剩余的矩阵不产生任何输出。
//
// 不满足矩阵加法定义的数据输出“Not satisfied the definition of matrix addition!”
//
// 每两组输出之间用一个空行分隔开。

// Sample Input
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3 3
// 9 8 7
// 6 5 4
// 3 2 1
// 3 3
// 1 1 1
// 1 1 1
// 1 1 1
// 2 2
// 2 2
// 2 2
// 1 1
// 0
// 0 0

// Sample Output
// 10 10 10
// 10 10 10
// 10 10 10
//
// Not satisfied the definition of matrix addition!

// HINT
// 矩阵的加法就是对应位置上的元素相加。

#include <stdio.h>

void add(int a[101][101], int a_row, int a_col, int b[101][101], int b_row, int b_col) {
  if (a_row != b_row || a_col != b_col) {
    printf("Not satisfied the definition of matrix addition!\n\n");
    return;
  }

  int matrix[a_row][a_col];
  for (int i = 0; i < a_row; i++) {
    for (int j = 0; j < a_col; j++) {
      matrix[i][j] = a[i][j] + b[i][j];
    }
  }

  for (int i = 0; i < a_row; i++) {
    for (int j = 0; j < a_col; j++) {
      printf("%d", matrix[i][j]);
      if (j < a_col - 1) {
        printf(" ");
      } else {
        if (i == a_row - 1)
          printf("\n");
        printf("\n");
      }
    }
  }
}

int main() {
  int row1, col1;
  while (scanf("%d %d", &row1, &col1)) {
    if (row1 == 0 && col1 == 0)
      break;

    int a[101][101];
    for (int i = 0; i < row1; i++) {
      for (int j = 0; j < col1; j++) {
        scanf("%d", &a[i][j]);
      }
    }

    int row2, col2;
    scanf("%d %d", &row2, &col2);
    if (row2 == 0 && col2 == 0) {
      printf("\n");
      break;
    }

    int b[101][101];
    for (int i = 0; i < row2; i++) {
      for (int j = 0; j < col2; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    add(a, row1, col1, b, row2, col2);
  }

  return 0;
}
