/**
 *    author: subobo
 *    created: 27.03.2022 22:51:12
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  const long long mod = 998244353;
  while (tt--) {
    long long n;
    cin >> n;
    if (n % 2 == 1) {
      cout << 0 << '\n';
      continue;
    }
    n /= 2;
    long long A = 1;
    for (long long x = n; x > 1; x--) {
      A = A * x % mod;
    }
    A = A * A % mod;
    cout << A << '\n';
  }
  return 0;
}