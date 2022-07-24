/**
 *    author: subobo
 *    created: 24.07.2022 15:19:14
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

bool isprime(long long n) {
  if (n < 2) return false;
  for (long long c = 2; c <= n / c; c++) {
    if (n % c == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long x;
    cin >> x;
    cout << (isprime(x) ? "Yes" : "No") << '\n';
  }
  return 0;
}