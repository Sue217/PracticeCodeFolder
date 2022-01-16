/**
 *    author: subobo
 *    created: 16.01.2022 09:30:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> check(n + 1);
    vector<int> h(n * 2 + 3, -1), e(n * 2 + 3), ne(n * 2 + 3);
    int idx = 0;
    auto Add = [&](int a, int b) {
      e[idx] = b;
      ne[idx] = h[a];
      h[a] = idx++;
    };
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      check[u]++; check[v]++;
      Add(u, v); Add(v, u);
    }
    if (*max_element(check.begin(), check.end()) > 2) {
      cout << -1 << '\n';
      continue;
    }
    vector<pair<int, int>> ans;
    function<void(int, int, int)> Dfs = [&](int u, int fa, int times) {
      for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j != fa) {
          ans.emplace_back(i, times);
          Dfs(j, u, times ^ 1);
        }
      }
    };
    int head = 0;
    for (int i = 1; i < n; i++) {
      if (check[i] == 1) {
        head = i;
        break;
      }
    }
    Dfs(head, -1, 2);
    sort(ans.begin(), ans.end());
    for (auto it : ans) {
      cout << it.second << " ";
    }
    cout << '\n';
  }
  return 0;
}