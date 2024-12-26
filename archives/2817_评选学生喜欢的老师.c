// Description
// 为了评选学生喜欢的老师，某校组织各班进行投票。投票和评选规则是：
//
// 1.每个学生只能投1个老师；
//
// 2.每个班级的任课教师数不同，该班级中每个老师的得票率是其获得的票数除以该班级的总人数。
//
// 3.每个老师可以给多个班级任课。
//
// 4.所有教师中，得票率最高的3位获评为学生喜欢的老师。
//
// 请编程实现上述过程。
//
// Input
// 输入有若干行，每行对应一个班级的投票情况。开头是2个整数，分别是为该班级上课的教师数和学生数。之后输入每个教师的姓名（不含空白符）和得票数。
//
// Output
// 先按照得票率从高到底，输出每个教师的姓名和得票率（保留2位小数），中间用1个空格分开，每个教师占一行。再输出获得“学生喜欢的教师”的教师姓名（按照得票率从高到低）。

// Sample Input
// 1 30 Tom 30
// 3 30 Jack 10 Zhang 20 Li 0
// 5 40 Li 10 Tao 10 Tom 15 Zhang 3 Hou 2
// 4 30 Tao 25 Li 1 Hou 1 Zhang 3

// Sample Output
// Tom 1.00
// Tao 0.83
// Zhang 0.67
// Jack 0.33
// Li 0.25
// Hou 0.05
// Tom
// Tao
// Zhang

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEACHERS 1000
#define MAX_NAME_LEN 100
#define EPSILON 1e-6

typedef struct {
  char name[MAX_NAME_LEN];
  double rate;
} Teacher;

int fcmp(double a, double b) {
  if (fabs(a - b) < EPSILON) {
    return 0;
  }
  return a < b ? -1 : 1;
}

int compare(const void *a, const void *b) {
  Teacher *teacher_a = (Teacher *)a;
  Teacher *teacher_b = (Teacher *)b;

  return fcmp(teacher_b->rate, teacher_a->rate);
}

int main() {
  int n, N;

  Teacher teacher_list[MAX_TEACHERS];
  int teacher_index = 0;

  while (scanf("%d %d", &n, &N) != EOF) {
    while (n--) {
      char name[MAX_NAME_LEN];
      int count;
      scanf("%s %d", name, &count);

      for (int i = 0; i < teacher_index; i++) {
        if (!strcmp(teacher_list[i].name, name)) {
          double rate = (double)count / N;
          if (rate > teacher_list[i].rate) {
            teacher_list[i].rate = rate;
          }
          goto a;
        }
      }

      teacher_list[teacher_index] = (Teacher){.rate = (double)count / N};
      strcpy(teacher_list[teacher_index].name, name);
      teacher_index++;

    a: {}
    }
  }

  qsort(teacher_list, teacher_index, sizeof(Teacher), compare);

  for (int i = 0; i < teacher_index; i++) {
    printf("%s %.2lf\n", teacher_list[i].name, teacher_list[i].rate);
  }

  printf("%s\n", teacher_list[0].name);
  printf("%s\n", teacher_list[1].name);
  printf("%s\n", teacher_list[2].name);
}
