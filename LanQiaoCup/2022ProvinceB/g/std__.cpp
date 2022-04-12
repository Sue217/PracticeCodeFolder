/**
 *    author: subobo
 *    created: 10.04.2022 18:57:36
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
  int n;
  cin >> n;
  long long a = 1;
  long long b = 0;
  long long c = 1;
  constexpr long long mod = 1000000007;
  for (int i = 2; i <= n; i++) {
    long long x = a;
    long long y = b;
    long long z = c;
    a = x + y + z; a %= mod;
    b = y + z * 2; b %= mod;
    c = x; c %= mod;
  }
  cout << a << '\n';
  return 0;
}