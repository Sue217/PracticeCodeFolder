/**
 *    author: subobo
 *    created: 16.04.2022 19:21:18
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  string s;
  cin >> s;
  bitset<26> d;
  for (int i = 0; i < 5; i++) {
    d[s[i] - 'A'] = 1;
  }
  bool win = false;
  for (int tt = 1; tt <= 7; tt++) {
    string xs;
    cin >> xs;
    if (xs == s) {
      cout << "WINNER" << '\n';
      win = true;
      break;
    }
    if (tt == 7) {
      cout << "LOSER" << '\n';
      break;
    }
    for (int i = 0; i < 5; i++) {
      if (xs[i] == s[i]) {
        cout << 'G';
        continue;
      }
      if (d[xs[i] - 'A'] == 1) {
        cout << 'Y';
      } else {
        cout << 'X';
      }
    }
    cout << '\n';
  }
  return 0;
}