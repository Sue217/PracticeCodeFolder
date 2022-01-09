/**
 *    author: subobo
 *    created: 09.01.2022 16:31:19
**/
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma comment(linker, "/stack:256000000")

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  while (cin >> n, n) {
    vector<int> seq(n);
    for (auto& in : seq) {
      cin >> in;
    }
    vector<int> up(n), down(n);
    int res = n;
    function<void(int, int, int)> Dfs = [&](int pos, int u, int d) {
      if (u + d >= res) {
        return;
      }
      if (pos >= n) {
        res = u + d;
        return;
      }
      int k;
      for (k = 0; k < u && up[k] >= seq[pos]; k++);
      int t = up[k];
      up[k] = seq[pos];
      if (k < u) {
        Dfs(pos + 1, u, d);
      } else {
        Dfs(pos + 1, u + 1, d);
      }
      up[k] = t;

      for (k = 0; k < d && down[k] <= seq[pos]; k++);
      t = down[k];
      down[k] = seq[pos];
      if (k < d) {
        Dfs(pos + 1, u, d);
      } else {
        Dfs(pos + 1, u, d + 1);
      }
      down[k] = t;
    };
    Dfs(0, 0, 0);
    cout << res << '\n';
  }
  return 0;
}
