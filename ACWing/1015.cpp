/**
 *    author: subobo
 *    created: 06.02.2022 09:47:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(m + 1)), f(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> g[i][j];
      }
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j] = max(f[i - 1][j], f[i][j - 1]) + g[i][j];
      }
    }
    cout << f[n][m] << '\n';
  }
  return 0;
}