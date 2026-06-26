// 设计一个学生信息添加和查询的系统，从键盘读入学生的数据，然后通过屏幕进行显示。
//
// 输入格式:
// 第一行有1个整数N,表示学生数量；
//
// 接下来有N行学生数据，分别表示学生的id（编号）、name（姓名）、birthday（生日）、score（成绩）属性的值，关键字(id)相同的记录代表同一个学生（如果id相同，后来读入的学生信息会覆盖已有的学生信息）
//
// 输出格式:
// 按照id从小到大的顺序，输出所有学生的属性名称及属性值，其中score（成绩）保留1位有效数字，具体输出格式见输出样例。
//
// 提示：可以利用Student类的toString()方法来实现类对象属性的展示。

// Sample Input
// 5
// 0001  Mike    1990-05-20  98.5
// 0002  John    1992-05-20  67
// 0003  Hill    1994-05-20  36.5
// 0004  Christ  1996-05-20  86.5
// 0001  Jack    1998-05-20  96

// Sample Output
// Student [id=0001, name=Jack, birthday=1998年05月20日, score=96.0]
// Student [id=0002, name=John, birthday=1992年05月20日, score=67.0]
// Student [id=0003, name=Hill, birthday=1994年05月20日, score=36.5]
// Student [id=0004, name=Christ, birthday=1996年05月20日, score=86.5]

import java.time.LocalDate;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        TreeMap<String, Student> students = new TreeMap<>();

        int n = sc.nextInt();
        while (n-- > 0) {
            String id = sc.next();
            String name = sc.next();
            LocalDate birthday = LocalDate.parse(sc.next());
            double score = sc.nextDouble();
            students.put(id, new Student(id, name, birthday, score));
        }

        students.forEach((i, st) -> { System.out.println(st); });

        sc.close();
    }
}

class Student implements Comparable {
    String id;
    String name;
    LocalDate birthday;
    double score;
    public Student(String id, String name, LocalDate birthday, double score) {
        this.id = id;
        this.name = name;
        this.birthday = birthday;
        this.score = score;
    }
    @Override
    public String toString() {
        // FIX: 傻逼题目，我调了半天，本来 id 用的 int，格式化为 %04d 然后 WE。
        //      最终改成 String。
        return String.format(
            "Student [id=%s, name=%s, birthday=%04d年%02d月%02d日, score=%.1f]", id, name,
            birthday.getYear(), birthday.getMonthValue(), birthday.getDayOfMonth(), score
        );
    }
    @Override
    public int compareTo(Object o) {
        if (o instanceof Student) {
            Student s = (Student)o;
            return this.id.compareTo(s.id);
        }
        return 0;
    }
}
