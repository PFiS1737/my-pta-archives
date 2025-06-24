// 给定一个有向图，每个顶点上的值表示该顶点启发函数 `h` 的值（输入保证 `h` 取值均合理），
// 使用 `A*` 算法求给定出发点到目标点的最短路径长度。
//
// 输入有多行，第一行为四个数 `m`， `n`，`s`，`d`，分别表示一个有向图的顶点数和边数，以及出发点和目标点（`0` 到 `n - 1`）。
// 第二行 `m` 个数，为每个顶点的启发函数 `h` 的值。
// 下面 `n` 行每行 3 个数，分别为一条边的起点和终点（`0` 到 `n - 1`）以及边的长度。

// Sample Input
// 12 21 0 7
// 7 8 6 5 5 3 3 0 7 4 5 3
// 0 1 4
// 0 2 10
// 0 3 11
// 1 2 8
// 1 4 5
// 2 4 15
// 3 4 8
// 3 5 20
// 3 6 2
// 4 6 1
// 4 9 20
// 4 8 16
// 5 7 17
// 6 7 13
// 8 10 2
// 8 9 1
// 9 11 13
// 9 7 5
// 9 10 5
// 10 11 7
// 11 7 16

// Sample Output
// 23

// Prepend Code Start
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int v, w;
};

int astar(int m, int s, int d, const vector<int> &h, const vector<vector<Edge>> &G);

int main() {
  int m, n, s, d;
  cin >> m >> n >> s >> d;

  vector<int> h(m);
  for (int i = 0; i < m; i++) {
    cin >> h[i];
  }

  vector<vector<Edge>> G(m);
  for (int i = 0; i < n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_back({v, w});
  }

  cout << astar(m, s, d, h, G) << endl;

  return 0;
}
// Prepend Code End

#include <queue>

struct Node {
  int id;
  int f;

  bool operator>(const Node &other) const {
    return f > other.f;
  }
};

int astar(int m, int s, int d, const vector<int> &h, const vector<vector<Edge>> &G) {
  vector<int> dist(m, 1e9);
  dist[s] = 0;

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  pq.push({s, h[s]});

  while (!pq.empty()) {
    auto [u, _] = pq.top();
    pq.pop();

    if (u == d) {
      return dist[u];
    }

    for (auto &[v, w] : G[u]) {
      int ng = dist[u] + w;
      if (ng < dist[v]) {
        dist[v] = ng;
        pq.push({v, ng + h[v]});
      }
    }
  }

  return -1;
}
