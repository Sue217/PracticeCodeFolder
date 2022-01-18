/**
 *    author: subobo
 *    created: 18.01.2022 11:23:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> h(m + 1, -1), e(m + 1), ne(m + 1);
  int idx = 0;
  auto Add = [&](int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
  };
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    Add(u, v);
  }
  int A, B;
  cin >> A >> B;
  bool ok = true;
  vector<bool> vis(n + 1);
  vector<int> rem(n + 1, -1);
  function<int(int)> Dfs = [&](int u) -> int {
    if (u == B) {
      return 1;
    }
    if (rem[u] != -1) {
      return rem[u];
    }
    vis[u] = true;
    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i]) {
      int j = e[i];
      if (!vis[j]) {
        cnt += Dfs(j);
      }
    }
    vis[u] = false;
    if (cnt == 0) {
      ok = false;
    }
    return rem[u] = cnt;
  };
  int ans = Dfs(A);
  cout << ans << " ";
  puts(ok ? "Yes" : "No");
  return 0;
}