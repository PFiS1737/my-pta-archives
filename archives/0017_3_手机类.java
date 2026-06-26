// 构造手机类，包含其配置信息：型号（字符串）、内存大小（整数）、存储空间（整数，GB为单位）、价格（整数）。提供带参数的构造函数，重写其equals方法，使得两个相同配置（型号、内存、存储相同即可，价格可不同）的手机为相等的手机。重写其toString函数，打印手机的配置信息，形式为CellPhone [model:xxx, memory:xxx, storage:xxx, price:xxx]
// main函数中从键盘读入两个手机对象，比较他们是否相等，输出他们的配置信息。
//
// 输入描述：
// 两个计算机对象，包含型号、内存、存储空间、价格
//
// 输出描述：
// 两个对象是否相等，两个对象的配置信息

// Sample Input
// P20 8 64 4999
// P20 8 64 4999

// Sample Output
// true
// CellPhone [model:P20, memory:8, storage:64, price:4999]
// CellPhone [model:P20, memory:8, storage:64, price:4999]

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        CellPhone c1 = new CellPhone(sc.next(), sc.nextInt(), sc.nextInt(), sc.nextInt());
        CellPhone c2 = new CellPhone(sc.next(), sc.nextInt(), sc.nextInt(), sc.nextInt());

        System.out.println(c1.equals(c2));
        System.out.println(c1);
        System.out.println(c2);

        sc.close();
    }
}

class CellPhone {
    String t;
    int mem;
    int sd;
    int price;
    CellPhone(String t, int mem, int sd, int price) {
        this.t = t;
        this.mem = mem;
        this.sd = sd;
        this.price = price;
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof CellPhone) {
            CellPhone c = (CellPhone)o;
            return this.t.equals(c.t) && this.mem == c.mem && this.sd == c.sd;
        }
        return false;
    }

    @Override
    public String toString() {
        return String.format(
            "CellPhone [model:%s, memory:%d, storage:%d, price:%d]", this.t, this.mem,
            this.sd, this.price
        );
    }
}
