/**
 *    author: subobo
 *    created: 21.04.2022 23:11:30
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
    map<char, int> mx, my;
    map<string, int> cnt;
    int n;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      char x = s[0], y = s[1];
      ans += mx[x] + my[y] - cnt[s] * 2;
      mx[x] += 1;
      my[y] += 1;
      cnt[s] += 1;
    }
    cout << ans << '\n';
  }
  return 0;
}