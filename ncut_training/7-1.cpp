/**
 *    author: subobo
 *    created: 23.01.2022 19:04:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, xs;
  while (cin >> s) {
    xs += s;
  }
  if (xs.size() == 0 || xs.size() == 1) {
    puts("0:0");
    return 0;
  }
  int w = 0, l = 0;
  for (char c : xs) {
    if (c == 'E') {
      break;
    }
    if (c == 'W') {
      w += 1;
    } else
    if (c == 'L') {
      l += 1;
    }
    if ((w >= 11 || l >= 11) && abs(w - l) >= 2) {
      cout << w << ":" << l << '\n';
      w = l = 0;
    }
  }
  cout << w << ":" << l << '\n';
  cout << '\n';
  w = 0, l = 0;
  for (char c : xs) {
    if (c == 'E') {
      break;
    }
    if (c == 'W') {
      w += 1;
    } else
    if (c == 'L') {
      l += 1;
    }
    if ((w >= 21 || l >= 21) && abs(w - l) >= 2) {
      cout << w << ":" << l << '\n';
      w = l = 0;
    }
  }
  cout << w << ":" << l << '\n';
  return 0;
}