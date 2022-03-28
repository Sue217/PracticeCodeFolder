/**
 *    author: subobo
 *    created: 27.03.2022 23:54:36
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
    int l, r;
    cin >> l >> r;
    int n = r - l + 1;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    int mb = 0;
    while (mx) {
      ++mb;
      mx >>= 1;
    }
    vector<int> bit(20);
    for (int i = 0; i < n; i++) {
      int x = a[i];
      int p = 0;
      for (int j = 0; j < mb; j++) {
        if (x >> j & 1) {
          bit[p] += 1;
        } else {
          bit[p] -= 1;
        }
        ++p;
      }
    }
    int ans = 0;
    int p = 0;
    for (int i = 0; i < mb; i++) {
      if (bit[i] > 0) {
        ans += (1 << p);
      }
      ++p;
    }
    cout << ans << '\n';
  }
  return 0;
}