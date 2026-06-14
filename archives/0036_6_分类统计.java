// 输入一行英文字符，分别统计出其中英文字母、空格、数字和其它字符的个数。
//
// 输入格式:
// 在一行中输入英文字符，假设该行字符中共有英文字母m个，空格n个，数字k个，其它字符h个
//
// 输出格式:
// 英文字母m空格n数字k其他h

// Sample Input
// It's snowing! It's time to make a snowman.James runs out. He makes a big pile of snow. He puts a big snowball on top. He adds a scarf and a hat. He adds an orange for the nose.

// Sample Output
// 英文字母130空格37数字0其他9

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String s = in.nextLine();

        int m = 0;
        int n = 0;
        int k = 0;
        int h = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (Character.isLetter(c)) {
                m++;
            } else if (c == ' ') {
                n++;
            } else if (Character.isDigit(c)) {
                k++;
            } else {
                h++;
            }
        }

        System.out.println("英文字母" + m + "空格" + n + "数字" + k + "其他" + h);

        in.close();
    }
}
