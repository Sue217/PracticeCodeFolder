/**
 *    author: subobo
 *    created: 27.02.2022 09:44:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> h(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  vector<vector<int>> g(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int root = (int) (max_element(h.begin(), h.end()) - h.begin());
  long long ans = 0;
  function<int(int, int)> Dfs = [&](int u, int fa) {
    vector<int> got;
    for (int v : g[u]) {
      if (v == fa) {
        continue;
      }
      got.push_back(Dfs(v, u));
    }
    // leaf
    if (got.empty()) {
      ans += h[u];
      return h[u];
    }
    // root && multiple sons
    if (u == root && got.size() > 1) {
      int& m1 = *max_element(got.begin(), got.end());
      ans += h[u] - m1;
      m1 = -1;
      int& m2 = *max_element(got.begin(), got.end());
      ans += h[u] - m2;
      m2 = -1;
      return h[u];
    }
    // root alone or only has one son
    if (u == root) {
      ans += h[u];
      //! return h[u];
    }
    // previous case && neither root nor leaf
    int max_son = *max_element(got.begin(), got.end());
    if (max_son >= h[u]) {
      return max_son;
    } else {
      ans += h[u] - max_son;
      return h[u];
    }
  };
  Dfs(root, 0);
  cout << ans << '\n';
  return 0;
}