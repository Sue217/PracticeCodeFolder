/**
 *    author: subobo
 *    created: 24.03.2022 13:51:23
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
  const int N = 1000;
  const int inf = (int) 1e9;
  vector<int> d(N + 1, inf);
  d[1] = 0;
  for (int i = 1; i <= N; i++) {
    for (int x = 1; x <= i; x++) {
      int v = i + i / x;
      if (v <= N) {
        d[v] = min(d[v], d[i] + 1);
      }
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      b[i] = d[b[i]];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    int s = accumulate(b.begin(), b.end(), 0);
    k = min(k, s);
    vector<int> dp(k + 1);
    for (int i = 0; i < n; i++) {
      for (int j = k; j >= b[i]; j--) {
        dp[j] = max(dp[j], dp[j - b[i]] + c[i]);
      }
    }
    cout << dp[k] << '\n';
  }
  return 0;
}