/**
 *    author: subobo
 *    created: 16.01.2022 14:55:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> f(m + 1), g(m + 1, 1);
  constexpr int mod = (int)1e9 + 7;
  for (int i = 1; i <= n; i++) {
    int v, w;
    cin >> v >> w;
    for (int j = m; j >= v; j--) {
      int val = f[j - v] + w;
      if (val > f[j]) {
        f[j] = val;
        g[j] = g[j - v];
      } else
      if (val == f[j]) {
        g[j] = (g[j] + g[j - v]) % mod;
      }
    }
  }
  cout << g[m] << '\n';
  return 0;
}
