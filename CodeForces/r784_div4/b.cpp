/**
 *    author: subobo
 *    created: 21.04.2022 22:37:49
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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    map<int, int> m;
    int ans = -1;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      m[x] += 1;
      if (m[x] >= 3) {
        ans = x;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}