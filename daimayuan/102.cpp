/**
 *    author: subobo
 *    created: 18.02.2022 14:23:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> h(n + 1, -1), e(n * 2 + 1), ne(n * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int id = 2; id <= n; id++) {
    int fa;
    cin >> fa;
    Add(fa, id);
  }
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  static constexpr int M = 101;
  vector<int> size(n + 1, 0);
  vector<vector<int>> dp(n + 1, vector<int>(M + 1, 0));
  function<void(int)> Dfs = [&](int u) {
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      vector<int> Cap(M + 1, -(int) 2e9);
      for (int i = 0; i <= size[u] && i <= M; i++) {
        for (int j = 0; j <= size[son] && i + j <= M; j++) {
          Cap[i + j] = max(Cap[i + j], dp[u][i] + dp[son][j]);
        }
      }
      for (int it = 0; it <= size[u] + size[son] && it <= M; it++) {
        dp[u][it] = Cap[it];
      }
      size[u] += size[son];
    }
    size[u] += 1;
    for (int i = min(size[u], M); i >= 1; i--) {
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