/**
 *    author: subobo
 *    created: 21.04.2022 23:44:02
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
    int b = 0;
    int r = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'B') {
        b += 1;
      } else
      if (s[i] == 'R') {
        r += 1;
      } else {
        if (b + r == 1 || b == 0 && r > 0 || r == 0 && b > 0) {
          ok = false;
          break;
        }
        b = r = 0;
      }
    }
    if (s[n - 1] != 'W' && (b + r == 1 || b == 0 && r > 0 || r == 0 && b > 0)) {
      ok = false;
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}