/**
 *    author: subobo
 *    created: 11.02.2022 14:17:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, t;
  cin >> n >> t;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int get = (int) 2e9, left = 0, right = n;
  while (left < right) {
    int m = (left + right + 1) / 2;
    deque<int> mono(1, 0);
    vector<int> dp(n + 1, 0);
    for (int it = 1; it <= n; it++) {
      if (mono.front() < it - m) {
        mono.pop_front();
      }
      dp[it] = dp[mono.front()] + a[it];
      while (!mono.empty() && dp[mono.back()] >= dp[it]) {
        mono.pop_back();
      }
      mono.push_back(it);
    }
    int get = (int) 2e9;
    for (int i = n - m + 1; i <= n; i++) {
      get = min(get, dp[i]);
    }
    if (get > t) {
      left = m;
    } else {
      right = m - 1;
    }
  }
  cout << left << '\n';
  return 0;
}