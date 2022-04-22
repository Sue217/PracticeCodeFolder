/**
 *    author: subobo
 *    created: 22.04.2022 09:16:00
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
    int n, k;
    cin >> n >> k;
    vector<int> bit(31);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < 31; j++) {
        bit[j] += (x >> j) & 1;
      }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
      int rex = n - bit[i];
      ans <<= 1;
      if (rex <= k) {
        ans += 1;
        k -= rex;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}