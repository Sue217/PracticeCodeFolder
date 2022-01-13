/**
 *    author: subobo
 *    created: 13.01.2022 08:44:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, l;
    cin >> n >> l;
    vector<vector<int>> cnt(l, vector<int>(2));
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      for (int j = 0; j < l; j++) {
        int bit = (x >> j) & 1;
        cnt[j][bit]++;
      }
    }
    int res = 0;
    for (int i = 0; i < l; i++) {
      if (cnt[i][0] < cnt[i][1]) {
        res += (1 << i);
      }
    }
    cout << res << '\n';
  }
  return 0;
}
