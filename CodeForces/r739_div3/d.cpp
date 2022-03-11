/**
 *    author: subobo
 *    created: 11.03.2022 16:37:58
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
    int ans = (int) 2e9;
    string s;
    cin >> s;
    int n = (int) s.size();
    for (int i = 0; i < 63; i++) {
      string t = to_string(1ll << i);
      int m = (int) t.size();
      int p = 0;
      for (int j = 0; j < n; j++) {
        if (p < m && t[p] == s[j]) {
          ++p;
        }
      }
      ans = min(ans, n + m - p * 2);
    }
    cout << ans << '\n';
  }
  return 0;
}