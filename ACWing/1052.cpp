/**
 *    author: subobo
 *    created: 17.01.2022 22:29:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  int m = (int)s.size();
  vector<int> ne(m + 1);
  for (int i = 1, j = 0; i < m; i++) {
    while (j && s[i] != s[j]) {
      j = ne[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    ne[i] = j;
  }
  constexpr int mod = (int)1e9 + 7;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      for (char c = 'a'; c <= 'z'; c++) {
        int p = j;
        while (p && c != s[p]) {
          p = ne[p - 1];
        }
        if (c == s[p]) {
          p++;
        }
        if (p < m) {
          dp[i][p] = (dp[i][p] + dp[i - 1][j]) % mod;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans = (ans + dp[n][i]) % mod;
  }
  cout << ans << '\n';
  return 0;
}
