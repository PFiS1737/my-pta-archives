// 编写一个分数类Fraction，该类包含两个int型参数表示分子与分母。
//
// 同时，该类包含如下方法：
//
// （1）Fraction plus(Fraction r)
// 表示将自己的分数和r的分数相加，产生一个新的Fraction的对象。
//
// （2）void print()
// 表示将其按照“分子/分母”的形式输出。注意：
// a、若分子分母不相同，则需要化简后输出。例如，2/4应该被化简为1/2再输出；
// b、若分子分母相同，则输出1，例如结果为4/4，则输出1。
// c、暂不考虑分母为0的情况。

// Sample Input
// 2 4 1 3

// Sample Output
// 1/2
// 1/3
// 5/6
// 1/2
// 1/3

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Fraction a = new Fraction(in.nextInt(), in.nextInt());
        Fraction b = new Fraction(in.nextInt(), in.nextInt());
        a.print();
        b.print();
        a.plus(b).print();
        a.print();
        b.print();
        in.close();
    }
}

class Fraction {
    int x, y;
    static int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    Fraction(int x, int y) {
        int d = gcd(x, y);
        this.x = x / d;
        this.y = y / d;
    }
    void print() {
        if (x == y)
            System.out.println(1);
        else if (x == 0)
            System.out.println(0);
        else
            System.out.println(x + "/" + y);
    }
    Fraction plus(Fraction r) {
        return new Fraction(x * r.y + r.x * y, y * r.y);
    }
}
