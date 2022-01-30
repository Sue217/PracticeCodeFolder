/**
 *    author: subobo
 *    created: 30.01.2022 10:24:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> tree(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> tree[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1)), root(n + 1, vector<int>(n + 1));
  function<void(int, int)> Dfs = [&](int l, int r) {
    if (l > r) {
      return;
    }
    int u = root[l][r];
    cout << u << " ";
    Dfs(l, u - 1);
    Dfs(u + 1, r);
  };
  for (int len = 1; len <= n; len++) {
    for (int l = 1; l + len - 1 <= n; l++) {
      int r = l + len - 1;
      if (l == r) {
        dp[l][r] = tree[l];
        root[l][r] = l;
      } else {
        for (int rt = l; rt <= r; rt++) {
          int left = rt == l ? 1 : dp[l][rt - 1];
          int right = rt == r ? 1 : dp[rt + 1][r];
          int point = left * right + tree[rt];
          if (dp[l][r] < point) {
            dp[l][r] = point;
            root[l][r] = rt;
          }
        }
      }
    }
  }
  cout << dp[1][n] << '\n';
  Dfs(1, n);
  cout << '\n';
  return 0;
}