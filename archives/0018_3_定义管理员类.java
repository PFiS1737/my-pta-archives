// 定义一个系统管理员，其中包括两个属性：姓名（name），密码（password，初始值设置为“123456”），一个方法（login）用于判断用户输入的密码是否正确。

// Sample Input
// 张三
// 123456

// Sample Output
// 密码正确，欢迎张三登录系统

import java.util.Scanner;

class Admin {
    String name;
    String password = "123456";

    void login(String password) {
        if (password.equals(this.password)) {
            System.out.println("密码正确，欢迎" + name + "登录系统");
        } else {
            System.out.println("密码错误，" + name + "您无权登录系统");
        }
    }
}

//在这里给出函数被调用进行测试的例子。例如：
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.next();
        Admin ad1 = new Admin();
        ad1.name = name;
        String pw = sc.next();
        ad1.login(pw);
        sc.close();
    }
}
