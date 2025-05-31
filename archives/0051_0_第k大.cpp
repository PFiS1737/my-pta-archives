// 整数数组中存储有N个整数，编写函数，找出并返回第k大的数。
// 要求时间复杂度要优于O(NlogN)。题目确保输入的K是合法的（1<=k<=N)。你可以认为k远小于N。
//
// INFO: 标准库优先队列实现

// Sample Input
// 100 30

// Sample Output
// 74

// Prepend Code Start
#include <iostream>
using namespace std;

int funKth(int d[], int N, int k);

int main() {
  int N, k;
  cin >> N >> k;

  int d[N];
  srand(2025530);
  for (int i = 0; i < N; i++) {
    d[i] = rand() % 101;
  }

  cout << funKth(d, N, k) << endl;

  return 0;
}
// Prepend Code End

#include <queue>

int funKth(int d[], int N, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < k; i++) {
    pq.push(d[i]);
  }

  for (int i = k; i < N; i++) {
    if (d[i] > pq.top()) {
      pq.pop();
      pq.push(d[i]);
    }
  }

  return pq.top();
}
