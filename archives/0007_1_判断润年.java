// 输入1000-5000之间的一个年份，判断并输出该年是否是闰年。
//
// 输入格式:
// 一行中输入整数N，1000<=N<=5000
//
// 输出格式:
// N是润年或者N不是闰年

// Sample Input
// 2020

// Sample Output
// 2020是闰年

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        System.out.println(n + (((n % 4 == 0 && n % 100 != 0) || (n % 400 == 0))
                                    ? "是闰年"
                                    : "不是闰年"));
        in.close();
    }
}
