// 需要你编写的Dog子类：
// 实现IAbility接口
//
// showInfo方法输出Dog的name、age，输出格式样例为：我是一只狗,我的名字是Mike,今年2岁（注意：输出结果中没有空格，逗号为英文标点符号）
//
// cry方法输出Dog 的叫声，输出格式样例为：旺旺
//
// 需要你编写的Cat子类：
// 实现IAbility接口
//
// showInfo方法输出Cat的name、age，输出格式样例为：我是一只猫,我的名字是Anna,今年4岁（注意：输出结果中没有空格，逗号为英文标点符号）
//
// cry方法输出Cat 的叫声，输出格式样例为：喵喵
//
// 需要你编写的模拟器类Simulator：
// void playSound(IAbility animal)：调用实现了IAbility接口类的showInfo和cry方法，并显示传入动物的名字和年龄

// Sample Input
// 1 Mike 2

// Sample Output
// 我是一只狗,我的名字是Mike,今年2岁
// 旺旺
// Mike
// 2

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        IAbility animal = null;
        int type = input.nextInt();
        String name = input.next();
        int age = input.nextInt();
        if (type == 1)
            animal = new Dog(name, age);
        else
            animal = new Cat(name, age);

        Simulator sim = new Simulator();
        sim.playSound(animal);
        input.close();
    }
}

abstract class Animal {
    private String name; //名字
    private int age;     //年龄

    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
}

interface IAbility {
    void showInfo(); //输出动物信息
    void cry();      //动物发出叫声
}

class Dog extends Animal implements IAbility {
    Dog(String name, int age) {
        super(name, age);
    }
    @Override
    public void showInfo() {
        System.out.printf("我是一只狗,我的名字是%s,今年%d岁\n", getName(), getAge());
    }
    @Override
    public void cry() {
        System.out.println("旺旺");
    }
}

class Cat extends Animal implements IAbility {
    Cat(String name, int age) {
        super(name, age);
    }
    @Override
    public void showInfo() {
        System.out.printf("我是一只猫,我的名字是%s,今年%d岁\n", getName(), getAge());
    }
    @Override
    public void cry() {
        System.out.println("喵喵");
    }
}

class Simulator {
    public void playSound(IAbility a) {
        a.showInfo();
        a.cry();

        if (a instanceof Animal) {
            Animal animal = (Animal)a;
            System.out.println(animal.getName());
            System.out.println(animal.getAge());
        }
    }
}
