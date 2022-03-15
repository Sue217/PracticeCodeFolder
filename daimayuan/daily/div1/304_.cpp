/**
 *    author: subobo
 *    created: 15.03.2022 22:59:32
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
    constexpr int bound = (int) 1e6;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += bound;
    }
    int ans = 0;
    for (int k = bound; k > 0; k--) {
      map<int, int> m;
      for (int i = 0; i < n; i++) {
        m[a[i] % k] += 1;
      }
      for (auto it : m) {
        if (it.second >= n / 2) {
          ans = max(ans, k);
        }
      }
    }
    if (ans == bound) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
  return 0;
}