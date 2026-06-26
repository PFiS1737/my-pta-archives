// 3个整数数组进行整体排序，根据输入的三个数组的元素，输出排序后的结果（从大到小）
//
// 输入格式:
// 第1个数组的长度
//
// 第1个数组的各个元素
//
// 第2个数组的长度
//
// 第2个数组的各个元素
//
// 第3个数组的长度
//
// 第3个数组的各个元素
//
// 输出格式:
// 所有数组的整体排序

// Sample Input
// 3
// 79 80 61
// 3
// 88 66 77
// 2
// 23 90

// Sample Output
// 90 88 80 79 77 66 61 23

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        ArrayList<Integer> arr = new ArrayList<Integer>();

        int len = in.nextInt();
        while (len-- > 0) {
            int n = in.nextInt();
            arr.add(n);
        }

        len = in.nextInt();
        while (len-- > 0) {
            int n = in.nextInt();
            arr.add(n);
        }

        len = in.nextInt();
        while (len-- > 0) {
            int n = in.nextInt();
            arr.add(n);
        }

        arr.sort((a, b) -> { return b - a; });

        for (int i = 0; i < arr.size(); i++) {
            System.out.print(arr.get(i));
            if (i != arr.size() - 1) {
                System.out.print(" ");
            } else {
                System.out.println();
            }
        }

        in.close();
    }
}
