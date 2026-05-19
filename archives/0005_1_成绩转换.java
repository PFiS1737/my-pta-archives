// 百分制成绩转换为五级计分制时，90分以上为A，80～89分为B，70～79分为C，60～69分为D，0～59分为E。（建议使用switch语句完成）
//
// 输入格式:
// 测试有多组，每组输入1个整数score。处理到输入结束。
//
// 输出格式:
// 逐行输出百分制成绩score对应的字符等级。若score非法，输出"error!"

// Sample Input
// 1
// 61
// 102

// Sample Output
// E
// D
// error!

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        while (in.hasNextInt()) {
            int n = in.nextInt();
            if (n > 100 || n < 0) {
                System.out.println("error!");
                continue;
            }
            switch (n / 10) {
                case 10:
                case 9:
                    System.out.println("A");
                    break;
                case 8:
                    System.out.println("B");
                    break;
                case 7:
                    System.out.println("C");
                    break;
                case 6:
                    System.out.println("D");
                    break;
                default:
                    System.out.println("E");
            }
        }
        in.close();
    }
}
