/**
 *    author: subobo
 *    created: 08.03.2022 23:07:53
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
    for (int i = 0; i < m; i++) {
      int x, w;
      cin >> x >> w;
      point.push_back({x, w, i + 1});
    }
    sort(point.begin(), point.end(), [&](vector<int> a, vector<int> b) {return a[0] < b[0];});
    // for (int i = 0; i < m; i++) {
    //   point[i][2] = i + 1;
    // }
    int ptr = n;
    vector<vector<int>> left, right;
    for (int i = 0; i < ptr; i++) {
      left.emplace_back(point[i]);
    }
    for (int i = ptr; i < m; i++) {
      right.emplace_back(point[i]);
    }
    sort(left.begin(), left.end(), [&](vector<int> a, vector<int> b) {return a[1] < b[1];});
    sort(right.begin(), right.end(), [&](vector<int> a, vector<int> b) {return a[1] < b[1];});
    long long ans = 0;
    vector<vector<int>> LP, RP;
    for (int i = 0; i < n; i++) {
      ans += left[i][1];
      LP.push_back(left[i]);
      ans += right[i][1];
      RP.push_back(right[i]);
    }
    sort(LP.begin(), LP.end(), [&](vector<int> a, vector<int> b) {return a[0] < b[0];});
    sort(RP.begin(), RP.end(), [&](vector<int> a, vector<int> b) {return a[0] > b[0];});
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
      cout << LP[i][2] << " " << RP[i][2] << '\n';
    }
    cout << '\n';
  }
  return 0;
}