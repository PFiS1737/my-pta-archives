// Description
// 求两个矩阵A、B的乘积C=AB。根据矩阵乘法的定义，只有A的列数和B的行数相同才能相乘。可以确保所有运算结果都在int类型的范围之内。
//
// Input
// 输入数据为多个矩阵（最少2个），每个矩阵以两个正整数m和n开始，满足0<m,n<=100，接下来为一个m行n列的矩阵A。当输入的m和n均为0时，表示输入数据结束。
//
// Output
// 对输入的矩阵两两相乘：第1个和第2个相乘、第1个和第2个相乘的结果和第3个相乘……按顺序输出矩阵相乘的结果：每行两个元素之间用一个空格分开，每行最后一个元素之后为一个换行，在下一行开始输出矩阵的下一行。
//
// 若前k个矩阵相乘的结果和第k+1个矩阵无法相乘（即不满足矩阵乘法定义），则输出“Not satisfied the definition of matrix multiplication!”。然后用第k+1个矩阵去和第k+2个矩阵相乘。最后一个矩阵只做乘数。
//
// 每两组输出之间用一个空行分隔开。

// Sample Input
// 2 3
// 1 1 1
// 1 1 1
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3 1
// 0
// 0
// 0
// 0 0

// Sample Output
// 12 15 18
// 12 15 18
//
// 0
// 0

// HINT
// 矩阵的乘法就是一行乘以一列加起来做一个元素。

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int **data;
  int rows;
  int cols;
} Matrix;

Matrix *new_matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    fprintf(stderr, "Error: Invalid matrix dimensions (%d, %d).\n", rows, cols);
    exit(EXIT_FAILURE);
  }

  Matrix *matrix = (Matrix *)malloc(sizeof(Matrix));
  if (matrix == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for matrix structure.\n");
    exit(EXIT_FAILURE);
  }

  matrix->rows = rows;
  matrix->cols = cols;

  matrix->data = (int **)malloc(rows * sizeof(int *));
  if (matrix->data == NULL) {
    fprintf(stderr, "Error: Failed to allocate memory for matrix rows.\n");
    free(matrix);
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < rows; i++) {
    matrix->data[i] = (int *)malloc(cols * sizeof(int));
    if (matrix->data[i] == NULL) {
      fprintf(stderr, "Error: Failed to allocate memory for matrix row %d.\n", i);
      for (int j = 0; j < i; j++) {
        free(matrix->data[j]);
      }
      free(matrix->data);
      free(matrix);
      exit(EXIT_FAILURE);
    }
  }

  return matrix;
}

void free_matrix(Matrix *matrix) {
  if (matrix == NULL)
    return;

  for (int i = 0; i < matrix->rows; i++) {
    free(matrix->data[i]);
  }

  free(matrix->data);
  free(matrix);
}

Matrix *scan_matrix(int rows, int cols) {
  Matrix *matrix = new_matrix(rows, cols);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (scanf("%d", &matrix->data[i][j]) != 1) {
        fprintf(stderr, "Error: Invalid input for matrix element (%d, %d).\n", i, j);
        free_matrix(matrix);
        exit(EXIT_FAILURE);
      }
    }
  }

  return matrix;
}

void print_matrix(const Matrix *matrix) {
  if (matrix == NULL) {
    fprintf(stderr, "Error: Attempted to print a NULL matrix.\n");
    return;
  }

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->cols; j++) {
      printf("%d", matrix->data[i][j]);
      if (j < matrix->cols - 1) {
        printf(" ");
      } else {
        printf("\n");
      }
    }
  }
}

Matrix *mul_matrix(const Matrix *lhs, const Matrix *rhs) {
  if (lhs == NULL || rhs == NULL) {
    fprintf(stderr, "Error: NULL matrix provided for multiplication.\n");
    return NULL;
  }

  if (lhs->cols != rhs->rows) {
    fprintf(stderr,
            "Error: Matrix dimensions (%d x %d) and (%d x %d) are incompatible for "
            "multiplication.\n",
            lhs->rows, lhs->cols, rhs->rows, rhs->cols);
    return NULL;
  }

  Matrix *result = new_matrix(lhs->rows, rhs->cols);

  for (int i = 0; i < lhs->rows; i++) {
    for (int j = 0; j < rhs->cols; j++) {
      result->data[i][j] = 0;
      for (int k = 0; k < lhs->cols; k++) {
        result->data[i][j] += lhs->data[i][k] * rhs->data[k][j];
      }
    }
  }

  return result;
}

void copy_matrix(const Matrix *from, Matrix **to) {
  if (from == NULL) {
    fprintf(stderr, "Error: Cannot clone from a NULL matrix.\n");
    return;
  }

  if (*to != NULL) {
    free_matrix(*to);
  }

  *to = new_matrix(from->rows, from->cols);

  for (int i = 0; i < from->rows; i++) {
    for (int j = 0; j < from->cols; j++) {
      (*to)->data[i][j] = from->data[i][j];
    }
  }
}

int main() {
  int lhs_rows, lhs_cols;
  scanf("%d %d", &lhs_rows, &lhs_cols);

  Matrix *lhs_matrix = scan_matrix(lhs_rows, lhs_cols);

  int rhs_rows, rhs_cols;
  while (scanf("%d %d", &rhs_rows, &rhs_cols) == 2) {
    if (rhs_rows == 0 && rhs_cols == 0) {
      break;
    }

    Matrix *rhs_matrix = scan_matrix(rhs_rows, rhs_cols);

    Matrix *result = mul_matrix(lhs_matrix, rhs_matrix);

    if (result == NULL) {
      printf("Not satisfied the definition of matrix multiplication!\n");
      copy_matrix(rhs_matrix, &lhs_matrix);
    } else {
      print_matrix(result);
      copy_matrix(result, &lhs_matrix);
      free_matrix(result);
    }

    printf("\n");
    free_matrix(rhs_matrix);
  }

  free_matrix(lhs_matrix);

  return EXIT_SUCCESS;
}
