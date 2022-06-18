/**
 *    author: subobo
 *    created: 18.06.2022 11:52:03
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
  int n, m;
  cin >> n >> m;
  vector<double> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i] /= 100.0;
  }
  vector<vector<double>> a(n, vector<double>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      a[i][j] /= 100.0;
    }
  }
  int k;
  cin >> k;
  map<int, double> c;
  double tot = 0.0;
  vector<double> col(n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      tot += a[j][i];
      col[i] += a[j][i];
    }
  }
  for (int i = 0; i < k; i++) {
    int b;
    cin >> b;
    --b;
    for (int j = 0; j < n; j++) {
      c[j] += a[j][b] * (col[b] / tot) / p[j];
    }
  }
  debug(c);
  double sum = 0.0;
  vector<pair<int, double>> ans;
  for (auto it : c) {
    sum += it.second;
    ans.emplace_back(it);
  }
  sort(ans.begin(), ans.end(), [&](pair<int, double> a, pair<int, double> b) {
    return a.second > b.second;
  });
  for (int i = 0; i < n; i++) {
    cout << ans[i].first + 1 << " " << fixed << setprecision(2) << (ans[i].second / sum) * 100.0 << '\n';
  }
  return 0;
}