/**
 *    author: subobo
 *    created: 25.03.2022 12:08:38
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
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (i * i % n < n / 2.0) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}