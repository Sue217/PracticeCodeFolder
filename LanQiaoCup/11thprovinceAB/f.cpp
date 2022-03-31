/**
 *    author: subobo
 *    created: 31.03.2022 21:09:57
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
  long long pref = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    cin >> x;
    ans += pref * x;
    pref += x;
  }
  cout << ans << '\n';
  return 0;
}