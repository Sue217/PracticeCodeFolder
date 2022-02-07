/**
 *    author: subobo
 *    created: 16.01.2022 13:23:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<int> w(n + 1), v(n + 1);
  int root = -1;
  for (int i = 1; i <= n; i++) {
    int id;
    cin >> v[i] >> w[i] >> id;
    if (id == -1) {
      root = i;
    } else {
      Add(id, i);
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  function<void(int)> Dfs = [&](int u) {
    for (int i = v[u]; i <= m; i++) {
      dp[u][i] = w[u];
    }
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      for (int i = m; i >= v[u]; i--) {
        for (int j = 0; j <= i - v[u]; j++) {
          dp[u][i] = max(dp[u][i], dp[u][i - j] + dp[son][j]);
        }
      }
    }
  };
  Dfs(root);
  cout << dp[root][m] << '\n';
  return 0;
}
