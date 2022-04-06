/**
 *    author: subobo
 *    created: 06.04.2022 12:26:04
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
  while (tt--) {
    long long n, m;
    cin >> n >> m;
    long long ans = 0;
    while (n != 0 && m != 0) {
      if (n < m) {
        swap(n, m);
      }
      long long delta = (n - m) / m + 1;
      ans += delta;
      n -= m * delta;
    }
    cout << ans << '\n';
  }
  return 0;
}