/**
 *    author: subobo
 *    created: 19.07.2022 12:04:34
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
  while (tt--) {
    int n, m, s, k;
    cin >> n >> m >> s >> k;
    vector<vector<pair<int, int>>> edge(n, vector<pair<int, int>>(n));
    for (int i = 0; i < m; i++) {
      int x, y, w, t;
      cin >> x >> y >> w >> t;
      --x;
      --y;
      edge[x][y] = edge[y][x] = make_pair(w, t);
    }
    // t = 0: common 1: special
    
  return 0;
}