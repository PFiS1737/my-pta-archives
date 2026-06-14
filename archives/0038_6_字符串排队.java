// 从键盘上输入若干个英文单词，请按照字典顺序将这些单词输出。
//
// 输入格式:
// 在一行中输入不超过20个英文单词，用空格分开。
//
// 输出格式:
// 在一行中输出前面输入的英文单词，按照字典序顺序输出，用空格作为分割符。

// Sample Input
// I am a student

// Sample Output
// I a am student

import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String[] words = in.nextLine().split("\\s");

        Arrays.sort(words);

        System.out.println(String.join(" ", words));

        in.close();
    }
}
