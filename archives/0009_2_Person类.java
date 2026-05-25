// 构造Person类。包括姓名(name)，性别(sex)和年龄(age)。提供所有属性的set和get函数，提供print函数打印其信息
//
// 输入描述：
// 姓名(name)，性别(sex)和年龄(age)
//
// 输出描述：
// 用户信息

// Sample Input
// Lucy male 23

// Sample Output
// name:Lucy; sex:male; age:23

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String name = scan.next();
        String sex = scan.next();
        int age = scan.nextInt();
        Person p = new Person();
        p.setName(name);
        p.setSex(sex);
        p.setAge(age);
        p.print();
        scan.close();
    }
}

class Person {
    String name;
    int age;
    String sex;
    String getName() {
        return name;
    }
    void setName(String name) {
        this.name = name;
    }
    int getAge() {
        return age;
    }
    void setAge(int age) {
        this.age = age;
    }
    String getSex() {
        return sex;
    }
    void setSex(String sex) {
        this.sex = sex;
    }
    void print() {
        System.out.printf("name:%s; sex:%s; age:%d\n", name, sex, age);
    }
}
