// 假设以S和X分别表示入栈和出栈操作。
// 如果根据一个仅由S和X构成的序列，对一个空堆栈进行操作，相应操作均可行（如没有出现删除时栈空）且最后状态也是栈空，则称该序列是合法的堆栈操作序列。
// 请编写程序，输入S和X序列，判断该序列是否合法。
//
// 输入第一行给出两个正整数 n 和 m，其中 n 是待测序列的个数，m（≤50）是堆栈的最大容量。
// 随后 n 行，每行中给出一个仅由S和X构成的序列。序列保证不为空，且长度不超过100。

// Sample Input
// 4 10
// SSSXXSXXSX
// SSSXXSXXS
// SSSSSSSSSSXSSXXXXXXXXXXX
// SSSXXSXXX

// Sample Output
// YES
// NO
// NO
// NO

#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  getchar();
  while (n--) {
    int s = 0, flag = 0;
    char c;
    while (scanf("%c", &c) && c != 10) {
      switch (c) {
      case 'S':
        s++;
        if (s > m) {
          flag = 1;
        }
        break;
      case 'X':
        s--;
        if (s < 0) {
          flag = 1;
        }
        break;
      }
    }
    if (s == 0 && flag == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
