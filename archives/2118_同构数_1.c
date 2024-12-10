// Description
// 正整数n若是它平方数的尾部，则称n为同构数。例如：5的平方数是25，且5出现在25的右侧，那么5就是一个同构数。
// Input
// 一个不超过4位的正整数N。
//
// Output
// 如果N是一个同构数，则输出：YES。否则输出NO。

// Sample Input
// 5

// Sample Output
// YES

#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  unsigned long long nn = n * n;

  char strn[20];
  char strnn[20];

  sprintf(strn, "%19d", n);
  sprintf(strnn, "%19llu", nn);

  for (int i = 19; i > 0; i--) {
    if (strn[i] == ' ')
      break;
    if (strnn[i] != strn[i]) {
      puts("NO\n");
      return 0;
    }
  }

  puts("YES\n");

  return 0;
}
