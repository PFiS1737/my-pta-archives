// 设计交通工具类Vehicle，其中的私有属性包括：类别kind、速度speed、颜色color；其中的公共方法包括：设置类别setKind( )、设置速度setSpeed( )、设置颜色setColor( )、获取类别getKind( )、获取速度getSpeed( )、获取颜色getColor( )。
//
// 定义测试类Main，在其main方法中创建两个Vehicle的对象v1和v2，通过键盘输入数据，为其设置不同的类别、速度和颜色，同时输出其所有信息。
//
// 输入格式:
// 前三行分别输入v1的类别、速度、颜色，
// 后三行分别输入v2的类别、速度、颜色。
//
// 输出格式:
// 第一行输出v1的类别、速度和颜色,
// 第二行输出v2的类别、速度和颜色。

// Sample Input
// 摩托车
// 50
// 红色
// 小汽车
// 100
// 黑色

// Sample Output
// 第一辆是摩托车，时速为50.0km/h，颜色为红色
// 第二辆是小汽车，时速为100.0km/h，颜色为黑色

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        String kinds = in.next();
        double speed = in.nextDouble();
        String color = in.next();

        Vehicle v1 = new Vehicle(kinds, speed, color);
        System.out.println("第一辆是" + v1.toString());

        kinds = in.next();
        speed = in.nextDouble();
        color = in.next();

        Vehicle v2 = new Vehicle(kinds, speed, color);
        System.out.println("第二辆是" + v2.toString());

        in.close();
    }
}

class Vehicle {
    String kind;
    double speed;
    String color;

    @Override
    public String toString() {
        return String.format("%s，时速为%.1fkm/h，颜色为%s", kind, speed, color);
    }

    public Vehicle(String kind, double speed, String color) {
        this.kind = kind;
        this.speed = speed;
        this.color = color;
    }
    public String getKind() {
        return kind;
    }
    public void setKind(String kind) {
        this.kind = kind;
    }
    public double getSpeed() {
        return speed;
    }
    public void setSpeed(double speed) {
        this.speed = speed;
    }
    public String getColor() {
        return color;
    }
    public void setColor(String color) {
        this.color = color;
    }
}
