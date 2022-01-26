/**
 *    author: subobo
 *    created: 26.01.2022 19:38:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  while (cin >> s >> t) {
    string tt = "";
    tt += t;
    int l = 0, r = (int) s.size() - 1;
    while (l <= r) {
      string ss = s.substr(l, r - l + 1);
      string rs = ss;
      reverse(rs.begin(), rs.end());
      if (ss < rs) {
        tt += s[l];
        l += 1;
      } else {
        tt += s[r];
        r -= 1;
      }
    }
    cout << tt << '\n';
  }
  return 0;
}