// 已知数组存放一批QQ号码，QQ号码最长为11位，最短为5位：
// String[] strs = {"12345","67891","12347809933","98765432102","67891","12347809933"}。
// 将该数组里面的所有QQ号都存放在LinkedList中，然后遍历链表，将list中第一个指定长度的QQ号查找出来；如果不存在指定长度的QQ号，则输出“not exist”。
//
// Main类：在main方法中，调用constructList方法将strs中的字符串存入一个String的链表中，然后调用search方法查找第一个指定长度的QQ号码，并打印到屏幕。
//
// 编写StringList类，编程要求如下：
//
// 根据程序需求，定义成员变量、编写构造方法。
// LinkedList constructList(String[] strs) 方法：将String数组strs中的元素添加到链表中，构建一个String对象链表，最后返回链表。
// String search(LinkedList list)方法：使用scanner的nextInt()方法从键盘读入一个int，表示指定长度，然后遍历链表，查找出链表中第一个指定长度的QQ号码并返回；如果不存在指定长度的QQ号，则返回字符串"not exist"。

// Sample Input
// 5

// Sample Output
// 12345

import java.util.*;

public class Main {
    public static void main(String[] args) {
        String[] strs = {"12345",       "67891", "12347809931",
                         "98765432102", "67891", "12347809933"};
        StringList sl = new StringList();
        LinkedList<String> qqList = sl.constructList(strs);
        System.out.println(sl.search(qqList));
    }
}

class StringList {
    LinkedList<String> constructList(String[] strs) {
        return new LinkedList<>(Arrays.asList(strs));
    }

    String search(LinkedList<String> qqList) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.close();
        return qqList.stream()
            .filter(s -> s.length() == n)
            .findFirst()
            .orElse("not exist");
    }
}
