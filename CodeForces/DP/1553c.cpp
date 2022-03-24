/**
 *    author: subobo
 *    created: 23.03.2022 23:12:58
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
    string s;
    cin >> s;
    int ans = 10;
    for (int t = 0; t < (1 << 10); t++) {
      bool ok = true;
      for (int i = 0; i < 10; i++) {
        int a = (t >> i) & 1;
        int b = s[i] == '0' ? 0 : (s[i] == '1' ? 1 : -1);
        if (a == 1 - b) {
          ok = false;
          break;
        }
      }
      if (!ok) {
        continue;
      }
      int x = 0, y = 0;
      int dx = 5, dy = 5;
      int kicks = 0;
      for (int i = 0; i < 10; i++) {
        int a = (t >> i) & 1;
        if (i % 2 == 0) {
          x += a;
          dx -= 1;
        } else {
          y += a;
          dy -= 1;
        }
        kicks += 1;
        if (x + dx < y || y + dy < x) {
          break;
        }
      }
      ans = min(ans, kicks);
    }
    cout << ans << '\n';
  }
  return 0;
}