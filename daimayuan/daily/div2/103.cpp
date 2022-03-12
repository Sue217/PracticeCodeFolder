/**
 *    author: subobo
 *    created: 12.03.2022 14:48:46
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
  int n, m;
  cin >> n >> m;
  string s = "0";
  for (int i = 0; i < m; i++) {
    s += '1';
  }
  vector<bool> dp(m + 1);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = m; j >= 0; j--) {
      if (j - a >= 0) {
        dp[j - a] = 1;
      }
      if (j - b >= 0) {
        dp[j - b] = 1;
      }
    }
  }
  for (int i = 0; i <= m; i++) {
    cout << !dp[i];
  }
  cout << '\n';
  return 0;
}