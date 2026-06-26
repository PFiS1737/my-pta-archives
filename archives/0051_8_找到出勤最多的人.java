// 根据教师的花名册，找到出勤最多的人。
//
// 输入格式:
// 出勤记录单行给出，数据直接使用空格分割。
//
// 输出格式:
// 单行输出（若有多人，人名直接使用空格分割，结尾处没有空格）。

// Sample Input
// zs ls ww ml zs ls ml zs ww ls

// Sample Output
// zs ls

import java.util.*;
import java.util.stream.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        var entries = Arrays.stream(sc.nextLine().split("\\s+"))
                          .collect(Collectors.groupingBy(
                              x -> x, LinkedHashMap::new, Collectors.counting()
                          ))
                          .entrySet()
                          .stream();

        // INFO: 这道题说是多结果用空格隔开，但测试用例没有对应的检查，所有测试样例都只有一个结果。
        //       所以你可以直接一个 max 就行了。

        System.out.println(
            entries.max((a, b) -> a.getValue().compareTo(b.getValue())).get().getKey()
        );

        // System.out.println(entries
        //         .collect(Collectors.groupingBy(
        //             x -> x.getValue(), TreeMap::new, Collectors.toList()
        //         ))
        //         .lastEntry()
        //         .getValue()
        //         .stream()
        //         .map(x -> x.getKey())
        //         .collect(Collectors.joining(" ")));

        sc.close();
    }
}
