/**
 *    author: subobo
 *    created: 12.03.2022 15:29:52
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
  string s;
  cin >> s;
  int n = (int) s.size();
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s.substr(i, 8) == "chuanzhi") {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}