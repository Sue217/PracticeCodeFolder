/**
 *    author: subobo
 *    created: 14.04.2022 17:16:32
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
    long long n, k, x, y;
    cin >> n >> k >> x >> y;
    long long mx = 0;
    for (int i = 0; i < n; i++) {
      long long x;
      cin >> x;
      mx = max(mx, x);
    }
    long long low = 0, high = 0;
    if (k * x >= mx) {
      low = 0, high = k;
      while (high - low > 1) {
        long long mid = (low + high) >> 1;
        if (mid * x >= mx) {
          high = mid;
        } else {
          low = mid;
        }
      }
    } else {
      low = k, high = (long long) 1e9;
      while (high - low > 1) {
        long long mid = (low + high) >> 1;
        if (k * x + (mid - k) * y >= mx) {
          high = mid;
        } else {
          low = mid;
        }
      }
    }
    cout << high << '\n';
  }
  return 0;
}