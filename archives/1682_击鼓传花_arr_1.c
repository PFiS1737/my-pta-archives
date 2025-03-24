// 删除数组元素法
//
// Description
// 设有N个人围成一个圈，每人手里都握着一个令牌写明一个数字（随机生成的）。从第一个人开始玩“击鼓传花”游戏，第一个击的次数为其令牌上写明的数字数（假设为m1）。第m1个人出列。下次再从第m1+1个人开始新的“击鼓传花”击的次数也为其令牌上写明的次数，等于该次数的人出列。重复以上过程直到所有人都出列为止。
// Input
// 输入第一行为测试数据组数。每组测试数据2行，第1行一个整数n（1<=n<=10000），代表人数，第2行有n个空格隔开的整数代表mi（1<=mi<=5000）。
// Output
// 对每组测试数据输出2行，第1行为数据组数，第2行为所有人顺序出队的序列，格式见样例。

// Sample Input
// 1
// 10
// 1 2 3 4 5 6 7 8 9 10

// Sample Output
// Case #1:
// 2 6 5 7 10 3 4 1 8

// tnnd，这个题是输出被删掉的那个人的初始位置，而不是他的 m 的值
// 你这个示例真 tmd...

#include <stdio.h>

typedef struct {
  int value;
  int index;
} Player;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    int len;
    scanf("%d", &len);

    Player arr[len];
    for (int j = 0; j < len; j++) {
      scanf("%d", &arr[j].value);
      // 该方法为就地地删除数组中的元素，故无法还原原始位置，需要额外记录
      arr[j].index = j + 1;
    }

    printf("Case #%d:\n", i);

    // 初始化指针位置
    int p = 0;

    int is_first = 1;

    // 循环 len - 1 遍
    while (--len) {
      // 获取需要走的步数
      int m = arr[p].value;

      // 指针往下移动到对应位置，注意循环
      // 另外，由于上面 len 减了一，这里记得要补上，因为这个最大长度是在原来数组上算的
      p = (p + m) % (len + 1);

      printf("%s%d", is_first ? (is_first = 0, "") : " ", arr[p].index);

      // 就地地删除 p 号元素，即将后面的元素依次往前移一个位置
      // 注意这里上限是 len，因为 len 前面已经减一了
      for (int k = p; k < len; k++) {
        arr[k] = arr[k + 1];
      }

      // 确保指针没有出界
      // 这里是为了处理上面正好是删的最后一个元素的情况
      p = p % len;
    }

    printf("\n");
  }

  return 0;
}
