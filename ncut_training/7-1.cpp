/**
 *    author: subobo
 *    created: 23.01.2022 19:04:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<string> score;
  string s;
  while (cin >> s) {
    score.emplace_back(s);
  }
  for (string sc : score) {
    int w = 0, l = 0, cnt = 0;
    int i = 0;
    for (char c : sc) {
      if (c == 'E') {
        break;
      }
      if (c == 'W') {
        w += 1;
      } else
      if (c == 'L') {
        l += 1;
      }
      cnt += 1;
      if (cnt == 11) {
        cout << w << ":" << l << '\n';
        w = l = cnt = 0;
      }
    }
    cout << w << ":" << l << '\n';
  }
  cout << '\n';
  for (string sc : score) {
    int w = 0, l = 0, cnt = 0;
    for (char c : s) {
      if (c == 'E') {
        break;
      }
      if (c == 'W') {
        w += 1;
      } else
      if (c == 'L') {
        l += 1;
      }
      cnt += 1;
      if (cnt == 21) {
        cout << w << ":" << l << '\n';
        w = l = cnt = 0;
      }
    }
    cout << w << ":" << l << '\n';
  }
  return 0;
}