/**
 *    author: subobo
 *    created: 13.03.2022 20:00:17
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> g(n + 1);
  vector<bool> enter(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      g[i].push_back(v);
      enter[v] = true;
    }
  }
  queue<int> q;
  vector<bool> vis(n + 1);
  for (int i = 1; i <= n; i++) {
    if (!enter[i]) {
      q.push(i);
      vis[i] = true;
      break;
    }
  }
  int ans = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    ans = v;
    for (int u : g[v]) {
      if (!vis[u]) {
        vis[u] = true;
        q.push(u);
      }
    }
  }
  cout << ans << '\n';
  return 0;
}