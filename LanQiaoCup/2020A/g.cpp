/**
 *    author: subobo
 *    created: 05.04.2022 00:04:32
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
    string subs = s.substr(0, 4);
    int hb = stoi(subs);
    string pb(subs);
    reverse(subs.begin(), subs.end());
    pb += subs;
    bool ok = true;
    // first
    if (s < pb) {
      ok = false;
      cout << pb << '\n';
    } else {
      int yy = hb + 1;
      while (true) {
        int m = yy - (yy / 100) * 100;
        if (m % 10 == 0 && 1 <= m / 10 && m / 10 <= 9 || m == 11 || m == 21) {
          string ys = to_string(yy);
          string ps(ys);
          reverse(ys.begin(), ys.end());
          ps += ys;
          cout << ps << '\n';
          break;
        }
        yy += 1;
      }
    }
    // second
    while (true) {
      string ps(to_string(hb));
      if (!ok) {
        if (s[0] == s[2] && s[1] == s[3]) {
          cout << ps << '\n';
          break;
        }
      } else {
        ++hb;
        string ss(to_string(hb));
        int yy = hb;
        if (ss[0] == ss[2] && ss[1] == ss[3]) {
          int m = yy - (yy / 100) * 100;
          if (m % 10 == 0 && 1 <= m / 10 && m / 10 <= 9 || m == 11 || m == 21) {
            string ys(to_string(hb));
            string ps(ys);
            reverse(ys.begin(), ys.end());
            ps += ys;
            cout << ps << '\n';
            break;
          }
        }
      }
    }
  }
  return 0;
}