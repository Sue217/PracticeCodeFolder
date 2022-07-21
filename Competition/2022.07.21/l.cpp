/**
 *    author: subobo
 *    created: 21.07.2022 12:24:44
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
  while (tt--) {
    long long n;
    cin >> n;
    long long ans = 0;
    if (n >= 79205LL) {
      ans += n / 79205LL * 217LL;
      n %= 79205LL;
    }
    if (n >= 11315LL) {
      ans += n / 11315LL * 31LL;
      n %= 11315LL;
    }
    if (n >= 2555LL) {
      ans += n / 2555LL * 7;
      n %= 2555LL;
    }
    if (n >= 365LL) {
      ans += n / 365LL;
      n %= 365LL;
    }
    if (n >= 217LL) {
      ans += n / 217LL * 7;
      n %= 217LL;
    }
    bool ok = true;
    for (long long i = 0; i < 31; i++) {
      for (long long j = 0; j < 7; j++) {
        if (i * 7LL + j * 31LL == n) {
          ans += i + j;
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? -1 : ans) << '\n';
  }
  return 0;
}