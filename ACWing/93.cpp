/**
 *    author: subobo
 *    created: 03.02.2022 14:24:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(m + 1);
  function<void(int, int)> Dfs = [&](int start, int u) {
    if (u + n - start < m) {
      return;
    }
    if (u > m) {
      for (int i = 1; i <= m; i++) {
        cout << a[i] << " ";
      }
      cout << '\n';
      return;
    }
    for (int i = start; i <= n; i++) {
      a[u] = i;
      Dfs(i + 1, u + 1);
    }
  };
  Dfs(1, 1);
  return 0;
}