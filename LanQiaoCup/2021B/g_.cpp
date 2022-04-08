/**
 *    author: subobo
 *    created: 08.04.2022 21:17:14
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
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int m = accumulate(a.begin(), a.end(), 0);
  vector<vector<bool>> can(n + 1, vector<bool>(m * 2 + 1));
  can[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      can[i][j] = can[i - 1][j] || can[i - 1][j + a[i]] || can[i - 1][(int) abs(j - a[i])];
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans += can[n][i];
  }
  cout << ans << '\n';
  return 0;
}