// Description
// 你的朋友刚买了一台新电脑，他以前用过的最强大的计算工具是一台袖珍计算器。现在，看着自己的新电脑，他有点失望，因为他更喜欢计算器上的LC显示器。所以，你决定写一个LC显示风格的程序帮他在电脑上显示数字。
//
// Input
// 输入包括若干行，每一行有两个整数。输入为两个0表示结束，并且此行不被处理。
//
// 每行输入的两个整数s和n，满足1<=s<=10且0<=n<=99 999 999，其中n是要被现实的数字，s是n应该显示的大小（放大的倍数）。
//
// Output
// 输出的数字是LC显示风格的：使用s个“-”表示水平线和s个“|”竖直线，每个数字刚好占据s+2列和2s+3行，所有没有“-”和“|”的空白处请用空格填满。并且每两个数字之间要有一列空格。
//
// 每一行输入数字对应上述一组LC显示风格输出。任意两组数字的输出之间用一个空行分割。

// Sample Input
// 2 12345
// 3 67890
// 0 0

// Sample Output
//       --   --        -- 
//    |    |    | |  | |   
//    |    |    | |  | |   
//       --   --   --   -- 
//    | |       |    |    |
//    | |       |    |    |
//       --   --        -- 
//
//  ---   ---   ---   ---   --- 
// |         | |   | |   | |   |
// |         | |   | |   | |   |
// |         | |   | |   | |   |
//  ---         ---   ---       
// |   |     | |   |     | |   |
// |   |     | |   |     | |   |
// |   |     | |   |     | |   |
//  ---         ---   ---   --- 

#include <stdio.h>
#include <string.h>

#define MAX_ROWS 23
#define MAX_COLS 105

const int digit_map[10][7] = {
    {1, 1, 1, 0, 1, 1, 1}, // 0
    {0, 0, 1, 0, 0, 1, 0}, // 1
    {1, 0, 1, 1, 1, 0, 1}, // 2
    {1, 0, 1, 1, 0, 1, 1}, // 3
    {0, 1, 1, 1, 0, 1, 0}, // 4
    {1, 1, 0, 1, 0, 1, 1}, // 5
    {1, 1, 0, 1, 1, 1, 1}, // 6
    {1, 0, 1, 0, 0, 1, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}, // 9
};

void draw_digit(char output[MAX_ROWS][MAX_COLS], int n, int s, int offset) {
  const int *seg = digit_map[n];
  int height = 2 * s + 3;

  // 上
  if (seg[0]) {
    for (int i = 1; i <= s; i++) {
      output[0][offset + i] = '-';
    }
  }
  // 左上
  if (seg[1]) {
    for (int i = 1; i <= s; i++) {
      output[i][offset] = '|';
    }
  }
  // 右上
  if (seg[2]) {
    for (int i = 1; i <= s; i++) {
      output[i][offset + s + 1] = '|';
    }
  }
  // 中
  if (seg[3]) {
    for (int i = 1; i <= s; i++) {
      output[s + 1][offset + i] = '-';
    }
  }
  // 左下
  if (seg[4]) {
    for (int i = s + 2; i < height - 1; i++) {
      output[i][offset] = '|';
    }
  }
  // 右下
  if (seg[5]) {
    for (int i = s + 2; i < height - 1; i++) {
      output[i][offset + s + 1] = '|';
    }
  }
  // 下
  if (seg[6]) {
    for (int i = 1; i <= s; i++) {
      output[height - 1][offset + i] = '-';
    }
  }
}

void draw_number(char output[MAX_ROWS][MAX_COLS], int s, char *n) {
  int len = strlen(n);
  int offset = 0;
  for (int i = 0; i < len; i++) {
    if (i > 0)
      offset++; // 空列

    draw_digit(output, n[i] - '0', s, offset);
    offset += s + 2;
  }
}

int main() {
  int s, nn;
  while (scanf("%d %d", &s, &nn)) {
    if (s == 0 && nn == 0)
      break;

    char n[9];
    sprintf(n, "%d", nn);

    int len = strlen(n);
    int height = 2 * s + 3;
    int width = len - 1 + len * (s + 2);

    char output[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
      for (int j = 0; j < MAX_COLS; j++) {
        output[i][j] = ' ';
      }
      output[i][width] = '\0';
    }

    draw_number(output, s, n);

    for (int i = 0; i < height; i++) {
      printf("%s\n", output[i]);
    }
    printf("\n");
  }
  return 0;
}
