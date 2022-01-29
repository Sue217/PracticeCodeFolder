/**
 *    author: subobo
 *    created: 29.01.2022 19:29:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  int x, y;
  cin >> n >> s >> x >> y;
  char opx, opy;
  if (x < 0) {
    opx = 'L';
  } else
  if (x > 0) {
    opx = 'R';
  } else {
    opx = 0;
  }
  if (y < 0) {
    opy = 'D';
  } else
  if (y > 0) {
    opy = 'U';
  } else {
    opy = 0;
  }
  x = abs(x); y = abs(y);
  int sum = x + y;
  if (n < sum) {
    puts("-1");
    return 0;
  }
  if (sum % 2 != n % 2) {
    puts("-1");
    return 0;
  }
  constexpr int inf = (int) 2e9;
  int ma = -1, mi = inf;
  for (int i = 0; i < n; i++) {
    if (sum == 0) {
      break;
    }
    if (s[i] == opx && x > 0) {
      x -= 1;
    } else
    if (s[i] == opy && y > 0) {
      y -= 1;
    } else {
      ma = max(ma, i);
      mi = min(mi, i);
    }
    sum -= 1;
  }
  if (ma == -1 && mi == inf) {
    puts("0");
  } else {
    cout << ma - mi + 1 << '\n';
  }
  return 0;
}