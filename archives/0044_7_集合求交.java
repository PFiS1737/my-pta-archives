// 从键盘录入1行包含6个整数（整数可以重复）的字符串，前3个整数和后3个整数分别构成2个集合。编写程序，输出这两个集合的交集中的元素个数。
//
// 输入格式:
// 键盘录入的1行包含6个整数（整数可以重复）的字符串
//
// 输出格式:
// 前3个整数和后3个整数构成的2个集合的交集中的元素个数

// Sample Input
// 12 14 22 12 16 22

// Sample Output
// 2

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Set<Integer> s1 =
            new HashSet<>(List.of(sc.nextInt(), sc.nextInt(), sc.nextInt()));
        Set<Integer> s2 =
            new HashSet<>(List.of(sc.nextInt(), sc.nextInt(), sc.nextInt()));

        s1.retainAll(s2);

        System.out.println(s1.size());

        sc.close();
    }
}
