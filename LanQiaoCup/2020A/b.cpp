/**
 *    author: subobo
 *    created: 04.04.2022 22:45:43
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
  for (int f = 1; f <= 2020; f++) {
    for (int d = 1; d <= 2020; d++) {
      if (__gcd(f, d) == 1) {
        ans += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}