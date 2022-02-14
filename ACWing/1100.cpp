/**
 *    author: subobo
 *    created: 14.02.2022 15:20:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  if (n >= k) {
    cout << n - k << '\n';
    return 0;
  }
  vector<int> step(k * 2 + 1, -1);
  queue<int> q;
  q.push(n);
  step[n] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x - 1 >= 0 && step[x - 1] == -1) {
      step[x - 1] = step[x] + 1;
      q.push(x - 1);
    }
    if (x + 1 <= k * 2 && step[x + 1] == -1) {
      step[x + 1] = step[x] + 1;
      q.push(x + 1);
    }
    if (x * 2 <= k * 2 && step[x * 2] == -1) {
      step[x * 2] = step[x] + 1;
      q.push(x * 2);
    }
  }
  cout << step[k] << '\n';
  return 0;
}