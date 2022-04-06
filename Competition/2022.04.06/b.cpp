/**
 *    author: subobo
 *    created: 06.04.2022 11:00:02
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T, typename U>
inline T power(const T& a, const T& b, const U& mod) {
  assert(b >= 0);
  T x = a, p = b, ans = 1;
  while (p > 0) {
    if (p & 1) ans = ans * x % mod;
    x = x * x % mod;
    p >>= 1;
  }
  return ans % mod;
}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k, q;
  cin >> n >> m >> k >> q;
  constexpr long long mod = 1000000007;
  long long ans = power(n / (m + n), k, mod);
  ans = power(ans, q, mod);
  cout << ans << '\n';
  return 0;
}