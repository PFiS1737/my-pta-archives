// 您需要编写一个数组校验程序对控制台输入的数组进行校验，具体要求如下：
//
// 1、若数组中元素按照升序排序，则打印“Array sorted”；
//
// 2、否则打印“Array not sorted”。
//
// 注意：
// 1、控制台输入的第一个元素为数组的长度，即当控制台输入“8 10 1 5 16 61 9 11 1”时，表示数组长度为8，包含的元素分别为“10 1 5 16 61 9 11 1”；
//
// 2、若存在相同元素亦视为升序排列，例如控制台输入4 1 2 2 3，则输出“Array sorted”。
//
// 函数接口定义：
// public static boolean isSorted(int[] list)

// Sample Input
// 8 10 12 15 16 6 19 11 13

// Sample Output
// Array not sorted

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int arrayLen = input.nextInt();
        int[] list = new int[arrayLen];
        for (int i = 0; i < arrayLen; i++)
            list[i] = input.nextInt();
        if (isSorted(list))
            System.out.println("Array sorted");
        else
            System.out.println("Array not sorted");
        input.close();
    }
    public static boolean isSorted(int[] list) {
        for (int i = 0; i < list.length - 1; i++) {
            if (list[i] > list[i + 1])
                return false;
        }
        return true;
    }
}
