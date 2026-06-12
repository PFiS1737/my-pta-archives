// 有一个团队由5个人组成。他们每个人给指导老师一个分数，去掉最高分，去掉最低分，剩下的3个分数的平均分就是该团队对指导老师的评分。

// Sample Input
// 1 2 4 6 9

// Sample Output
// 4.00

import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] grade = new int[5];
        for (int i = 0; i < grade.length; i++) {
            grade[i] = in.nextInt();
        }
        RR rr = new RT(grade);
        double dd = rr.mark();
        System.out.printf("%.2f", dd);
        in.close();
    }
}
abstract class RR {
    int[] grade;
    public RR(int[] grade) {
        this.grade = grade;
    }
    public abstract double mark();
}
class RT extends RR {
    RT(int[] grade) {
        super(grade);
    }
    @Override
    public double mark() {
        double sum = 0;
        for (int i = 1; i < grade.length - 1; i++) {
            sum += grade[i];
        }
        return sum / (grade.length - 2);
    }
}
