/**
 *    author: subobo
 *    created: 02.04.2022 20:08:24
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
    int r, c;
    cin >> r >> c;
    r = 2 * r + 1;
    c = 2 * c + 1;
    cout << "Case #" << qq << ":" << '\n';
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i == 0 && (j == 0 || j == 1) || i == 1 && (j == 0 || j == 1)) {
          cout << ".";
          continue;
        }
        if (i % 2 == 0) {
          if (j % 2 == 0) {
            cout << "+";
          } else {
            cout << "-";
          }
        } else {
          if (j % 2 == 0) {
            cout << "|";
          } else {
            cout << ".";
          }
        }
      }
      cout << '\n';
    }
  }
  return 0;
}