// Input
// 输入的第一个为整数M，接下来有M个测试数据，即M个方程组。每组测试数据首先输入一个整数n（n<=50），表示该方程组有n个未知数，接下来是一个n阶的系数矩阵。
//
// Output
// 对于每一组数据，输出n个未知数的解。每两组测试数据之间输出一个空行。
//
// 请注意未知数的下标和输出顺序与输入的对应关系。

// Sample Input
// 2
// 4
// 11 1 5 -4 13
// -2 8 2 3 11
// 3 -2 10 4 15
// 1 3 -2 17 19
// 3
// 2 1 1 28
// 5 2 2 66
// 10 5 4 137

// Sample Output
// x1=1.000
// x2=1.000
// x3=1.000
// x4=1.000
//
// x1=10.000
// x2=5.000
// x3=3.000

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 50
#define EPSILON 1e-6

int fcmp(double a, double b) {
  if (fabs(a - b) < EPSILON) {
    return 0;
  }

  return a < b ? -1 : 1;
}

double *solve(double matrix[MAX_N][MAX_N + 1], int m, int n) {
  int i = 0, j = 0;

  while (i < m && j < n) {
    // 找主元
    int i_max = i;
    for (int k = i; k < m; k++) {
      if (fcmp(fabs(matrix[k][j]), fabs(matrix[i_max][j])) > 0) {
        i_max = k;
      }
    }

    // 已知有解， 不考虑主元为0的情况

    // 行交换：将包含最大值的行移动到主元位置
    if (i_max != i) {
      for (int k = 0; k < n; k++) {
        double temp = matrix[i][k];
        matrix[i][k] = matrix[i_max][k];
        matrix[i_max][k] = temp;
      }
    }

    // 消元
    for (int k = i + 1; k < m; k++) {
      double factor = matrix[k][i] / matrix[i][i];
      for (int g = 0; g < n; g++) {
        matrix[k][g] -= factor * matrix[i][g];
      }
    }

    i++;
    j++;
  }

  // 向上消元
  for (int i = m - 1; i >= 0; i--) {
    // 由于已知有解，此处不再找主元，而是直接使用目标位置的元素
    matrix[i][n - 1] /= matrix[i][i];
    for (int k = 0; k < i; k++) {
      matrix[k][n - 1] -= matrix[k][i] * matrix[i][n - 1];
    }
  }

  double *solution = (double *)malloc(m * sizeof(double));
  for (int i = 0; i < m; i++) {
    solution[i] = matrix[i][n - 1];
  }
  return solution;
}

int main() {
  int m;
  scanf("%d", &m);

  for (int t = 0; t < m; t++) {
    if (t > 0) {
      printf("\n");
    }

    int n;
    scanf("%d", &n);

    double matrix[MAX_N][MAX_N + 1];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= n; j++) {
        scanf("%lf", &matrix[i][j]);
      }
    }

    double *solution = solve(matrix, n, n + 1);

    for (int i = 0; i < n; i++) {
      printf("x%d=%.3lf\n", i + 1, solution[i]);
    }
  }

  return 0;
}
