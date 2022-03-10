/**
 *    author: subobo
 *    created: 09.03.2022 10:08:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> point;
    for (int i = 1; i <= m; i++) {
      int x, w;
      cin >> x >> w;
      point.push_back({x, w, i});
    }
    sort(point.begin(), point.end(), [&](vector<int> a, vector<int> b) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      }
      return a[1] < b[1];});
    int ans = 0;
    for (int i = 0; i < n * 2; i++) {
      ans += point[i][1];
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << point[i][2] << " " << point[n * 2 - i - 1][2] << '\n';
    }
    cout << '\n';
  }
  return 0;
}