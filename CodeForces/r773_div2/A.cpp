/**
 *    author: subobo
 *    created: 23.02.2022 18:11:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    array<double, 3> x, y;
    bool ok = true;
    for (int i = 0; i < 3; i++) {
      cin >> x[i] >> y[i];
    }
    double ans = 0.0;
    if (y[0] == y[1]) {
      if (y[0] == 0) {
        ans = 0;
      } else
      if (y[0] > y[2]) {
        ans = abs(x[0] - x[1]);
      } else {
        ans = 0;
      }
    } else
    if (y[1] == y[2]) {
      if (y[1] == 0) {
        ans = 0;
      } else
      if (y[1] > y[0]) {
        ans = abs(x[1] - x[2]);
      } else {
        ans = 0;
      }
    } else
    if (y[0] == y[2]) {
      if (y[0] == 0) {
        ans = 0;
      } else
      if (y[0] > y[1]) {
        ans = abs(x[0] - x[2]);
      } else {
        ans = 0;
      }
    }
    cout << fixed << setprecision(9) << ans << '\n';
  }
  return 0;
}