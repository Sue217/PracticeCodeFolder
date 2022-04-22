/**
 *    author: subobo
 *    created: 21.04.2022 23:55:35
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
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == '*') {
          int x = i;
          for (int k = i + 1; k < n; k++) {
            if (g[k][j] == '.') {
              x = k;
            } else {
              break;
            }
          }
          swap(g[x][j], g[i][j]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      cout << g[i] << '\n';
    }
  }
  return 0;
}