/**
 *    author: subobo
 *    created: 16.03.2022 15:06:21
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T, typename U>
inline T pow(const T& a, const T& b, const U& mod) {
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
  int tt;
  cin >> tt;
  while (tt--) {
    long long m;
    cin >> m;
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      ans = (ans + pow(x, y, m)) % m;
    }
    cout << ans << '\n';
  }
  return 0;
}