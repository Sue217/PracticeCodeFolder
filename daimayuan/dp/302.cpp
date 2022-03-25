/**
 *    author: subobo
 *    created: 24.03.2022 22:12:37
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b;
    b.push_back(a[0]);
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i - 1]) {
        b.push_back(a[i]);
      }
    }
    vector<int> pos(n + 1, n + 1), next(n + 1, n + 1);
    n = (int) b.size();
    for (int i = n - 1; i >= 0; i--) {
      next[i] = pos[b[i]];
      pos[b[i]] = i;
    }
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 1; len < n; len++) {
      for (int l = 0; l + len < n; l++) {
        int r = l + len;
        dp[l][r] = dp[l + 1][r];
        int m = next[l];
        while (m <= r) {
          dp[l][r] = max(dp[l][r], dp[l + 1][m - 1] + dp[m][r] + 1);
          m = next[m];
        }
      }
    }
    cout << n - dp[0][n - 1] - 1 << '\n';
  }
  return 0;
}