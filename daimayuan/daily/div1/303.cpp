/**
 *    author: subobo
 *    created: 15.03.2022 09:11:05
**/
#include <bits/stdc++.h>

using namespace std;

#define LOCAL

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << H;
  debug_out(T...);
}

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
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  long long ans = 0;
  function<long long(int, int)> Dfs = [&](int v, int pv)->long long {
    long long x = 0, y = 0;
    for (int u : g[v]) {
      if (u == pv) {
        continue;
      }
      long long z = Dfs(u, v);
      ans += y * z;
      y += x * z;
      x += z;
    }
    if (x + 1 < n) {
      ans += y * (n - x - 1);
    }
    // debug(v, x, y, ans);
    return x + 1;
  };
  Dfs(1, 0);
  cout << ans << '\n';
  return 0;
}