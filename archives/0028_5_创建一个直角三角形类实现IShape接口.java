// 创建一个直角三角形类（regular triangle）RTriangle类，实现下列接口IShape。两条直角边长作为RTriangle类的私有成员，类中包含参数为直角边的构造方法。
//
// interface IShape {// 接口
//
//    public abstract double getArea(); // 抽象方法 求面积
//
//    public abstract double getPerimeter();  // 抽象方法 求周长
//
// }
//
// ###直角三角形类的定义：
//
// 直角三角形类的构造函数原型如下：
// RTriangle(double a, double b);

// Sample Input
// 3.1 4.2

// Sample Output
// 6.51
// 12.5202

import java.text.DecimalFormat;
import java.util.Scanner;

interface IShape {
    public abstract double getArea();

    public abstract double getPerimeter();
}

class RTriangle implements IShape {
    double a, b, c;
    RTriangle(double a, double b) {
        this.a = a;
        this.b = b;
        this.c = Math.sqrt(a * a + b * b);
    }
    @Override
    public double getArea() {
        return (a * b) / 2;
    }
    @Override
    public double getPerimeter() {
        return a + b + c;
    }
}

public class Main {
    public static void main(String[] args) {
        DecimalFormat d = new DecimalFormat("#.####");
        Scanner input = new Scanner(System.in);
        double a = input.nextDouble();
        double b = input.nextDouble();
        IShape r = new RTriangle(a, b);
        System.out.println(d.format(r.getArea()));
        System.out.println(d.format(r.getPerimeter()));
        input.close();
    }
}
