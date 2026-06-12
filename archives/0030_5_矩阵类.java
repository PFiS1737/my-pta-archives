// 利用二维数组（int[]）实现一个矩阵类：Matrix。要求提供以下方法：（1）set（int row, int col, int value）：将第row行第col列的元素赋值为value；（2）get（int row，int col）：取第row行第col列的元素；（3）width()：返回矩阵的列数；（4）height()：返回矩阵的行数；（5）Matrix add（Matrix b）：返回当前矩阵与矩阵b相加后的矩阵；（6）Matrix multiply（Matrix b）：返回当前矩阵与矩阵b相乘后的矩阵。（7）Matrix transpose()：返回当前矩阵的转置矩阵；（8）toString()：以行和列的形式打印出当前矩阵。
//
// 输入格式:
// 矩阵的行列数
// 矩阵的数据
// 设置矩阵值的行、列和值
// 获取矩阵值的行、列
// 待相加矩阵的行列数
// 待相加矩阵的值
// 待相乘矩阵的行列数
// 待相乘矩阵的值
//
// 输出格式:
// 矩阵的行、列数
// 设置矩阵值后的矩阵
// 某行某列的矩阵值
// 矩阵相加结果
// 矩阵相乘结果
// 矩阵转置结果

// Sample Input
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 2 3 8
// 1 3
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9
// 3 2
// 1 2
// 1 2
// 1 2

// Sample Output
// row:3 column:3
// after set value:
// 1 2 3
// 4 5 8
// 7 8 9
// value on (1,3):3
// after add:
// 2 4 6
// 8 10 14
// 14 16 18
// after multiply:
// 6 12
// 17 34
// 24 48
// after transpose:
// 1 4 7
// 2 5 8
// 3 8 9

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int rows = input.nextInt();
        int cols = input.nextInt();

        System.out.printf("row:%d column:%d\n", rows, cols);

        Matrix matrix = new Matrix(rows, cols);
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                matrix.set(i, j, input.nextInt());
            }
        }

        int row = input.nextInt();
        int col = input.nextInt();
        int value = input.nextInt();

        matrix.set(row, col, value);

        System.out.println("after set value:");
        System.out.println(matrix);

        row = input.nextInt();
        col = input.nextInt();

        System.out.printf("value on (%d,%d):%d\n", row, col, matrix.get(row, col));

        rows = input.nextInt();
        cols = input.nextInt();
        Matrix matrix2 = new Matrix(rows, cols);
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                matrix2.set(i, j, input.nextInt());
            }
        }

        Matrix sum = matrix.add(matrix2);
        System.out.println("after add:");
        System.out.println(sum);

        rows = input.nextInt();
        cols = input.nextInt();
        Matrix matrix3 = new Matrix(rows, cols);
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                matrix3.set(i, j, input.nextInt());
            }
        }

        Matrix product = matrix.multiply(matrix3);
        System.out.println("after multiply:");
        System.out.println(product);

        Matrix transpose = matrix.transpose();
        System.out.println("after transpose:");
        System.out.println(transpose);

        input.close();
    }
}

class Matrix {
    // 什么叫“利用二维数组（int[]）实现一个矩阵类” ？？？
    // 到底用一维还是二维？
    int[][] inner;
    int rows, cols;

    Matrix(int rows, int cols) {
        this.rows = rows;
        this.cols = cols;
        inner = new int[rows][cols];
    }

    void set(int row, int col, int value) {
        inner[row - 1][col - 1] = value;
    }
    int get(int row, int col) {
        return inner[row - 1][col - 1];
    }

    int width() {
        return cols;
    }
    int height() {
        return rows;
    }

    Matrix add(Matrix other) {
        if (this.rows != other.rows || this.cols != other.cols) {
            throw new IllegalArgumentException("...");
        }
        Matrix result = new Matrix(this.rows, this.cols);
        for (int i = 1; i <= this.rows; i++) {
            for (int j = 1; j <= this.cols; j++) {
                result.set(i, j, this.get(i, j) + other.get(i, j));
            }
        }
        return result;
    }

    Matrix multiply(Matrix other) {
        if (this.cols != other.rows) {
            throw new IllegalArgumentException("...");
        }
        Matrix result = new Matrix(this.rows, other.cols);
        for (int i = 1; i <= this.rows; i++) {
            for (int j = 1; j <= other.cols; j++) {
                int sum = 0;
                for (int k = 1; k <= this.cols; k++) {
                    sum += this.get(i, k) * other.get(k, j);
                }
                result.set(i, j, sum);
            }
        }
        return result;
    }

    Matrix transpose() {
        Matrix result = new Matrix(this.cols, this.rows);
        for (int i = 1; i <= this.rows; i++) {
            for (int j = 1; j <= this.cols; j++) {
                result.set(j, i, this.get(i, j));
            }
        }
        return result;
    }

    @Override
    public String toString() {
        String result = "";
        for (int i = 1; i <= this.rows; i++) {
            for (int j = 1; j <= this.cols; j++) {
                result += this.get(i, j) + " ";
            }
            result = result.trim();
            result += "\n";
        }
        result = result.trim();
        return result;
    }
}
