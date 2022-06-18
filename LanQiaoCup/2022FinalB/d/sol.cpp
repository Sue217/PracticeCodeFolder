/**
 *    author: subobo
 *    created: 18.06.2022 10:33:55
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  string s(to_string(n));
  for (int i = 0; i < (int) s.size(); i++) {
    if (9 - (s[i] - '0') <= s[i] - '0' + 1) {
      if (a >= 9 - (s[i] - '0')) {
        a -= 9 - (s[i] - '0');
        s[i] = '9';
      } else {
        if (b >= s[i] - '0' + 1) {
          b -= s[i] - '0' + 1;
          s[i] = '9';
        } else {
          s[i] += a;
          a = 0;
        }
      }
    } else {
      if (b >= s[i] - '0' + 1) {
        b -= s[i] - '0' + 1;
        s[i] = '9';
      } else {
        if (a >= 9 - (s[i] - '0')) {
          a -= 9 - (s[i] - '0');
          s[i] = '9';
        } else {
          s[i] += a;
          a = 0;
        }
      }
    }
  }
  cout << stoi(s) << '\n';
  return 0;
}