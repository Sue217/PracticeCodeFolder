/**
 *    author: subobo
 *    created: 29.01.2022 21:19:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  string s = "0", xs;
  cin >> n >> xs >> x >> y;
  s += xs;
  if (abs(x) + abs(y) > n || (x + y - n) % 2 != 0) {
    puts("-1");
    return 0;
  }
  vector<int> psx(n + 1), psy(n + 1);
  for (int i = 1; i <= n; i++) {
    psx[i] = psx[i - 1];
    psy[i] = psy[i - 1];
    if (s[i] == 'U') {
      psy[i] += 1;
    } else
    if (s[i] == 'D') {
      psy[i] -= 1;
    } else
    if (s[i] == 'R') {
      psx[i] += 1;
    } else
    if (s[i] == 'L') {
      psx[i] -= 1;
    }
  }
  auto check = [&](int md) {
    for (int i = 1; i + md - 1 <= n; i++) {
      int j = i + md - 1;
      int xx = psx[n] - (psx[j] - psx[i - 1]);
      int yy = psy[n] - (psy[j] - psy[i - 1]);
      int d = abs(x - xx) + abs(y - yy);
      if (d <= md && (d - md) % 2 == 0) {
        return true;
      }
    }
    return false;
  };
  int l = 0, r = n;
  while (l < r) {
    int md = (l + r) >> 1;
    if (check(md)) {
      r = md;
    } else {
      l = md + 1;
    }
  }
  cout << r << '\n';
  return 0;
}