// 你好车辆共享公司现有两种共享车辆，即共享汽车和共享单车。共享汽车包含车牌号（String类型）和售价（double类型），共享单车包含车牌号（String类型）。不同车辆的租金计算方式不同，具体计算方式如下：
// 1、共享汽车，租金天计算，每天租金为售价的0.1%；
// 2、共享单车，租金天计算，每天租金为12元。
//
// 现需要您构造上述共享车辆的继承体系，他们均继承自你好车辆类（HiINC）,且提供方法getRent()返回租金。在main函数中构造了HiINC数组，包含共享汽车和共享单车对象，调用HiINC类中的静态方法calculateRent得到并输出租金，保留小数点两位。
//
// 函数接口定义：
// double getRent();
// static double calculateRent(HiINC[] hi, int days);

// Sample Input
// 5
// car C001 253000
// car C002 163000
// bicycle B001 
// bicycle B002
// car C003 161000
// 20

// Sample Output
// 12020.00

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        HiINC[] hi = new HiINC[n];
        for (int i = 0; i < n; i++) {
            String type = sc.next();
            if (type.equals("bicycle")) {
                hi[i] = new Bicycle(sc.next());
            } else {
                hi[i] = new Car(sc.next(), sc.nextDouble());
            }
        }
        double rent = HiINC.calculateRent(hi, sc.nextInt());
        System.out.printf("%.2f", rent);
        sc.close();
    }
}

class HiINC {
    double rent;
    HiINC(double rent) {
        this.rent = rent;
    }
    double getRent() {
        return rent;
    }
    static double calculateRent(HiINC[] hi, int days) {
        double total = 0;
        for (HiINC h : hi) {
            total += h.getRent() * days;
        }
        return total;
    }
}

class Car extends HiINC {
    String id;
    double price;
    Car(String id, double price) {
        super(price * 0.001);
        this.id = id;
        this.price = price;
    }
}

class Bicycle extends HiINC {
    String id;
    Bicycle(String id) {
        super(12);
        this.id = id;
    }
}
