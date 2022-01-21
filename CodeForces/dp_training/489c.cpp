/**
 *    author: subobo
 *    created: 21.01.2022 09:54:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, s;
  cin >> m >> s;
  if (s > 9 * m or s == 0 and m != 1) {
    cout << "-1 -1" << '\n';
    return 0;
  }
  int t = s;
  for (int i = m - 1; i >= 0; i--) {
    int x = t - 9 * i;
    if (x < 0) {
      if (i == m - 1) {
        x = 1;
      } else {
        x = 0;
      }
    }
    cout << x;
    t -= x;
  }
  cout << " ";
  for (int i = 0; i < m; i++) {
    int x = s;
    if (x > 9) {
      x = 9;
    }
    s -= x;
    cout << x;
  }
  return 0;
}