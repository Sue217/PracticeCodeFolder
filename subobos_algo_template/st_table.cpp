/**
 *    author: Jingbo Su
 *    title: ST Table
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> st(n + 3, vector<int>(log2l(n) + 1));
  for (int i = 1; i <= n; ++i) {
    cin >> st[i][0];
  }
  for (int j = 1; j <= log2l(n); ++j) {
    for (int i = 1; i <= n - (1 << j) + 1; ++i) {
      st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto query = [&](int l, int r) -> int {
    int k = (int)log2l(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
  };
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    cout << query(l, r) << '\n';
  }
  return 0;
}
