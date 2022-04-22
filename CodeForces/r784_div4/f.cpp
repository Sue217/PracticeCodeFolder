/**
 *    author: subobo
 *    created: 21.04.2022 23:27:22
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int l = 0, r = n - 1;
    int sa = 0, sb = 0;
    int ans = 0;
    while (l <= r) {
      sa += a[l];
      ++l;
      while (l <= r && sa > sb) {
        sb += a[r];
        --r;
      }
      if (sa == sb) {
        ans = max(ans, l + n - r - 1);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}