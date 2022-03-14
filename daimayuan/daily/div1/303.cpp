/**
 *    author: subobo
 *    created: 14.03.2022 20:43:05
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
  vector<vector<pair<int, int>>> g(n + 1);
  int root = -1;
  vector<bool> pr(n + 1);
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
    pr[v] = true;
  }
  long long ans = 0;
  function<long long(int, int)> Dfs = [&](int v, int pv)->long long {
    long long cnt = 0, d = 0;
    for (auto p : g[v]) {
      int u = p.first;
      if (u == pv) {
        continue;
      }
      long long s = Dfs(u, v);
      ans += d * s;
      d += cnt * s;
      cnt += s;
      // debug(v, cnt, d);
    }
    if (cnt + 1 < n) {
      ans += d * (n - (cnt + 1));
    }
    return cnt + 1;
  };
  for (int i = 1; i <= n; i++) {
    if (!pr[i]) {
      root = i;
      break;
    }
  }
  Dfs(root, 0);
  cout << ans << '\n';
  return 0;
}