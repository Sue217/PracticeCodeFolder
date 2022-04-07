/**
 *    author: subobo
 *    created: 07.04.2022 22:25:21
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
  string in;
  cin >> in;
  string s("s");
  s += in;
  int n = (int) s.size();
  string xs(in);
  xs += 'x';
  reverse(xs.begin(), xs.end());
  vector dp(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s[i] == xs[j]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
      }
    }
  }
  cout << n - *max_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}