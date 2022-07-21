/**
 *    author: subobo
 *    created: 19.07.2022 15:24:50
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
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  int tt = 20000;
  cout << tt << '\n';
  while (tt--) {
    int n = rng() % 1000;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << rng() % 10 << " \n"[i == n - 1];
    }
  }
  return 0;
}