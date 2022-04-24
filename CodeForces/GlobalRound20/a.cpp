/**
 *    author: subobo
 *    created: 23.04.2022 22:06:39
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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt += x - 1;
    }
    cout << (cnt % 2 == 1 ? "errorgorn" : "maomao90") << '\n';
  }
  return 0;
}