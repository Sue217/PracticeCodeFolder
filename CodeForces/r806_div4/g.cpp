/**
 *    author: subobo
 *    created: 19.07.2022 11:40:02
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n + 1);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
    }
    long long ans = 0;
    multiset<long long> s;
    for (int i = n; i >= 0; i--) {
      long long now = pref[i] - (long long) k * i;
      now += accumulate(s.begin(), s.end(), 0LL);
      ans = max(ans, now);
      s.insert(a[i]);
      multiset<long long> t;
      for (auto& x : s) {
        if (x / 2 > 0) {
          t.insert(x / 2);
        }
      }
      s = t;
    }
    cout << ans << '\n';
  }
  return 0;
}