// 大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。
// 并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一次只能移动一个圆盘。
//
// 本题要求编写递归函数，输出n层汉诺塔问题的解的过程，
// 例如假设三根柱子编号分别为1、2、3，将圆盘从1号柱子移动到3号柱子，
// 当n=1时，直接从1号移动到3号即可，输出1->3；
// 当n=2时，则需要将1号柱的较小的圆盘先移动到2号柱子，
// 再将1号柱子的较大的圆盘移动到3号柱子，最后将2号柱子圆盘移动到3号柱子结束，
// 对应的输出结果为：1->2 、1->3、2->3，每次输出占一行。
//
// 在这里解释接口参数: n 表示移动的层数； a、b、c 是柱子的编号。
// 函数要求从a柱子移动到 c柱子。

// Sample Input
// 2

// Sample Output
// 1->2
// 1->3
// 2->3

// Append Code Start
#include <stdio.h>

void hanoi(int n, char a, char b, char c);

int main() {
  int n;
  char a = '1', b = '2', c = '3';
  scanf("%d", &n);
  hanoi(n, a, b, c);
  printf("\n");
}
// Append Code End

void hanoi(int n, char a, char b, char c) {
  if (n == 1) {
    printf("%c->%c\n", a, c);
    return;
  }

  hanoi(n - 1, a, c, b);
  printf("%c->%c\n", a, c);
  hanoi(n - 1, b, a, c);
}
