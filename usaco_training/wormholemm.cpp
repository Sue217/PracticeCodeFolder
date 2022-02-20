/**
 *    author: subobo
 *    created: 19.02.2022 23:24:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> point;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    point.emplace_back(x, y);
  }
  sort(point.begin(), point.end(), [](const pair<int, int> a, const pair<int, int> b) {
    if (a.second == b.second) {
      return a.first < b.first;
    }
    return a.second < b.second;
  });
  vector<vector<bool>> used(n + 1, vector<bool>(2, false)), in_vis(n + 1, vector<bool>(2, false));
  vector<int> in(n + 1, -1), out(n + 1, -1);
  // bitset<n + 1> vis;
  vector<bool> vis(n + 1, false);
  int ans = 0;
  for (int i = 1; i < n ;i++) {
    if (point[i - 1].first == point[i].first) {
      out[i - 1] = i;
    }
  }
  function<bool(int, int)> has_loop = [&](int u, int st) {
    if (in_vis[u][st]) {
      return true; // has a loop
    }
    if (used[u][st]) {
      return false; // do not have a loop
    }
    in_vis[u][st] = true; // push stack
    used[u][st] = true;
    bool has = false;
    if (st == 0) {
      // is `in`
      if (has_loop(in[u], 1 - st)) {
        has = true;
      }
    } else {
      // is 'out'
      if (out[u] != -1 && has_loop(out[u], 1 - st)) {
        has = true;
      }
    }
    in_vis[u][st] = false; // pop stack
    return has;
  };
  function<bool()> check = [&]() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 2; j++) {
        if (!used[i][j] && has_loop(i, j)) {
          return true;
        }
      }
    }
    return false;
  };
  function<void(int)> Dfs = [&](int u) {
    if (u == n / 2) {
      if (check()) {
        ans += 1;
      }
      return;
    }
    for (int i = 0; i < n; i++) {
      if (!vis[i]) {
        for (int j = i + 1; j < n; j++) {
          if (!vis[j]) {
            vis[i] = vis[j] = true;
            in[i] = j; in[j] = i;
            Dfs(u + 1);
            vis[i] = vis[j] = false;
            in[i] = in[j] = -1;
          }
        }
        break;
      }
    }
  };
  Dfs(0);
  cout << ans << '\n';
  return 0;
}