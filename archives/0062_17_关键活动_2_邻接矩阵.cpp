// NOTE: 邻接矩阵做法
//       这样稍麻烦，因为要按照输出循序规则来输出
//       解决方法是单独把边存起来，后面输出前先按规定顺序排序
//       然后根据有序的 edges 输出
//
// 假定一个工程项目由一组子任务构成，子任务之间有的可以并行执行，有的必须在完成了其它一些子任务后才能执行。
// “任务调度”包括一组子任务、以及每个子任务可以执行所依赖的子任务集。
// 任务调度问题中，如果还给出了完成每个子任务需要的时间，则我们可以算出完成整个工程需要的最短时间。
// 在这些子任务中，有些任务即使推迟几天完成，也不会影响全局的工期；
// 但是有些任务必须准时完成，否则整个项目的工期就要因此延误，这种任务就叫“关键活动”。
// 请编写程序判定一个给定的工程项目的任务调度是否可行；如果该调度方案可行，则计算完成整个工程项目需要的最短时间，并输出所有的关键活动。
//
// 输入格式:
// 输入第1行给出两个正整数N(≤100)和M，其中N是任务交接点（即衔接相互依赖的两个子任务的节点，例如：若任务2要在任务1完成后才开始，则两任务之间必有一个交接点）的数量。
// 交接点按1N编号，M是子任务的数量，依次编号为1M。随后M行，每行给出了3个正整数，分别是该任务开始和完成涉及的交接点编号以及该任务所需的时间，整数间用空格分隔。
//
// 输出格式:
// 如果任务调度不可行，则输出0；否则第1行输出完成整个工程项目需要的时间，第2行开始输出所有关键活动，
// 每个关键活动占一行，按格式“V->W”输出，其中V和W为该任务开始和完成涉及的交接点编号。
// 关键活动输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。

// Sample Input
// 7 8
// 1 2 4
// 1 3 3
// 2 4 5
// 3 4 3
// 4 5 1
// 4 6 6
// 5 7 5
// 6 7 2

// Sample Output
// 17
// 1->2
// 2->4
// 4->6
// 6->7

#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Edge {
  int from, to, dur, i;
};

int main() {
  int Nv, Ne;
  cin >> Nv >> Ne;

  vector<vector<int>> G(Nv + 1, vector<int>(Nv + 1, 0));
  vector<int> indegree(Nv + 1, 0);
  vector<Edge> edges;

  for (int i = 0; i < Ne; i++) {
    int from, to, dur;
    cin >> from >> to >> dur;
    G[from][to] = dur;
    indegree[to]++;
    edges.push_back({from, to, dur, i});
  }

  vector<int> topo;
  vector<int> ve(Nv + 1, 0);

  stack<int> s;
  for (int i = 1; i <= Nv; i++) {
    if (!indegree[i]) {
      s.push(i);
    }
  }

  while (!s.empty()) {
    int from = s.top();
    s.pop();
    topo.push_back(from);
    for (int to = 1; to <= Nv; to++) {
      if (!G[from][to])
        continue;

      if (!--indegree[to]) {
        s.push(to);
      }
      ve[to] = max(ve[to], ve[from] + G[from][to]);
    }
  }

  if (Nv != (int)topo.size()) {
    cout << 0 << endl;
    return 0;
  }

  int max = *max_element(ve.begin(), ve.end());
  cout << max << endl;

  vector<int> vl(Nv + 1, max);

  for (int i = Nv - 1; i >= 0; i--) {
    int from = topo[i];
    for (int to = 1; to <= Nv; to++) {
      if (!G[from][to])
        continue;

      vl[from] = min(vl[from], vl[to] - G[from][to]);
    }
  }

  // NOTE: > “输出的顺序规则是：任务开始的交接点编号小者优先，起点编号相同时，与输入时任务的顺序相反。”
  sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
    if (a.from != b.from)
      return a.from < b.from;
    return a.i > b.i;
  });

  for (auto &[from, to, dur, _] : edges) {
    if (ve[from] + dur == vl[to]) {
      cout << from << "->" << to << endl;
    }
  }

  return 0;
}
