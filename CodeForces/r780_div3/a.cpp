/**
 *    author: subobo
 *    created: 31.03.2022 22:35:00
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
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      cout << 1 << '\n';
      continue;
    }
    if (a > b) {
      cout << a + b + 1 << '\n';
    } else {
      cout << b * 2 + a + 1 << '\n';
    }
  }
  return 0;
}