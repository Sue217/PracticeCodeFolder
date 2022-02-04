/**
 *    author: subobo
 *    created: 04.02.2022 12:52:52
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
  int ans = 0;
  function<int(int, int)> Dfs = [&](int u, int fa) {
    int dist = 0, d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
      int j = e[i];
      if (j == fa) {
        continue;
      }
      int d = Dfs(j, u) + w[i];
      dist = max(dist, d);
      if (d > d1) {
        d2 = d1;
        d1 = d;
      } else
      if (d > d2) {
        d2 = d;
      }
    }
    ans = max(ans, d1 + d2);
    return dist;
  };
  Dfs(1, 0);
  cout << ans << '\n';
  return 0;
}