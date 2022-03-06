/**
 *    author: subobo
 *    created: 06.03.2022 10:46:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double a, b, c, x;
  cin >> a >> b >> c >> x;
  double ans = c / (b - a);
  if (x <= a) {
    ans = 1;
  }
  if (x > b) {
    ans = 0;
  }
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}