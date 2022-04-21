/**
 *    author:  tourist
 *    created: 09.04.2022 05:04:55       
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
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    vector<vector<int>> s(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      vector<int> b = a[i];
      for (int j = i; j < n; j++) {
        for (int k = 0; k < m; k++) {
          b[k] = min(b[k], a[j][k]);
        }
        s[i][j] = accumulate(b.begin(), b.end(), 0);
      }
    }
    vector<vector<int>> f(n, vector<int>(n));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i; j < n; j++) {
        if (i == j) {
          f[i][j] = s[i][j];
          continue;
        }
        f[i][j] = (int) 1e9;
        for (int k = i; k < j; k++) {
          f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
        }
        f[i][j] -= s[i][j];
      }
    }
    cout << f[0][n - 1] * 2 << '\n';
  }
  return 0;
}
