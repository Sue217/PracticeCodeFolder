/**
 *    author: subobo
 *    created: 21.02.2022 12:11:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int m = n - 1;
  vector<int> h(m * 2 + 1, -1), e(m * 2 + 1), ne(m * 2 + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  vector<pair<int, int>> point;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    point.emplace_back(u, v);
  }
  sort(point.begin(), point.end(), [](const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) {
      return a.second > b.second;
    }
    return a.first < b.first;
  });
  for (auto it : point) {
    Add(it.first, it.second);
  }
  vector<int> l(n + 1, 0), r(n + 1, 0), Id(n + 1, 0);
  int tot = 0;
  function<void(int)> Dfs = [&](int u) {
    l[u] = ++tot;
    Id[tot] = u;
    for (int id = h[u]; id != -1; id = ne[id]) {
      Dfs(e[id]);
    }
    r[u] = tot;
  };
  Dfs(1);
  for (int i = 1; i <= n; i++) {
    int u = Id[i];
    cout << u << ": (" << l[u] << ", " << r[u] << ") \n";
  }
  // 1(2(4,5), 3(6(7)))
  return 0;
}