// 假定要为某个公司编写雇员工资支付程序，这个公司有各种类型的雇员（Employee），不同类型的雇员按不同的方式支付工资（都是整数）：
// （1）经理（Manager）——每月获得一份固定的工资
// （2）销售人员（Salesman）——在基本工资的基础上每月还有销售提成
// （3）一般工人（Worker）——则按他每月工作的天数计算工资
// 在Employee中提供方法getSalary()，用于计算每个雇员一个月的工资，并在子类中重写。
//
// Post_AppendCode的main方法中已经构造Employee的三个变量，分别指向Manager、Salesman、Worker的对象，调用getSalary方法，输出三个对象的工资。
// 要求：编码实现经理、销售人员、一般工人三个类。
//
// 输入描述：
// 经理的月工资
// 销售人员的基本工资 销售人员的提成
// 工人的工作天数 工人每天的工资
//
// 输出描述：
// 经理的工资
// 销售人员的工资
// 工人的工资

// Sample Input
// 12000
// 3000 5000
// 22 200

// Sample Output
// 12000
// 8000
// 4400

import java.util.Scanner;

abstract class Employee {
    int salary;
    Employee(int salary) {
        this.salary = salary;
    }
    abstract int getSalary();
}

class Manager extends Employee {
    public Manager(int salary) {
        super(salary);
    }
    @Override
    int getSalary() {
        return salary;
    }
}
class Salesman extends Employee {
    int raise;
    public Salesman(int salary, int raise) {
        super(salary);
        this.raise = raise;
    }
    @Override
    int getSalary() {
        return salary + raise;
    }
}
class Worker extends Employee {
    int days;
    public Worker(int salary, int days) {
        super(salary);
        this.days = days;
    }
    @Override
    int getSalary() {
        return salary * days;
    }
}

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int managerSalary = scan.nextInt();
        int salemanSalary = scan.nextInt();
        int salemanRaise = scan.nextInt();
        int workerEveryday = scan.nextInt();
        int workerDays = scan.nextInt();

        Employee e1 = new Manager(managerSalary);
        Employee e2 = new Salesman(salemanSalary, salemanRaise);
        Employee e3 = new Worker(workerEveryday, workerDays);

        System.out.println(e1.getSalary());
        System.out.println(e2.getSalary());
        System.out.println(e3.getSalary());

        scan.close();
    }
}
