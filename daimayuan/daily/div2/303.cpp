/**
 *    author: subobo
 *    created: 14.03.2022 21:46:49
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
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }
  int b = 0, w = 0, cb = 0, cw = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (g[i][j] == 'B') {
        ++b;
      } else
      if (g[i][j] == 'W') {
        ++w;
      }
    }
    if (b != w) {
      cout << 0 << '\n';
      return 0;
    }
  }
  b = w = 0;
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      if (g[i][j] == 'B') {
        ++b;
      } else
      if (g[i][j] == 'W') {
        ++w;
      }
    }
    if (b != w) {
      cout << 0 << '\n';
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 2 < n; j++) {
      if (g[i][j] == 'B' && g[i][j + 1] == 'B' && g[i][j + 2] == 'B' || g[i][j] == 'W' && g[i][j + 1] == 'W' && g[i][j + 2] == 'W') {
        cout << 0 << '\n';
        return 0;
      }
    }
  }
  for (int j = 0; j < n; j++) {
    for (int i = 0; i + 2 < n; i++) {
      if (g[i][j] == 'B' && g[i + 1][j] == 'B' && g[i + 2][j] == 'B' || g[i][j] == 'W' && g[i + 1][j] == 'W' && g[i + 2][j] == 'W') {
        cout << 0 << '\n';
        return 0;
      }
    }
  }
  cout << 1 << '\n';
  return 0;
}