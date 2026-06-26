// 输入5个整数，对所有整数进行排序，按照升序输出。
//
// 输入格式:
// 输入5个整数。
//
// 输出格式:
// 按照升序输出5个整数。

// Sample Input
// 35
// 22
// 49
// 18
// 32

// Sample Output
// 18
// 22
// 32
// 35
// 49

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[] arr = {
            in.nextInt(),
            in.nextInt(),
            in.nextInt(),
            in.nextInt(),
            in.nextInt(),
        };

        Arrays.sort(arr);

        for (int i : arr) {
            System.out.println(i);
        }

        in.close();
    }
}
