// Description
//
// 输入同一天内的两个时间，求它们之间间隔多少秒。
//
// Input
// 输入有2行，每行是一个时间，格式为“hh-mm-ss”。
//
// Output
// 求输入的2个时间之间的间隔。

// Sample Input
// 0-0-0
// 1-1-1

// Sample Output
// 3661

#include <stdio.h>
#include <stdlib.h>

int time_to_seconds(int hours, int minutes, int seconds) {
  return hours * 3600 + minutes * 60 + seconds;
}

int main() {
  int h1, m1, s1;
  int h2, m2, s2;

  scanf("%d-%d-%d", &h1, &m1, &s1);
  scanf("%d-%d-%d", &h2, &m2, &s2);

  int time1 = time_to_seconds(h1, m1, s1);
  int time2 = time_to_seconds(h2, m2, s2);

  int diff = abs(time2 - time1);

  printf("%d\n", diff);

  return 0;
}
