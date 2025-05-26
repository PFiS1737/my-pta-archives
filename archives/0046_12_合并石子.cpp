// 现在有n堆石子，我们要把它们合并成一堆。
// 每一次合并，可以把两堆石子（可以不相邻）合并到一起，消耗的体力等于两堆石子的重量之和。
// 显然，所有的石子经过 n−1 次合并之后，就只剩下一堆了。
//
// 在合并石子时总共消耗的体力等于每次合并所耗体力之和。
// 我们希望在合并石子时要尽可能地节省体力。
// 假定每个石子重量都为1，并且已知石子的堆数和每堆石子的数目，求最少所消耗的体力。
//
// 输入格式：
// 第一行是一个整数 n(1≤n≤100000) ，表示石子的堆数。
// 第二行包含 n 个整数，用空格分隔，第 i 个整数 ai(0≤ai≤100000) 是第 i 堆石子的数目。
//
// 输出格式：
// 一个整数，也就是最小的体力耗费值。

// Sample Input
// 3
// 1 2 3

// Sample Output
// 9

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define ll long long

int main() {
  int n;
  cin >> n;

  priority_queue<ll, vector<ll>, greater<ll>> heap;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    heap.push(x);
  }

  ll cost = 0;

  while (heap.size() > 1) {
    ll a = heap.top();
    heap.pop();
    ll b = heap.top();
    heap.pop();

    ll merged = a + b;
    heap.push(merged);

    cost += merged;
  }

  cout << cost << endl;

  return 0;
}
