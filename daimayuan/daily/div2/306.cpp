/**
 *    author: subobo
 *    created: 17.03.2022 21:34:08
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
  vector<long long> a(n + 1);
  const long long mod = 1000003;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(n + 1)), w(n + 1, vector<long long>(n + 1));
  auto pow = [&](long long x)->long long {
    long long ans = 1, p = 2;
    while (p > 0) {
      ans *= x;
      --p;
    }
    return ans;
  };
  for (int i = 1; i <= n; i++) {
    long long v = a[i];
    w[i][i] = v;
    for (int j = i + 1; j <= n; j++) {
      v = v * a[j] % mod;
      w[i][j] = v;
    }
  }
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len <= n; l++) {
      int r = l + len;
      for (int m = l; m < r; m++) {
        dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r] + pow(w[l][m] - w[m + 1][r]));
      }
    }
  }
  cout << dp[1][n] << '\n';
  return 0;
}