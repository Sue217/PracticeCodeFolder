/**
 *    author:  tourist
 *    created: 14.05.2022 19:05:17       
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
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    long long R;
    cin >> R;
    long long ans = 0;
    for (long long x = 1; x <= R; x++) {
      long long low = 0, high = R;
      while (low < high) {
        long long y = (low + high + 1) >> 1;
        long long d = llround(sqrt(x * x + y * y));
        if (d <= R) {
          low = y;
        } else {
          high = y - 1;
        }
      }
      ans += 4 * (low + 1);
    }
    for (long long r = 1; r <= R; r++) {
      long long low = 0, high = r;
      while (low < high) {
        long long x = (low + high + 1) >> 1;
        long long y = llround(sqrt(r * r - x * x));
        if (x <= y) {
          low = x;
        } else {
          high = x - 1;
        }
      }
      long long x = low;
      long long y = llround(sqrt(r * r - x * x));
      long long cc2 = 2 * x + (x < y);
      ans -= 4 * cc2;
    }
    cout << ans << '\n';
  }
  return 0;
}
