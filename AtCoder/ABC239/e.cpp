/**
 *    author: subobo
 *    created: 19.02.2022 21:11:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> x(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  int m = n;
  vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), ne(m * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    Add(a, b);
    Add(b, a);
  }
  vector<vector<int>> kth(n + 1);
  function<void(int, int)> Dfs = [&](int u, int fa) {
    kth[u].emplace_back(x[u]);
    for (int id = h[u]; id != -1; id = ne[id]) {
      int son = e[id];
      if (son == fa) {
        continue;
      }
      Dfs(son, u);
      for (int v : kth[son]) {
        kth[u].emplace_back(v);
      }
    }
    sort(kth[u].begin(), kth[u].end(), [](const int a, const int b) {
      return a > b;
    });
    if (kth[u].size() > 20) {
      kth[u].resize(20);
    }
  };
  Dfs(1, 0);
  for (int i = 0; i < q; i++) {
    int v, k;
    cin >> v >> k;
    cout << kth[v][k - 1] << '\n';
  }
  return 0;
}