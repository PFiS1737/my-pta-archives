// Description
// 输入不超过100个（24小时制）时间，把它们按从前到后进行排序。
//
//  -----------------------------------------------------------------------------
//
//  至少编写三个函数完成程序：
//
//  原型：int get_time(struct time tm[]);
//
//  功能：按格式从输入读取若干时间存入结构体数组tm[]中，返回值为实际输入的时间个数。
//
//  原型：int sort_time(struct time tm[], int n);
//
//  功能：将结构体数组tm中的时间按从小到大排序。
//
//  原型：int put_time(struct time tm[], int n);
//
//  功能：将结构体数组tm中的时间按顺序输出，格式见样例。
//
//  函数的调用格式见“Append Code”，结构体“struct time”的类型定义根据“Append Code”自行给出。
//
// Input
// 输入为两部分，第一部分为整数n，n<=100，第二部分为n行，每行三行个整数，表示时间的小时、分钟、秒。
//
// Output
// 输出为n个从小到大的时间，格式为”hh:mm:ss”，时分秒均输出2位，不足前补0。

// Sample Input
// 5
// 12 0 30
// 12 3 30
// 11 1 30
// 11 3 20
// 12 3 20

// Sample Output
// 11:01:30
// 11:03:20
// 12:00:30
// 12:03:20
// 12:03:30

// Append Code
// int main() {
//   struct time tm[100];
//   int n;
//   n = get_time(tm);
//   sort_time(tm, n);
//   put_time(tm, n);
// }

#include <stdio.h>
#include <stdlib.h>

struct time {
  int hour;
  int minute;
  int second;
};

int get_time(struct time tm[]) {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &tm[i].hour, &tm[i].minute, &tm[i].second);
  }

  return n;
}

int compare(const void *a, const void *b) {
  struct time *tm1 = (struct time *)a;
  struct time *tm2 = (struct time *)b;

  if (tm1->hour != tm2->hour) {
    return tm1->hour - tm2->hour;
  } else if (tm1->minute != tm2->minute) {
    return tm1->minute - tm2->minute;
  } else {
    return tm1->second - tm2->second;
  }
}

void sort_time(struct time tm[], int n) {
  qsort(tm, n, sizeof(struct time), compare);
}

void put_time(struct time tm[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%02d:%02d:%02d\n", tm[i].hour, tm[i].minute, tm[i].second);
  }
}
