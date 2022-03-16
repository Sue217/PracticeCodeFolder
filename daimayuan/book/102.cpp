/**
 *    author: subobo
 *    created: 16.03.2022 11:00:23
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <typename T, typename U>
inline T add(const T& a, const T& b, const U& mod) {
  assert(b >= 0);
  T x = a, p = b, ans = 0;
  while (p > 0) {
    if (p & 1) ans = (ans + x) % mod;
    x = (x + x) % mod;
    p >>= 1;
  }
  return ans % mod;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long a, b, p;
  cin >> a >> b >> p;
  cout << add(a, b, p) << '\n';
  return 0;
}