/**
 *    author: subobo
 *    created: 04.04.2022 22:42:00
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
  int ans = 0;
  for (int y = 1; y <= 2020; y++) {
    string s = to_string(y);
    for (char c : s) {
      if (c == '2') {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}