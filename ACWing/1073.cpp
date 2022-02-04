/**
 *    author: subobo
 *    created: 04.02.2022 13:16:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
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
  constexpr int inf = (int) 2e9;
  vector<int> d1(n + 1, -inf), d2(n + 1, -inf), p(n + 1, 0), up(n + 1, 0);
  function<int(int, int)> dfs_down = [&](int u, int fa) {
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == fa) {
        continue;
      }
      int dist = dfs_down(j, u) + w[i];
      if (dist > d1[u]) {
        d2[u] = d1[u];
        d1[u] = dist;
        p[u] = j;
      } else
      if (dist > d2[u]) {
        d2[u] = dist;
      }
    }
    if (d1[u] == -inf) {
      d1[u] = d2[u] = 0;
    }
    return d1[u];
  };
  function<void(int, int)> dfs_up = [&](int u, int fa) {
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == fa) {
        continue;
      }
      if (p[u] == j) {
        up[j] = max(up[u], d2[u]) + w[i];
      } else {
        up[j] = max(up[u], d1[u]) + w[i];
      }
      dfs_up(j, u);
    }
  };
  dfs_down(1, 0);
  dfs_up(1, 0);
  int ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, max(d1[i], up[i]));
  }
  cout << ans << '\n';
  return 0;
}