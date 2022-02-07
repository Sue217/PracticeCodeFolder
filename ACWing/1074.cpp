/**
 *    author: subobo
 *    created: 07.02.2022 22:04:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  int m = n - 1;
  vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), w(m * 2 + 1), ne(m * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b, int c) {
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    Add(u, v, w);
    Add(v, u, w);
  }
  vector<vector<int>> dp(n + 1, vector<int>(q + 1, 0));
  function<void(int, int)> Dfs = [&](int u, int fa) {
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      if (son == fa) {
        continue;
      }
      Dfs(son, u);
      for (int i = q; i >= 0; i--) {
        for (int j = 0; j <= i - 1; j++) {
          dp[u][i] = max(dp[u][i], dp[u][i - j - 1] + dp[son][j] + w[id]);
        }
      }
    }
  };
  Dfs(1, 0);
  cout << dp[1][q] << '\n';
  return 0;
}