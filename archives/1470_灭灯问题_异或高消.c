// Description
// 给你一个5*6的矩阵，矩阵里每一个单元都有一个灯和一个开关，如果按下此开关，那么开关所在位置的那个灯和开关前后左右的灯的状态都会改变 (即由亮到不亮或由不亮到亮)。给你一个初始的灯的状态，问怎样控制每一个开关使得所有的灯最后全部熄灭。
//
// Input
// 输入第一行整数N，代表有N组测试用例，每一组测试用例是一个5*6的矩阵，在5*6的矩阵里，0代表灯关闭，1代表灯开着。
//
// Output
// 对于每一组数据，输出第一行包括字符串："PUZZLE #m"，m是代表的是第m组数据，接着输出一个包含0,1的5*6的矩阵，（ij）处的0代表（i，j）处的开关没有按下，（ij）处的1代表（i，j）处的开关按下。

// Sample Input
// 2
// 0 1 1 0 1 0
// 1 0 0 1 1 1
// 0 0 1 0 0 1
// 1 0 0 1 0 1
// 0 1 1 1 0 0
//
// 0 0 1 0 1 0
// 1 0 1 0 1 1
// 0 0 1 0 1 1
// 1 0 1 1 0 0
// 0 1 0 1 0 0

// Sample Output
// PUZZLE #1
// 1 0 1 0 0 1
// 1 1 0 1 0 1
// 0 0 1 0 1 1
// 1 0 0 1 0 0
// 0 1 0 0 0 0
// PUZZLE #2
// 1 0 0 1 1 1
// 1 1 0 0 0 0
// 0 0 0 1 0 0
// 1 1 0 1 0 1
// 1 0 1 1 0 1

// HINT
// 找出每个灯和开关之间的关系，列出方程组求解。

#include <stdio.h>

#define ROW 5
#define COL 6
#define SIZE 30

void gauss(int matrix[SIZE][SIZE + 1]) {
  int m = SIZE, n = SIZE + 1;
  int i = 0, j = 0;

  while (i < m && j < n) {
    int i_max = i;
    for (int k = i; k < m; k++) {
      if (matrix[k][j] > matrix[i_max][j]) {
        i_max = k;
      }
    }

    if (matrix[i_max][j]) {
      if (i_max != i) {
        for (int k = 0; k < n; k++) {
          double temp = matrix[i][k];
          matrix[i][k] = matrix[i_max][k];
          matrix[i_max][k] = temp;
        }
      }

      for (int k = 0; k < m; k++) {
        if (k != i && matrix[k][j]) {
          for (int l = j; l < n; l++) {
            matrix[k][l] ^= matrix[i][l];
          }
        }
      }

      i++;
    }

    j++;
  }
}

int main() {
  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {
    int b[ROW][COL];

    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        scanf("%d", &b[i][j]);
      }
    }

    int A[SIZE][SIZE + 1];
    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE + 1; j++) {
        A[i][j] = 0;
      }
    }
    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        int index = i * COL + j;

        A[index][index] = 1;
        if (i > 0)
          A[index][index - COL] = 1;
        if (i < ROW - 1)
          A[index][index + COL] = 1;
        if (j > 0)
          A[index][index - 1] = 1;
        if (j < COL - 1)
          A[index][index + 1] = 1;

        A[index][SIZE] = b[i][j];
      }
    }

    gauss(A);

    printf("PUZZLE #%d\n", t);
    for (int i = 0; i < ROW; i++) {
      for (int j = 0; j < COL; j++) {
        if (j > 0) {
          printf(" ");
        }
        printf("%d", A[i * COL + j][SIZE]);
      }
      printf("\n");
    }
  }

  return 0;
}
