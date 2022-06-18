/**
 *    author: subobo
 *    created: 18.06.2022 09:25:08
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  double diff = 1.0 / 120.0;
  for (double h = 0; h <= 360; h += diff) {
    for (double m = 0; ; m += 0.1) {
      if (m >= 360) m -= 360;
      for (double s = 0; ; s += 6) {
        if (s >= 360) s -= 360;
        if ((m - h == (s - m) * 2) && h != 0 && m != 0 && s != 0) {
          cout << h << " " << m << " " << s << '\n';
          return 0;
        }
      }
    }
  }
  return 0;
}