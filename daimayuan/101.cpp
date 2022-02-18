/**
 *    author: subobo
 *    created: 18.02.2022 12:11:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> h(n + 1, -1), e(n + 1), ne(n + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 2; i <= n; i++) {
    int fa;
    cin >> fa;
    Add(fa, i);
  }
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> size(n + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
  function<void(int)> Dfs = [&](int u) {
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      vector<int> Cap(n + 1, -(int) 2e9);
      for (int i = 0; i <= size[u]; i++) {
        for (int j = 0; j <= size[son]; j++) {
          Cap[i + j] = max(Cap[i + j], dp[u][i] + dp[son][j]);
          // dp[u][i + j] = max(dp[u][i + j], dp[u][i] + dp[son][j]);
        }
      }
      for (int it = 0; it <= size[u] + size[son]; it++) {
        dp[u][it] = Cap[it];
      }
      size[u] += size[son];
    }
    size[u] += 1;
    for (int i = size[u]; i >= 1; i--) {
      dp[u][i] = dp[u][i - 1] + a[u];
    }
  };
  Dfs(1);
  for (int i = 0; i < q; i++) {
    int u, m;
    cin >> u >> m;
    cout << dp[u][m] << '\n';
  }
  return 0;
}