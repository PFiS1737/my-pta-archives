// 输入一个整数n，按规定格式输出数据。
//
// 输入格式:
// 输入一个正整数。
//
// 输出格式:
// 每行输出10个数，相邻数字中间用1个空格作为分隔符。
// 提示：行首无空格，每行的最后一个数字之后不加空格。

// Sample Input
// 15

// Sample Output
// 1 2 3 4 5 6 7 8 9 10
// 11 12 13 14 15

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            System.out.print(i);
            if (i % 10 == 0) {
                System.out.println("");
            } else if (i != n) {
                System.out.print(" ");
            }
        }
        in.close();
    }
}
