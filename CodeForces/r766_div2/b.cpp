/**
 *    author: subobo
 *    created: 16.01.2022 09:20:39
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
    vector<int> dist;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dist.emplace_back(max(i, n - i - 1) + max(j, m - j - 1));
      }
    }
    sort(dist.begin(), dist.end());
    for (auto it : dist) {
      cout << it << " ";
    }
    cout << '\n';
  }
  return 0;
}