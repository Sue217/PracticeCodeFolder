/**
 *    author: subobo
 *    created: 14.05.2022 11:14:43
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    --a[i];
  }
  vector<int> b(a);
  sort(b.begin(), b.end());
  vector<vector<int>> edge(3, vector<int>(3));
  for (int i = 0; i < n; i++) {
    edge[a[i]][b[i]] += 1;
  }
  int self = 0;
  for (int i = 0; i < 3; i++) {
    self += edge[i][i];
  }
  int ans = self;
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 3; j++) {
      int mn = min(edge[i][j], edge[j][i]);
      ans += mn;
      edge[i][j] -= mn;
      edge[j][i] -= mn;
    }
  }
  ans += max(edge[0][1], edge[1][0]);
  cout << n - ans << '\n';
  return 0;
}