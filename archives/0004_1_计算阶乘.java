// 输入一个非负整数n，计算n！。
//
// 输入格式:
// 输入一个非负整数n
//
// 输出格式:
// 输出n！

// Sample Input
// 7

// Sample Output
// 5040

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int pro = 1;
        for (int i = 1; i <= n; i++) {
            pro *= i;
        }
        System.out.println(pro);
        in.close();
    }
}
