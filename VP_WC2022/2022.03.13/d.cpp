/**
 *    author: subobo
 *    created: 13.03.2022 18:34:39
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
  int x, y;
  cin >> x >> y;
  int ans = 5000 - x * y / 2 - (100 - x) * y - (100 - x) * (100 - y) / 2;
  cout << ans << '\n';
  return 0;
}