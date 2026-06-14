// 作为一个职业HR，要给某个项目组的所有职员群发邮件，已经知道HR有所有人的姓名、电话以及邮箱，请编写程序，取出所有人的邮箱，合并为一个邮箱列表，邮箱之间以“；”隔开，使其可以群发邮件。
//
// 输入格式:
// 在一行中给出所有人的姓名、电话以及邮箱，例如：丽丽/13539870198/lili@qq.com,天梯/13408791122/tiant@qq.com
//
// 输出格式:
// 一行中邮箱列表，以分号隔开。

// Sample Input
// 丽丽/13539870198/lili@qq.com,天梯/13408791122/tiant@qq.com,楠楠/13112034567/nn@qq.com

// Sample Output
// lili@qq.com;tiant@qq.com;nn@qq.com;

import java.util.Scanner;
import java.util.regex.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();

        Pattern pattern = Pattern.compile("/([^/,]+@[^/,]+)");
        Matcher matcher = pattern.matcher(s);

        while (matcher.find()) {
            System.out.print(matcher.group(1) + ";");
        }

        in.close();
    }
}
