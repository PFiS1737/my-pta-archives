// 定义一个日期类Date，含有数据成员：年、月、日，3个成员方法：构造方法用于初始化数据成员、计算天数方法、判断闰年方法。编程：创建日期对象，计算并输出该日是该年的第几天。
//
// 输入格式:
// 每组测试数据仅包含一个测试用例，每个测试用例占一行包括三个数，分别表示年、月、日。
//
// 输出格式:
// 该日是该年的第几天。

// Sample Input
// 2022 4 3

// Sample Output
// 93

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Date date = new Date(in.nextInt(), in.nextInt(), in.nextInt());
        System.out.println(date.dayOfYear());
        in.close();
    }
}

class Date {
    int y, m, d;

    Date(int y, int m, int d) {
        this.y = y;
        this.m = m;
        this.d = d;
    }

    boolean isLeapYear() {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    int dayOfYear() {
        int[] month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        if (isLeapYear())
            month[2]++;

        int sum = 0;
        for (int i = 1; i <= m - 1; i++)
            sum += month[i];

        return sum + d;
    }
}
