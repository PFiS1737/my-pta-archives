// 定义Student学生类，拥有学号、姓名、性别属性，提供构造函数，以及相应属性的get set函数，提供函数attendClass(String className)表示上课。
// 定义CollegeStudent大学生类继承自Student类，拥有新增属性专业，提供构造函数，提供新增属性的get和set函数
// 定义GraduateStudent研究生类继承自CollegeStudent类，拥有新增属性导师，提供构造函数，提供新增属性的get和set函数，提供函数doResearch() 表示做研究（打印xx is doing research）。
//
// main函数中对构造的类进行测试
//
// 输入描述：
// 学生类信息，学号、姓名、性别
// 大学生类信息，学号、姓名、性别、专业
// 研究生类信息，学号、姓名、性别、专业、导师
//
// 输出描述：
// 学生类信息
// 大学生类信息
// 研究生类信息

// Sample Input
// 1 liu female
// 2 chen female cs
// 3 li male sc wang

// Sample Output
// no: 1
// name: liu
// sex: female
// no: 2
// name: chen
// sex: female
// major: cs
// no: 3
// name: li
// sex: male
// major: sc
// supervisor: wang
// li is doing research

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int no = scan.nextInt();
        String name = scan.next();
        String sex = scan.next();
        Student s = new Student(no, name, sex);
        s.print();

        no = scan.nextInt();
        name = scan.next();
        sex = scan.next();
        String major = scan.next();
        CollegeStudent c = new CollegeStudent(no, name, sex, major);
        c.print();

        no = scan.nextInt();
        name = scan.next();
        sex = scan.next();
        major = scan.next();
        String supervisor = scan.next();
        GraduateStudent g = new GraduateStudent(no, name, sex, major, supervisor);
        g.print();
        g.doResearch();
        scan.close();
    }
}

class Student {
    int id;
    String name;
    String sex;
    Student(int id, String name, String sex) {
        this.id = id;
        this.name = name;
        this.sex = sex;
    }
    void print() {
        System.out.printf("no: %d\nname: %s\nsex: %s\n", id, name, sex);
    }
}

class CollegeStudent extends Student {
    String major;
    CollegeStudent(int id, String name, String sex, String major) {
        super(id, name, sex);
        this.major = major;
    }

    @Override
    void print() {
        super.print();
        System.out.printf("major: %s\n", major);
    }
}

class GraduateStudent extends CollegeStudent {
    String supervisor;
    GraduateStudent(int id, String name, String sex, String major, String supervisor) {
        super(id, name, sex, major);
        this.supervisor = supervisor;
    }

    @Override
    void print() {
        super.print();
        System.out.printf("supervisor: %s\n", supervisor);
    }

    void doResearch() {
        System.out.println(name + " is doing research");
    }
}
