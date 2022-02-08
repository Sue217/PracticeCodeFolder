/**
 *    author: subobo
 *    created: 08.02.2022 22:12:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b;
  cin >> a >> b;
  if (a == 0) {
    cout << 0 << '\n';
    return 0;
  }
  constexpr long long mod = 9901;
  auto f_pow = [&](long long a, long long b)->long long {
    long long ans = 1;
    while (b) {
      if (b & 1) {
        ans = ans * a % mod;
      }
      a = a * a % mod;
      b >>= 1;
    }
    return ans;
  };
  function<long long(long long, long long)> get = [&](long long p, long long k)->long long {
    // get(p, k) = p^0 + p^1 + ... + p^k-1  __GP
    if (k == 1) {
      // 1 / 2 = 0
      return 1;
    }
    if (k % 2 == 0) {
      return (1 + f_pow(p, k / 2)) * get(p, k / 2) % mod;
    } else {
      return (get(p, k - 1) + f_pow(p, k - 1)) % mod;
      // return 1 + p * get(p, k - 1) % mod;
    }
  };
  long long ans = 1;
  for (long long i = 2; i <= a / i; i++) {
    if (a % i == 0) {
      long long times = 0;
      while (a % i == 0) {
        a /= i;
        times += 1;
      }
      ans = ans * get(i, b * times + 1) % mod;
    }
  }
  if (a > 1) {
    ans = ans * get(a, b + 1) % mod;
  }
  cout << ans << '\n';
  return 0;
}