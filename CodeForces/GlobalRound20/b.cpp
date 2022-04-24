/**
 *    author: subobo
 *    created: 23.04.2022 22:15:44
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
    int n = (int) s.size();
    bool ok = true;
    if (s[n - 1] != 'B') {
      cout << "NO" << '\n';
      continue;
    }
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') ++a;
      if (s[i] == 'B') {
        ++b;
        if (b > a) {
          ok = false;
          break;
        }
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}