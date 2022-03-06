/**
 *    author: subobo
 *    created: 06.03.2022 10:56:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  constexpr int mod = 998244353;
  vector dp(n + 1, vector<int>(10));
  for (int i = 1; i <= 9; i++) {
    dp[1][i] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 9; j++) {
      for (int k = max(1, j - 1); k <= min(9, j + 1); k++) {
        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 9; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << '\n';
  return 0;
}