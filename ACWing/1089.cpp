/**
 *    author: subobo
 *    created: 11.02.2022 11:55:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
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
  int ans = (int) 2e9;
  for (int i = n - m + 1; i <= n; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
  return 0;
}