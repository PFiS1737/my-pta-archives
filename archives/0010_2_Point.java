// There is a class Point that is incompleted. Please complete the class according to the test code in Main.

// Sample Input
// 3.14 1.9 2.72

// Sample Output
// (0.0,2.72)
// (3.14,1.9)
// (3.14,1.9)
// (5.86,3.8)
// b.x=3.14 b.y=1.9

import java.util.Scanner;

class Point {
    private double x;
    private double y;
    public String toString() {
        return "(" + this.x + "," + this.y + ")";
    }

    Point() {
        x = 0;
        y = 0;
    }
    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }
    Point(Point p) {
        this.x = p.x;
        this.y = p.y;
    }

    void setX(double x) {
        this.x = x;
    }
    void setY(double y) {
        this.y = y;
    }

    double getX() {
        return this.x;
    }
    double getY() {
        return this.y;
    }

    Point add(Point p) {
        return new Point(this.x + p.x, this.y + p.y);
    }
}

public class Main {
    public static void main(String[] args) {
        Point a = new Point(); //    default ctor, x and y are zeros
        Scanner sc = new Scanner(System.in);
        double x, y, z;
        x = sc.nextDouble();
        y = sc.nextDouble();
        z = sc.nextDouble();
        Point b = new Point(x, y); //  ctor by x and y
        Point c = new Point(b);    //  ctor by another Point
        a.setY(z);
        System.out.println(a);
        System.out.println(b);
        System.out.println(c);
        c.setX(z);
        a = b.add(c);
        System.out.println(a);
        System.out.println("b.x=" + b.getX() + " b.y=" + b.getY());
        sc.close();
    }
}
