/**
 *    author: subobo
 *    created: 08.02.2022 11:36:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = n - 1;
  vector<int> h(m + 4, -1), e(m + 4), ne(m + 4);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<int> w(n + 1);
  vector<bool> has_father(n + 1);
  for (int i = 1; i <= n; i++) {
    int tot, from;
    cin >> from >> w[from] >> tot;
    for (int j = 0; j < tot; j++) {
      int to;
      cin >> to;
      Add(from, to);
      has_father[to] = true;
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(3, 0));
  function<void(int)> Dfs = [&](int u) {
    dp[u][2] = w[u];
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      Dfs(son);
      dp[u][0] += min(dp[son][1], dp[son][2]);
      dp[u][2] += min({dp[son][0], dp[son][1], dp[son][2]});
    }
    dp[u][1] = (int) 2e9;
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      dp[u][1] = min(dp[u][1], dp[son][2] + (dp[u][0] - min(dp[son][1], dp[son][2])));
    }
  };
  int root = -1;
  for (int id = 1; id <= n; id++) {
    if (!has_father[id]) {
      root = id;
    }
  }
  Dfs(root);
  cout << min(dp[root][1], dp[root][2]) << '\n';
  return 0;
}