// 在 3 x 3 的棋盘上，摆有八个滑块，每个棋子上标有 `1` \~ `8` 的某一数字。
// 棋盘中留有一个空格，空格用 `0` 来表示。
// 空格周围的滑块可以移到空格中，这样原来的位置就会变成空格。
//
// 给出一种初始布局和目标布局，试找到一种从初始布局到目标布局最少步骤的移动方法。
//
// ### 提示
//
// 本题考虑使用 `A*` 搜算算法完成，其中启发函数为不在目标位置的滑块数，或每个滑块到其目标位置的曼哈顿距离之和。
//
// ### 输入格式:
//
// 输入有两行，每行 `9` 个范围在 `0` \~ `8` 的数字，用空格隔开，
// 分别表示初始布局和目标布局（输入按从左到右、从上到下填入棋盘，`0` 表示该格子为空）。
//
// ### 输出格式:
//
// 输出为一行，一个数，为最小移动步数（无解输出 `-1`）。

// Sample Input
// 8 6 7 2 5 4 3 0 1
// 1 2 3 4 5 6 7 8 0

// Sample Output
// 31

#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

struct State {
  string board;
  int g;
  int h;

  int f() const {
    return g + h;
  }

  bool operator<(const State &other) const {
    return f() > other.f();
  }
};

int mismatch(const string &current, const string &target) {
  int count = 0;
  for (int i = 0; i < 9; ++i)
    if (current[i] != '0' && current[i] != target[i])
      count++;
  return count;
}

int solve(string start, string target) {
  priority_queue<State> pq;
  map<string, int> dist;

  pq.push({start, 0, mismatch(start, target)});
  dist[start] = 0;

  while (!pq.empty()) {
    State cur = pq.top();
    pq.pop();

    if (cur.board == target)
      return cur.g;

    int i = cur.board.find('0');
    int x = i / 3, y = i % 3;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d], ny = y + dy[d];
      if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
        continue;

      int j = nx * 3 + ny;
      string next = cur.board;
      swap(next[i], next[j]);

      if (!dist.count(next) || cur.g + 1 < dist[next]) {
        dist[next] = cur.g + 1;
        pq.push({next, cur.g + 1, mismatch(next, target)});
      }
    }
  }

  return -1;
}

int main() {
  string start = "", target = "";

  for (int i = 0; i < 9; ++i) {
    int x;
    cin >> x;
    start += x + '0';
  }
  for (int i = 0; i < 9; ++i) {
    int x;
    cin >> x;
    target += x + '0';
  }

  cout << solve(start, target) << endl;
  return 0;
}
