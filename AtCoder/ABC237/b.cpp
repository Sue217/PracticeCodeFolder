/**
 *    author: subobo
 *    created: 30.01.2022 20:05:46
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m)), ans(m, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> g[i][j];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      ans[i][j] = g[j][i];
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}