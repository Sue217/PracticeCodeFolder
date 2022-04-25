/**
 *    author: subobo
 *    created: 24.04.2022 23:58:39
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
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    int l = 0, r = n - 1;
    int mx = 0;
    while (l <= r) {
      if (a[l] >= a[r]) {
        ans += a[r] >= mx;
        mx = max(mx, a[r]);
        r -= 1;
      } else {
        ans += a[l] >= mx;
        mx = max(mx, a[l]);
        l += 1;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}