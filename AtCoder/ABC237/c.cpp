/**
 *    author: subobo
 *    created: 30.01.2022 20:09:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, rs;
  cin >> s;
  rs = s;
  reverse(rs.begin(), rs.end());
  if (rs == s) {
    puts("Yes");
    return 0;
  }
  int n = (int) s.size();
  int l = 0, r = n - 1;
  while (s[l] == 'a' && s[r] == 'a') {
    l += 1;
    r -= 1;
  }
  if (s[l] == 'a') {
    puts("No");
    return 0;
  }
  while (s[r] == 'a') {
    r -= 1;
  }
  int len = r - l + 1;
  if (r == n - 1 && l != 0) {
    puts("No");
    return 0;
  }
  if (s.substr(l, len) == rs.substr(n - r - 1, len)) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}