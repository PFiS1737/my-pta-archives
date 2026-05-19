// 注意:这是在不使用数组的情况下完成的。
// RDMP音乐播放器将存储5首歌曲，它们的名称将永远是“A”，“B”，“C”，“D”和“E”。RDMP有3个按钮，用户可以按下这些按钮来重新排列播放列表并播放歌曲。
// 最初，RDMP播放列表是“A, B, C, D, E”。3个控制按钮做以下工作:
// •按钮1:将播放列表的第一首歌曲移动到播放列表的末尾。例如:“A, B, C, D, E”会变成“B, C, D, E, A”。
// •按钮2:将播放列表的最后一首歌移动到播放列表的开始。例如，“A, B, C, D, E”会变成“E, A, B, C, D”。
// •按钮3:交换播放列表的前两首歌。例如，“A, B, C, D, E”会变成“B, A, C, D, E”。1.
// 你需要编写一个程序来模拟一个可以按下5次按钮的RD音乐播放器。
//
// 输入格式:
// 输入1到3之间的5个数字，代表要采取的行动。
//
// 输出格式:
// 输出播放列表的正确顺序。
// 歌曲名称中间用逗号作分隔，最后一首歌名称之后没有逗号。

// Sample Input
// 3
// 3
// 1
// 2
// 1

// Sample Output
// B,C,D,E,A

import java.util.Scanner;

public class Main {
    public static void main() {
        Scanner in = new Scanner(System.in);
        char c1 = 'A', c2 = 'B', c3 = 'C', c4 = 'D', c5 = 'E';
        int n = 5;
        while (n-- != 0) {
            int x = in.nextInt();
            switch (x) {
                case 1: {
                    char tmp = c1;
                    c1 = c2;
                    c2 = c3;
                    c3 = c4;
                    c4 = c5;
                    c5 = tmp;
                    break;
                }
                case 2: {
                    char tmp = c5;
                    c5 = c4;
                    c4 = c3;
                    c3 = c2;
                    c2 = c1;
                    c1 = tmp;
                    break;
                }
                case 3: {
                    char tmp = c1;
                    c1 = c2;
                    c2 = tmp;
                    break;
                }
            }
        }
        System.out.printf("%c,%c,%c,%c,%c", c1, c2, c3, c4, c5);
        in.close();
    }
}
