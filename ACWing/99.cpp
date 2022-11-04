/**
 *    author: subobo
 *    created: 16.09.2022 12:18:26
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

const int N = 5002;
// vector<vector<int>> pref(N, vector<int>(N));
int pref[N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, r;
  cin >> n >> r;
  r = min(r, N - 1);
  for (int i = 0; i < n; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    x += 1;
    y += 1;
    pref[x][y] += w;
  }
  for (int i = 1; i < N; i++) {
    for (int j = 1; j < N; j++) {
      pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
    }
  }
  int ans = -1;
  for (int i = r; i < N; i++) {
    for (int j = r; j < N; j++) {
      ans = max(ans, pref[i][j] - pref[i - r][j] - pref[i][j - r] + pref[i - r][j - r]);
    }
  }
  cout << ans << '\n';
  return 0;
}
