/**
 *    author: subobo
 *    created: 30.03.2022 23:05:20
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int x;
      cin >> x;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + x);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + x);
    }
  }
  cout << *max_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}