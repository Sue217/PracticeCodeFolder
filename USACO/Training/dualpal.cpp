/**
 *    author: subobo
 *    created: 12.02.2022 16:19:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int it = m + 1;
  while (n) {
    bool once = false;
    for (int base = 2; base <= 10; base++) {
      string s = "";
      int t = it;
      while (t) {
        s += t % base + '0';
        t /= base;
      }
      string revs = s;
      reverse(revs.begin(), revs.end());
      if (s == revs) {
        // cerr << it << " " << s << " " <<  base << '\n';
        if (!once) {
          once = true;
        } else {
          cout << it << '\n';
          n -= 1;
          break;
        }
      }
    }
    it += 1;
  }
  return 0;
}