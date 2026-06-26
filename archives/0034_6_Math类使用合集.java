// 使用Java中Math类完成以下内容：
// 1、使用n1生成2-23之间的随机数，并通过程序测试（测试程序已给出，无需编写）；
// 2、接收控制台输入的n2,n3,计算  的值并赋值给n4（四舍五入保留整数位）；

// Sample Input
// 21 2

// Sample Output
// random
// 5.0

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        double n1 = Math.random();
        int n2 = in.nextInt();
        int n3 = in.nextInt();
        double n4 = 0;

        n1 = (int)(n1 * 22) + 2;
        n4 = Math.round(Math.sqrt(n2) + Math.log(n3));

        //判断随机数n1是否为整数并且是2-23之间的数
        if (n1 == (int)n1 && n1 >= 2 && n1 <= 23) {
            System.out.println("random");
        }
        System.out.println(n4);
        in.close();
    }
}
