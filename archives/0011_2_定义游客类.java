// 定义游客类(其测试类已给出)，要求如下：
// 一个景区根据游人的年龄收取不同价格的门票。请编写游客类，根据年龄段决定能够购买的门票价格并输出
//
// 当输入的年龄小于18或者大于60（不包括18,60）时，程序输出：
// 年龄为：XX，免费
// 当输入的年龄在18与60之间时，程序输出
// 年龄为：XX，价格为20元

// Sample Input
// 18

// Sample Output
// 年龄为：18，价格为20元

import java.util.Scanner;

class Tourist {
    int age;
    void show() {
        System.out.print("年龄为：" + age + "，");

        if (age < 18 || age > 60) {
            System.out.println("免费");
        } else {
            System.out.println("价格为20元");
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Tourist v = new Tourist();
        v.age = input.nextInt();
        v.show();
        input.close();
    }
}
