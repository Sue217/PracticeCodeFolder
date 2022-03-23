/**
 *    author: subobo
 *    created: 23.03.2022 20:51:20
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> dp(n + 1, -(int) 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      int s = 0;
      for (int j = i; j < n; j++) {
        s += a[j];
        dp[j - i + 1] = max(dp[j - i + 1], s);
      }
    }
    for (int k = 0; k <= n; k++) {
      int ans = 0;
      for (int t = 0; t <= n; t++) {
        ans = max(ans, dp[t] + min(t, k) * x);
      }
      cout << ans << " \n"[k == n];
    }
  }
  return 0;
}