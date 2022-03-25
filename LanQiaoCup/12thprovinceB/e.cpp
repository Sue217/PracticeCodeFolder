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
  array<int, 8> dx{-2, -2, -1, -1, 1, 1, 2, 2}, dy{-1, 1, -2, 2, -2, 2, -1, 1};
  vector<vector<int>> hack(n, vector<int>(m));
  function<long long(int, int, int)> Dfs = [&](int x, int y, int z)->long long {
    if (z == k) {
      return 1;
    }
    long long ans = 0;
    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];
      if (xx >= 0 && xx < n && yy >= 0 && yy < m && !hack[xx][yy]) {
        hack[xx][yy] = true;
        ans = (ans + Dfs(xx, yy, z + 1)) % mod;
        hack[xx][yy] = false;
      }
    }
    return ans;
  };
  int N = n * m;
  vector<vector<long long>> C(N + 1, vector<long long>(k + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= k; j++) {
      if (i == j) {
        C[i][j] = 1;
        continue;
      }
      if (j == 1) {
        C[i][j] = i;
        continue;
      }
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }
  C[N][k] %= mod;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans = (ans + Dfs(i, j, 1)) % mod;
    }
  }
  cout << ans << '\n';
  return 0;
}