/**
 *    author: subobo
 *    created: 25.03.2022 14:48:47
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
  int n, m, k;
  cin >> n >> m >> k;
  const long long mod = 1000000007;
  const int T = 1 << n;
  vector dp(m + 1, vector<vector<vector<long long>>>(T, vector<vector<long long>>(T, vector<long long>(k + 1))));
  dp[0][0][0][0] = 1;
  auto check = [&](int x, int y, int z) {
    return !(x << (3 - z) & y || y << (3 - z) & x);
  };
  for (int i = 1; i <= m; i++) {
    for (int x = 0; x < T; x++) {
      for (int y = 0; y < T; y++) {
        if (check(x, y, 1)) {
          for (int z = 0; z < T; z++) {
            if (check(x, z, 2) && check(y, z, 1)) {
              int one = __builtin_popcount(z);
              for (int t = k; t >= one; t--) {
                dp[i][y][z][t] = (dp[i][y][z][t] + dp[i - 1][x][y][t - one]) % mod;
              }
            }
          }
        }
      }
    }
  }
  long long ans = 0;
  for (int x = 0; x < T; x++) {
    for (int y = 0; y < T; y++) {
      ans = (ans + dp[m][x][y][k]) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}