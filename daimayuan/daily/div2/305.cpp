/**
 *    author: subobo
 *    created: 16.03.2022 22:30:58
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
    string s;
    cin >> s;
    const int inf = (int) 1e9;
    int ans = inf;
    for (int i = 0; i < 26; i++) {
      char c = 'a' + i;
      int has = 0;
      bool ok = true;
      for (int l = 0, r = n - 1; l <= r;) {
        if (s[l] == s[r]) {
          ++l; --r;
          continue;
        }
        if (s[l] == c) {
          ++l;
          ++has;
          continue;
        }
        if (s[r] == c) {
          --r;
          ++has;
          continue;
        }
        if (s[l] != c || s[r] != c) {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans = min(ans, has);
      }
    }
    cout << (ans == inf ? -1 : ans) << '\n';
  }
  return 0;
}