// A同学晚上睡不着的时候不喜欢玩手机，也不喜欢打游戏，他喜欢数星星。
//
// 输入N个（X，Y）代表Ｎ颗星星。在2个点——左下点B（x,y）和右上点T(x,y)代表矩形中，问有多少颗星星在窗子内部，在窗边上的不计。
//
// 输入：
//
// 多组输入。
//
// 每组先输入一个整数N(N <= 10000)，接着输入两个点代表矩形的左下点B（x,y）和右上点T(x,y)，然后输入N个（X，Y）代表Ｎ颗星星。问有多少颗星星在窗子内部，在窗边上的不计。
//
// 输出：
//
//  输出一个整数，代表有多少颗星星在窗子内部。

// Sample Input
// 3
// 0 1
// 3 4
// 1 1
// 2 2
// 3 3

// Sample Output
// 1

import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        int n, x, y;
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            n = sc.nextInt(); //待考察的点数
            int count = 0;    //计数器
            Rect rect = new Rect(
                sc.nextInt(), sc.nextInt(), sc.nextInt(),
                sc.nextInt()
            );                          //构建矩形对象
            for (int i = 0; i < n; i++) //判断n个点是否在矩形对象rect中
            {
                x = sc.nextInt();                     //读入待考察点的x坐标
                y = sc.nextInt();                     //读入待考察点的y坐标
                boolean inRect = rect.isInRect(x, y); //判断点(x,y)是否在矩形中
                if (inRect)                           //是，计数器加1
                {
                    count++;
                }
            }
            System.out.println(count); //打印N个点在矩形对象中的点的个数
        }
        sc.close();
    }
}

class Rect {
    int x1, y1, x2, y2; //4个属性,分别表示左下角和右上角的x、y坐标

    //构造方法
    public Rect(int x1, int y1, int x2, int y2) {
        this.x1 = x1;
        this.y1 = y1;
        this.x2 = x2;
        this.y2 = y2;
    }
    //判断点（x,y)是否在本矩形对象内部，在窗边的不计
    public boolean isInRect(int x, int y) {
        return x > x1 && x < x2 && y > y1 && y < y2;
    }
}
