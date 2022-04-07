/**
 *    author: subobo
 *    created: 07.04.2022 23:34:15
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
  while (tt--) {
    int n, m;
    cin >> n >> m;
    function<int(int, int)> Dfs = [&](int x, int y) {
      if (x == 0) {
        return 1;
      }
      if (y == 0) {
        return 0;
      }
      if (x < y) {
        return Dfs(x, x);
      }
      return Dfs(x - y, y) + Dfs(x, y - 1);
    };
    int ans = Dfs(n, m);
    cout << ans << '\n';
  }
  return 0;
}