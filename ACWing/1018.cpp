/**
 *    author: subobo
 *    created: 06.02.2022 10:44:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1, vector<int>(n + 1)), f(n + 1, vector<int>(n + 1, (int) 2e9));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> g[i][j];
    }
  }
  f[1][1] = g[1][1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + g[i][j]);
    }
  }
  cout << f[n][n] << '\n';
  return 0;
}