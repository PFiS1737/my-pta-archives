// 请按类图创建类Shape、Circle、Rectangle、Pillar。其中Pillar类（柱类），该类的getVolume()方法可以计算柱体的体积。
// 柱体的体积=底面积*高。
// 柱体的底面可能是圆形，矩形或其他形状。
//
// 类图：
// 柱的体积.png
//
// 注意：
// shape类中的getArea()方法是抽象方法。
// 类Circle中，成员变量r表示半径；构造方法Circle()用参数r初始化域r；成员方法getArea()计算并返回圆面积，使用Math.PI。
// 类Rectangle中，成员变量a表示矩形长；成员变量b表示矩形宽；构造方法Rectangle ()用参数a、b分别初始化域a和域b；成员方法getArea()计算并返回矩形面积。
// 类Pillar中，成员变量bottom表示柱形底面；成员变量height表示柱形高；构造方法Pillar()用参数bot和hei分别初始化域bottom和域height；成员方法getVolume()计算并返回柱形体积。

// Sample Input
// 1 10
// 2 5 10

// Sample Output
// 圆形底的柱体体积31.42
// 矩形底的柱体体积100.00

import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        //声明Pillar类对象pil
        Pillar pil;
        //声明Shape类对象shp;
        Shape shp;
        //键盘输入半径r，创建半径为r的Circle类对象，赋值给对象shp
        double r = in.nextDouble();
        shp = new Circle(r);
        //键盘输入柱形高h，用底面shp和高h创建Pillar类对象，赋值给对象pil
        double h = in.nextDouble();
        pil = new Pillar(shp, h);
        //显示柱形体积
        System.out.printf("圆形底的柱体体积%.2f\n", pil.getVolume());
        //键盘输入矩形长a和宽b，创建Rectangle类对象，赋值给对象shp
        double a = in.nextDouble();
        double b = in.nextDouble();
        shp = new Rectangle(a, b);
        //键盘输入柱形高h，用底面shp和高h创建Pillar类对象，赋值给对象pil
        h = in.nextDouble();
        pil = new Pillar(shp, h);
        //显示柱形体积
        System.out.printf("矩形底的柱体体积%.2f\n", pil.getVolume());
        in.close();
    }
}

abstract class Shape {
    abstract double getArea();
}

class Circle extends Shape {
    double r;
    Circle(double r) {
        this.r = r;
    }

    @Override
    double getArea() {
        return Math.PI * r * r;
    }
}

class Rectangle extends Shape {
    double a, b;
    Rectangle(double a, double b) {
        this.a = a;
        this.b = b;
    }

    @Override
    double getArea() {
        return a * b;
    }
}

class Pillar {
    Shape b;
    double h;

    Pillar(Shape b, double h) {
        this.b = b;
        this.h = h;
    }

    double getVolume() {
        return b.getArea() * h;
    }
}
