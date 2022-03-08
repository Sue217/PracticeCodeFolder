/**
 *    author: subobo
 *    created: 08.03.2022 22:35:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    string s;
    cin >> s;
    char c;
    cin >> c;
    int n = (int) s.size();
    bool ok = true, found = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == c) {
        found = true;
        if (i % 2 == 0) {
          ok = false;
          break;
        }
      }
    }
    if (!ok && found) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  return 0;
}