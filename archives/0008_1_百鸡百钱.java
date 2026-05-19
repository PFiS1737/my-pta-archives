// 鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何？
//
// 输出格式:
// 输出购买公鸡、母鸡、小鸡的数量，如果有多种购买方式，则全部输出。

// Sample Input
// 

// Sample Output
// 公鸡:0母鸡:25小鸡:75
// 公鸡:4母鸡:18小鸡:78
// 公鸡:8母鸡:11小鸡:81
// 公鸡:12母鸡:4小鸡:84

public class Main {
    public static void main() {
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int k = 100 - i - j;
                if (k % 3 != 0)
                    continue;
                if (i * 5 + j * 3 + k / 3 == 100) {
                    System.out.println("公鸡:" + i + "母鸡:" + j + "小鸡:" + k);
                }
            }
        }
    }
}
