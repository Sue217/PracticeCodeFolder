/**
 *    author: subobo
 *    created: 21.04.2022 22:58:36
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
    if (n == 1 && s != "W") {
      cout << "NO" << '\n';
      continue;
    }
    bool ok = true;
    if (n == 2 && s != "WW") {
      if (s == "WW" || s == "RB" || s == "BR") {
        ok = true;
      } else {
        ok = false;
      }
    }
    string xs = "";
    xs += s[0];
    xs += s[1];
    if (xs == "BW" || xs == "RW") ok = false;
    xs = "";
    xs += s[n - 2];
    xs += s[n - 1];
    if (xs == "WB" || xs == "WR") ok = false;
    for (int i = 0; i <= n - 3; i++) {
      if (s.substr(i, 3) == "BBB" || s.substr(i, 3) == "RRR" || s.substr(i, 3) == "WBW" || s.substr(i, 3) == "WRW") {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}