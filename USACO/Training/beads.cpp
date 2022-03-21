/**
 *    author: subobo
 *    created: 30.01.2022 17:40:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  s += s;
  auto val = [&](char c) {
    if (c == 'b') {
      return 1;
    }
    return 2;
  };
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int L = i, R = i + n - 1;
    int lv = 0, rv = 0, cnt = 0;
    while (L <= R) {
      if (s[L] == 'w') {
        cnt += 1;
      } else {
        if ((lv | val(s[L])) != 3) {
          lv = val(s[L]);
          cnt += 1;
        } else {
          break;
        }
      }
      L += 1;
    }
    while (L <= R) {
      if (s[R] == 'w') {
        cnt += 1;
      } else {
        if ((rv | val(s[R])) != 3) {
          rv = val(s[R]);
          cnt += 1;
        } else {
          break;
        }
      }
      R -= 1;
    }
    ans = max(ans, cnt);
  }
  cout << ans << '\n';
  return 0;
}