/**
 *    author: subobo
 *    created: 14.04.2022 19:37:08
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
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<long long> pref(1);
    for (int i = 0; i < n; i++) {
      pref.push_back(pref.back() + a[i] - b[i]);
    }
    vector<long long> dp(n + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        if (pref[i] - pref[j - 1] >= 0 && pref[j - 1] >= 0) {
          dp[i] = max(dp[i], dp[j - 1] + 1);
        }
      }
    }
    cout << (dp[n] == 0 ? -1 : dp[n]) << '\n';
  }
  return 0;
}