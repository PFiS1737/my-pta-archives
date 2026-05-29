// 由于奖学金评选工作需要，现需要设计一套系统对学生是否具有评选资格进行筛选，目前已给出一个学生类Student，其包含学号（String id）、综合测评成绩（double ca）两个私有属性，以及具有能够初始化学号和综合测评成绩两个参数的构造方法和判断是否具有参评奖学金资格的方法(boolean isReq())，需要您完成以下内容：
//
// 1、定义本科生类Undergraduate继承Student，并重写isReq()若ca>=80时返回true,否则返回false;
//
// 2、定义研究生类Graduate继承Student，增加导师确认（boolean supervisor）属性，并重写isReq()若ca>=85且supervisor为true时返回true,否则返回false;
//
// 注意：除题目已给出的属性，所有类不得添加新的属性，但可以适当添加方法。

// Sample Input
// 7
// 001 56
// 002 80
// 003 81
// 004 12 false
// 005 80 false
// 006 85 false
// 007 85 true

// Sample Output
// 001 fail
// 002 pass
// 003 pass
// 004 fail
// 005 fail
// 006 fail
// 007 pass

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //通过键盘输入确定Student数组的长度
        Student[] stu = new Student[Integer.parseInt(sc.nextLine())];
        for (int i = 0; i < stu.length; i++) {
            //截取输入的字符
            String[] str = sc.nextLine().split("\\s+");
            //三个字符串表示为Graduate，否则为Undergraduate
            if (str.length > 2) {
                stu[i] = new Graduate(str[0], Double.parseDouble(str[1]),
                                      Boolean.parseBoolean(str[2]));
            } else {
                stu[i] = new Undergraduate(str[0], Double.parseDouble(str[1]));
            }
        }

        //循环输出结果
        for (int i = 0; i < stu.length; i++) {
            if (stu[i].isReq())
                System.out.println(stu[i].getId() + " pass");
            else
                System.out.println(stu[i].getId() + " fail");
        }

        sc.close();
    }
}

class Student {
    private String id;
    private double ca;

    public Student(String id, double ca) {
        this.id = id;
        this.ca = ca;
    }

    public boolean isReq() {
        return false;
    }

    public String getId() {
        return id;
    }

    public double getCA() {
        return ca;
    }
}

class Graduate extends Student {
    boolean supervisor;
    Graduate(String id, double ca, boolean supervisor) {
        super(id, ca);
        this.supervisor = supervisor;
    }

    @Override
    public boolean isReq() {
        return getCA() >= 85 && supervisor;
    }
}

class Undergraduate extends Student {
    Undergraduate(String id, double ca) {
        super(id, ca);
    }

    @Override
    public boolean isReq() {
        return getCA() >= 80;
    }
}
