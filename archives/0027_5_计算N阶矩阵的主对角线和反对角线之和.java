// 下列给定程序中，函数fun的功能是：计算N×N矩阵的主对角线元素和反向对角线元
// 素之和，并作为函数值返回。要求先累加主对角线元素中的值，再累加反向对角线
// 元素中的值。
//
// 例如：若N＝3，有下列矩阵：
//
//                          1　　2　　3
//                          4　　5　　6
//                          7　　8　　9
//   首先累加1、5、9，然后累加3、5、7，函数返回值为30。

// Sample Input

// Sample Output
// The original data:
//   21   2  13  24
//   25  16  47  38
//   29  11  32  54
//   42  21   3  10
// The result is:203

public class Main {
    public static void main(String[] args) {
        int t[][] = {
            {21, 2, 13, 24}, {25, 16, 47, 38}, {29, 11, 32, 54}, {42, 21, 3, 10}};
        System.out.println("The original data:");
        for (int i = 0; i < t.length; i++) {
            for (int j = 0; j < t[i].length; j++)
                System.out.printf("%4d", t[i][j]);
            System.out.println();
        }
        System.out.println("The result is:" + fun(t));
    }
    public static int fun(int t[][]) {
        int sum;
        sum = 0;
        for (int i = 0; i < t.length; i++)
            sum += t[i][i];
        for (int i = 0; i < t.length; i++)
            sum += t[i][t.length - i - 1];
        return sum;
    }
}
