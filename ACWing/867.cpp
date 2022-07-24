/**
 *    author: subobo
 *    created: 24.07.2022 15:38:24
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

void factor(int n) {
  for (int c = 2; c <= n / c; c++) {
    if (n % c == 0) {
      int cnt = 0;
      while (n % c == 0) {
        n /= c;
        cnt += 1;
      }
      cout << c << " " << cnt << '\n';
    }
  }
  if (n > 1) {
    cout << n << " " << 1 << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    factor(x);
    cout << '\n';
  }
  return 0;
}