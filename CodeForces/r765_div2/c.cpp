/**
 *    author: subobo
 *    created: 13.01.2022 20:46:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, l, k;
  cin >> n >> l >> k;
  vector<int> d(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  d.emplace_back(l);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  a.emplace_back(0);
  constexpr long long inf = (long long) 2e18;
  vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      for (int p = i - 1; p >= 0; p--) {
        int remove = j - (i - p - 1);
        if (remove >= 0) {
          dp[i][j] = min(dp[i][j], dp[p][remove] + (d[i] - d[p]) * a[p]);
        }
      }
    }
  }
  cout << *min_element(dp.back().begin(), dp.back().end()) << '\n';
  return 0;
}
