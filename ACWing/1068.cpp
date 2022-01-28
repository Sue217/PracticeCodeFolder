/**
 *    author: subobo
 *    created: 28.01.2022 11:32:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> seq(n + 1), presum(n * 2 + 1);
  for (int i = 1; i <= n; i++) {
    cin >> seq[i];
    presum[i] = presum[i - 1] + seq[i];
  }
  for (int i = 1, j = n + 1; i <= n; i++, j++) {
    presum[j] = presum[j - 1] + seq[i];
  }
  vector<vector<int>> f(n * 2 + 1, vector<int>(n * 2 + 1)), g(n * 2 + 1, vector<int>(n * 2 + 1));
  constexpr int inf = (int) 2e9;
  for (int len = 2; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n * 2; l++) {
      int r = l + len - 1;
      f[l][r] = inf;
      int last = presum[r] - presum[l - 1];
      for (int m = l; m < r; m++) {
        f[l][r] = min(f[l][r], f[l][m] + f[m + 1][r] + last);
        g[l][r] = max(g[l][r], g[l][m] + g[m + 1][r] + last);
      }
    }
  }
  int ma = 0, mi = inf;
  for (int i = 1; i <= n; i++) {
    int j = i + n - 1;
    mi = min(mi, f[i][j]);
    ma = max(ma, g[i][j]);
  }
  cout << mi << '\n';
  cout << ma << '\n';
  return 0;
}