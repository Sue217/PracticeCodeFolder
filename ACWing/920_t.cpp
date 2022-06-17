/**
 *    author: subobo
 *    created: 17.06.2022 21:24:13
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
  int m, n;
  cin >> m >> n;
  cin.get();
  if (n == 1 || m == 1) {
    cout << 0 << '\n';
    return 0;
  }
  constexpr int inf = (int) 1e8;
  vector<vector<int>> dist(n, vector<int>(n, inf));
  for (int i = 0; i < m; i++) {
    string s;
    getline(cin, s);
    vector<int> a;
    stringstream sin(s);
    int x;
    while (sin >> x) a.push_back(x);
    for (int j = 0; j < (int) a.size(); j++) {
      for (int k = j + 1; k < (int) a.size(); k++) {
        dist[a[j] - 1][a[k] - 1] = 1;
      }
    }
  }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  if (dist[0][n - 1] == inf) {
    cout << "NO" << '\n';
  } else {
    cout << dist[0][n - 1] - 1 << '\n';
  }
  cerr << "time: " << clock() / 1000 << " ms" << '\n';
  return 0;
}