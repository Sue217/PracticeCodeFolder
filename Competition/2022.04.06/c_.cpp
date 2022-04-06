/**
 *    author: subobo
 *    created: 06.04.2022 13:35:06
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m, h, q;
    cin >> n >> m >> h >> q;
    vector<array<int, 3>> co;
    while (q--) {
      int op, x, y, z;
      cin >> op >> x >> y >> z;
      --x; --y; --z;
      if (op == 1) {
        co.push_back({x, y, z});
      }
      if (op == 2) {
        int ans = (int) 2e9;
        for (auto d : co) {
          int xx = d[0];
          int yy = d[1];
          int zz = d[2];
          ans = min(ans, (int) (abs(x - xx) + abs(y - yy) + abs(z - zz)));
        }
        cout << ans << '\n';
      }
    }
  }
  return 0;
}