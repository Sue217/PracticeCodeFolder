/**
 *    author: subobo
 *    created: 03.02.2022 20:24:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  array<int, 5> dx{-1, 0, 0, 1, 0}, dy{0, -1, 0, 0, 1};
  int tt;
  cin >> tt;
  while (tt--) {
    vector<string> g(5);
    for (int i = 0; i < 5; i++) {
      cin >> g[i];
    }
    int ans = 7;
    for (int i = 0; i < 32; i++) {
      auto backup = g;
      auto Switch = [&](int x, int y) {
        for (int i = 0; i < 5; i++) {
          int xx = x + dx[i];
          int yy = y + dy[i];
          if (xx >= 0 && xx < 5 && yy >= 0 && yy < 5) {
            backup[xx][yy] ^= 1;
          }
        }
      };
      int cnt = 0;
      for (int it = 0; it < 5; it++) {
        if ((i >> it) & 1) {
          Switch(0, it);
          cnt += 1;
        }
      }
      for (int j = 1; j < 5; j++) {
        for (int k = 0; k < 5; k++) {
          if (backup[j - 1][k] == '0') {
            Switch(j, k);
            cnt += 1;
          }
        }
      }
      bool ok = true;
      for (int it = 0; it < 5; it++) {
        if (backup[4][it] == '0') {
          ok = false;
        }
      }
      if (ok) {
        ans = min(ans, cnt);
      }
    }
    if (ans > 6) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}