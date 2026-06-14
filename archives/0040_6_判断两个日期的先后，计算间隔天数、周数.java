// 从键盘输入两个日期，格式如：2022-06-18。判断两个日期的先后，并输出它们之间间隔的天数、周数（不足一周按0计算）。
//
// 预备知识：通过查询Java API文档，了解Scanner类中nextLine()等方法、String类中split()等方法、Integer类中parseInt()等方法的用法，了解LocalDate类中of()、isAfter()、isBefore()、until()等方法的使用规则，了解ChronoUnit类中DAYS、WEEKS、MONTHS等单位的用法。
//
// 输入格式:
// 输入两行，每行输入一个日期，日期格式如：2022-06-18
//
// 输出格式:
// 第一行输出：第一个日期比第二个日期更早（晚）
// 第二行输出：两个日期间隔XX天
// 第三行输出：两个日期间隔XX周

// Sample Input
// 2000-02-18
// 2000-3-15

// Sample Output
// 第一个日期比第二个日期更早
// 两个日期间隔26天
// 两个日期间隔3周

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[] date1 =
            Arrays.stream(in.nextLine().split("-")).mapToInt(Integer::parseInt).toArray();
        int[] date2 =
            Arrays.stream(in.nextLine().split("-")).mapToInt(Integer::parseInt).toArray();

        LocalDate d1 = LocalDate.of(date1[0], date1[1], date1[2]);
        LocalDate d2 = LocalDate.of(date2[0], date2[1], date2[2]);

        if (d1.isBefore(d2)) {
            System.out.println("第一个日期比第二个日期更早");
        } else if (d1.isAfter(d2)) {
            System.out.println("第一个日期比第二个日期更晚");
        }

        long days = Math.abs(ChronoUnit.DAYS.between(d1, d2));
        long weeks = days / 7;

        System.out.println("两个日期间隔" + days + "天");
        System.out.println("两个日期间隔" + weeks + "周");

        in.close();
    }
}
