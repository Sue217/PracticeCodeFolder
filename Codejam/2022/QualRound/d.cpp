/**
 *    author: subobo
 *    created: 03.04.2022 13:45:13
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
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++) {
      int p;
      cin >> p;
      g[p].push_back(i);
    }
    long long ans = 0;
    const long long inf = (long long) 2e18;
    function<long long(int)> Dfs = [&](int v)->long long {
      long long mn = inf;
      for (int u : g[v]) {
        long long x = Dfs(u);
        if (mn > x) {
          mn = x;
        }
        ans += x;
      }
      if (mn == inf) {
        mn = 0;
      } else {
        ans -= mn;
      }
      return max(mn, a[v]);
    };
    ans += Dfs(0);
    cout << "Case #" << qq << ": " << ans << '\n';
  }
  return 0;
}