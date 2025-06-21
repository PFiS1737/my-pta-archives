// 作为一个城市的应急救援队伍的负责人，你有一张特殊的全国地图。
// 在地图上显示有多个分散的城市和一些连接城市的快速道路。
// 每个城市的救援队数量和每一条连接两个城市的快速道路长度都标在地图上。
// 当其他城市有紧急求助电话给你的时候，你的任务是带领你的救援队尽快赶往事发地，同时，一路上召集尽可能多的救援队。
//
// 输入格式:
// 输入第一行给出 4 个正整数 n、m、s、d，其中 n（2≤n≤500）是城市的个数，顺便假设城市的编号为 0 ~ (n−1)；
// m 是快速道路的条数；s 是出发地的城市编号；d是目的地的城市编号。
// 第二行给出 n 个正整数，其中第 i 个数是第 i 个城市的救援队的数目，数字间以空格分隔。
// 随后的 m 行中，每行给出一条快速道路的信息，分别是：城市 1、城市 2、快速道路的长度，中间用空格分开，数字均为整数且不超过 500。
// 输入保证救援可行且最优解唯一。
//
// 输出格式:
// 第一行输出最短路径的条数和能够召集的最多的救援队数量。第二行输出从 s 到 d 的路径中经过的城市编号。数字间以空格分隔，输出结尾不能有多余空格。

// Sample Input
// 4 5 0 3
// 20 30 40 10
// 0 1 1
// 1 3 2
// 0 3 3
// 0 2 2
// 2 3 2

// Sample Output
// 2 60
// 0 1 3

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to;
  int weight;
};

int main() {
  int n, m, s, d;
  cin >> n >> m >> s >> d;

  vector<int> cities(n);
  for (int i = 0; i < n; i++) {
    cin >> cities[i];
  }

  vector<deque<Edge>> G(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].push_front({v, w});
    G[v].push_front({u, w});
  }

  vector<int> dist(n, 1000);
  vector<int> prev(n, -1);
  vector<int> paths(n, 0);
  vector<int> teams(n, 0);
  vector<bool> visited(n, false);

  dist[s] = 0;
  paths[s] = 1;
  teams[s] = cities[s];

  auto cmp = [&dist](int a, int b) { return dist[a] > dist[b]; };
  priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
  pq.push(s);

  while (!pq.empty()) {
    int u = pq.top();
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;

    for (auto &[v, w] : G[u]) {
      int alt = dist[u] + w;
      if (alt < dist[v]) {
        dist[v] = alt;
        prev[v] = u;
        paths[v] = paths[u];
        teams[v] = teams[u] + cities[v];
        pq.push(v);
      } else if (alt == dist[v]) {
        paths[v] += paths[u];
        int alt = teams[u] + cities[v];
        if (alt > teams[v]) {
          prev[v] = u;
          teams[v] = alt;
        }
      }
    }
  }

  deque<int> path;
  for (int p = d; p != -1; p = prev[p]) {
    path.push_front(p);
  }

  cout << paths[d] << " " << teams[d] << endl;
  for (size_t i = 0; i < path.size(); i++) {
    cout << (i ? " " : "") << path[i];
  }

  return 0;
}
