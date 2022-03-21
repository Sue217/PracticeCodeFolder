#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> m >> n;
  vector<vector<int>> group(n + 1);
  vector<int> w(n + 1, 0), v(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    group[c].emplace_back(i);
    w[i] = a;
    v[i] = b;
  }
  vector<int> dp(m + 1, 0);
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 0; j--) {
      for (int k : group[i]) {
        if (j - w[k] >= 0) {
          dp[j] = max(dp[j], dp[j - w[k]] + v[k]);
        }
      }
    }
  }
  cout << dp[m] << '\n';
  return 0;
}