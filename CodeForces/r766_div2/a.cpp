/**
 *    author: subobo
 *    created: 15.01.2022 22:35:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    r--, c--;
    vector<string> g(n);
    for (int i = 0; i < n; i++) {
      cin >> g[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (g[i][j] == 'B') {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      puts("-1");
    } else
    if (g[r][c] == 'B') {
      puts("0");
    } else {
      bool nice = true;
      for (int i = 0; i < n; i++) {
        if (g[i][c] == 'B') {
          nice = false;
          puts("1");
          break;
        }
      }
      if (nice) {
        for (int i = 0; i < m; i++) {
          if (g[r][i] == 'B') {
            puts("1");
            nice = false;
            break;
          }
        }
      }
      if (nice) {
        puts("2");
      }
    }
  }
  return 0;
}