/**
 *    author: subobo
 *    created: 02.04.2022 08:47:56
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
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    cin >> n;
    vector<long long> f(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> f[i];
    }
    vector<long long> p(n + 1);
    vector<long long> last(n + 1);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      g[p[i]].push_back(i);
      last[p[i]] += 1;
    }
    queue<int> s;
    for (int d = 0; d <= n; d++) {
      if (last[d] == 0) {
        s.push(d);
      }
    }
    const long long inf = (long long) 2e18;
    vector<long long> dp(n + 1);
    int pt = -1;
    long long ans = 0;
    while (!s.empty()) {
      int u = s.front();
      s.pop();
      long long mn = inf;
      for (int v : g[u]) {
        if (dp[v] < mn) {
          mn = dp[v];
          pt = v;
        }
      }
      if (mn == inf) {
        mn = 0;
      }
      for (int v : g[u]) {
        if (v != pt) {
          ans += dp[v];
        }
      }
      dp[u] = max(f[u], mn);
      last[p[u]] -= 1;
      if (last[p[u]] == 0) {
        s.push(p[u]);
      }
    }
    cout << "Case #" << qq << ": ";
    cout << ans + dp[0] << '\n';
  }
  return 0;
}