/**
 *    author: subobo
 *    created: 01.04.2022 12:48:43
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
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int minus = 0, plus = 0;
      for (int j = i; j < n; j++) {
        if (s[j] == '+') {
          plus += 1;
        } else {
          minus += 1;
        }
        if (minus >= plus && (minus - plus) % 3 == 0) {
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}