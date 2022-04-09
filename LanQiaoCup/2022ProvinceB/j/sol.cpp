#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> b;
  b.push_back(a[0]);
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      b.push_back(a[i]);
    }
  }
  vector<int> pos(n + 1, n + 1), ne(n + 1, n + 1);
  n = (int) b.size();
  map<long long, int> s;
  for (int i = 0; i < n; i++) {
    s[b[i]] += 1;
  }
  long long mxn = 0, mxv = 0;
  for (auto i : s) {
    if (i.second > mxn) {
      mxn = i.second;
      mxv = i.first;
    }
  }
  int addt = (int) sqrt(mxv / 2 + 1);
  for (int i = n - 1; i >= 0; i--) {
    ne[i] = pos[b[i]];
    pos[b[i]] = i;
  }
  vector<vector<int>> dp(n, vector<int>(n));
  for (int d = 1; d < n; d++) {
    for (int l = 0; l + d < n; l++) {
      int r = l + d;
      dp[l][r] = dp[l + 1][r];
      int m = ne[l];
      while (m <= r) {
        dp[l][r] = max(dp[l][r], dp[l + 1][m - 1] + dp[m][r] + 1);
        m = ne[m];
      }
    }
  }
  cout << n - dp[0][n - 1] - 1 + addt << '\n';
  return 0;
}