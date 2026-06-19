// 约瑟夫环是一个数学的应用问题：已知n个人（以编号a，b，c...分别表示）围坐在一张圆桌周围。从编号为1的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。
//
// 输入格式:
// 固定为2行，第一行为m，第二行为n个人的名称列表，用英文字母代表，元素直接使用英文逗号 ， 分开
//
// 输出格式:
// 一行，为出列元素序列，元素之间使用英文逗号 ， 分开【注意：末尾元素后没有逗号】

// Sample Input
// 3
// a,b,c,d,e,f,g

// Sample Output
// c,f,b,g,e,a,d

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt() - 1;
        ArrayList<String> arr = new ArrayList<>(Arrays.asList(sc.next().split(",")));

        ArrayList<String> out = new ArrayList<>();

        int pos = 0;
        while (arr.size() > 0) {
            pos = (pos + m) % arr.size();
            out.add(arr.remove(pos));
        }

        System.out.println(String.join(",", out));

        sc.close();
    }
}
