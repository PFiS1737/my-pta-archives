// 求两个整数之和。从键盘输入2个整数，然后它们的和，按规定格式输出。
//
// 输入格式:
// 从键盘输入2个正整数A和B，中间有1个空格。
//
// 输出格式:
// 计算它们的和，按如下形式输出：A+B=C。

// Sample Input
// 1 2

// Sample Output
// 1+2=3

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        int b = in.nextInt();
        System.out.println(a + "+" + b + "=" + (a + b));
        in.close();
    }
}
