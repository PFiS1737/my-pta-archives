// 在类Point中重写Object类的equals方法。使Point对象x和y坐标相同时判定为同一对象。

// Sample Input
// 10 20
// 10 20

// Sample Output
// true

import java.util.Scanner;
class Point {
    private int xPos, yPos;
    public Point(int x, int y) {
        xPos = x;
        yPos = y;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Point) {
            Point o = (Point)obj;
            return o.xPos == xPos && o.yPos == yPos;
        }
        return false;
    }
}
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Object p1 = new Point(sc.nextInt(), sc.nextInt());
        Object p2 = new Point(sc.nextInt(), sc.nextInt());
        System.out.println(p1.equals(p2));
        sc.close();
    }
}
