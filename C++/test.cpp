/**
 *    author: subobo
 *    created: 08.02.2022 20:03:14
**/
#include <bits/stdc++.h>

using namespace std;

inline long long mults(long long& a, long long& b, const long long mod) {
  assert(b >= 0);
  long long x = a, res = 0;
  long long p = b;
  while (p > 0) {
    if (p & 1) {
      res = (res + x) % mod;
    }
    x = (x + x) % mod;
    p >>= 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, p;
  cin >> a >> b >> p;
  cout << mults(a, b, p) << '\n';
  return 0;
}