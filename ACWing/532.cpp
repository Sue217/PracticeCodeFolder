/**
 *    author: subobo
 *    created: 14.01.2022 22:12:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> v[i];
    }
    sort(v.begin() + 1, v.end());
    int m = v.back();
    vector<int> dp(m + 1);
    dp[0] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (dp[v[i]] == 0) {
        ans++;
        for (int j = v[i]; j <= m; j++) {
          dp[j] += dp[j - v[i]];
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
