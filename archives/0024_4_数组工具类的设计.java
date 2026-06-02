// 本题要求设计一个名为MyArrays的类，根据调用的方式实现相应的方法。
//
// 函数接口定义：
// 请同学根据该类的调用方式和结果，自行设计MyArrays类中的方法，满足应用的需要。

// Sample Input
// 5
// 5 4 6 8 3

// Sample Output
// 5,4,6,8,3
// 3,4,5,6,8
// 26

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int array[] = new int[n];

        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }

        MyArrays.printArray(array);           //显示数组的内容
        MyArrays.sortArray(array);            //对数组元素排序
        MyArrays.printArray(array);           //显示排序后的结果
        int sum = MyArrays.sumOfArray(array); //数组元素求和
        System.out.println(sum);              //显示数组元素的和

        sc.close();
    }
}

class MyArrays {
    static void printArray(int arr[]) {
        if (arr.length == 0) {
            return;
        }

        System.out.print(arr[0]);

        for (int i = 1; i < arr.length; i++) {
            System.out.print("," + arr[i]);
        }

        System.out.println();
    }

    static void sortArray(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    static int sumOfArray(int arr[]) {
        int sum = 0;

        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }

        return sum;
    }
}
