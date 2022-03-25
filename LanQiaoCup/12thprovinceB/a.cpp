/**
 *    author: subobo
 *    created: 25.03.2022 12:06:04
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
  for (int qq = 0; qq < 5; qq++) {
    string s;
    cin >> s;
    if (s[0] == s[2] && s[3] - s[1] == 1) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}