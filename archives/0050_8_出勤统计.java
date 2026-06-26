// 某公司现需要统计员工出勤次数，具体要求如下：
//
// 输入样例解释:
// 每行表示某天出勤的员工名单，以空格间隔。
// end表示输入结束
//
// 输出样例解释:
// 按出勤天数倒序输出，若出勤次数相同则按输入顺序输出(即先输入的先输出，样例中Tom比Jack先输入，因此先输出Tom)。每名员工占一行，格式为员工名+空格+出勤次数

// Sample Input
// Mark Tom
// Ivor Mark
// Ivor Mark
// Jack
// end

// Sample Output
// Mark 3
// Ivor 2
// Tom 1
// Jack 1

import java.util.*;
import java.util.stream.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        sc.tokens()
            .takeWhile(s -> !s.equals("end"))
            .collect(
                Collectors.groupingBy(x -> x, LinkedHashMap::new, Collectors.counting()))
            .entrySet()
            .stream()
            .sorted((a, b) -> b.getValue().compareTo(a.getValue()))
            .forEach(e -> System.out.println(e.getKey() + " " + e.getValue()));

        sc.close();
    }
}
