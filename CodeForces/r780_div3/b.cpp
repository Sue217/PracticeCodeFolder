/**
 *    author: subobo
 *    created: 31.03.2022 23:08:17
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
    if (n == 1) {
      int x;
      cin >> x;
      if (x == 1) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
      continue;
    }
    int m1 = 0, m2 = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x > m1) {
        m2 = m1;
        m1 = x;
      } else
      if (x > m2) {
        m2 = x;
      }
    }
    if (m1 - m2 <= 1) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}