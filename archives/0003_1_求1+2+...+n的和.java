// 输入一个正整数n（假设 n<=100）,求1+2+...+n的和，并输出相应的运算表达式
//
// 输入格式:
// 一个正整数n
//
// 输出格式:
// 相应的运算表达式

// Sample Input
// 10

// Sample Output
// 1+2+3+4+5+6+7+8+9+10=55

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i;
            System.out.print(i);
            if (i != n) {
                System.out.print("+");
            } else {
                System.out.print("=" + sum);
            }
        }
        in.close();
    }
}
