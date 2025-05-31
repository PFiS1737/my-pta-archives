// 整数数组中存储有N个整数，编写函数，找出并返回第k大的数。
// 要求时间复杂度要优于O(NlogN)。题目确保输入的K是合法的（1<=k<=N)。你可以认为k远小于N。
//
// INFO: 逃课实现，注意到所有元素均处于 0-100 之间，直接开个桶

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

#define MAX 100

int funKth(int d[], int N, int k) {
  int b[MAX + 1] = {0};

  for (int i = 0; i < N; i++)
    b[d[i]]++;

  for (int i = MAX; i >= 0; i--) {
    if (b[i] > 0) {
      k -= b[i];
      if (k <= 0)
        return i;
    }
  }

  throw;
}
