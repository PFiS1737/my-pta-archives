// 编写以下两个函数
//
// //以空格(单个或多个)为分隔符，将line中的元素抽取出来，放入一个List
// public static List<String> convertStringToList(String line)
// //在list中移除掉与str内容相同的元素
// public static void remove(List<String> list, String str)

// Sample Input
// 1 2 1 2 1 1 1 2
// 1
// 11 1 11 1 11
// 11
// 2 2 2
// 1
// 1   2 3 4 1 3 1
// 1

// Sample Output
// [1, 2, 1, 2, 1, 1, 1, 2]
// [2, 2, 2]
// [11, 1, 11, 1, 11]
// [1, 1]
// [2, 2, 2]
// [2, 2, 2]
// [1, 2, 3, 4, 1, 3, 1]
// [2, 3, 4, 3]

import java.util.*;

public class Main {
    //以空格(单个或多个)为分隔符，将line中的元素抽取出来，放入一个List
    public static List<String> convertStringToList(String line) {
        return new ArrayList<String>(Arrays.asList(line.split("\\s+")));
    }
    //在list中移除掉与str内容相同的元素
    public static void remove(List<String> list, String str) {
        list.removeIf(s -> s.equals(str));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNextLine()) {
            List<String> list = convertStringToList(sc.nextLine());
            System.out.println(list);
            String word = sc.nextLine();
            remove(list, word);
            System.out.println(list);
        }
        sc.close();
    }
}
