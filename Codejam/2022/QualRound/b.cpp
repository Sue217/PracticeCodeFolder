/**
 *    author: subobo
 *    created: 02.04.2022 20:18:49
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
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    vector<int> mn(4, (int) 1e6);
    for (int i = 0; i < 3; i++) {
      int c, m, y, k;
      cin >> c >> m >> y >> k;
      mn[0] = min(c, mn[0]);
      mn[1] = min(m, mn[1]);
      mn[2] = min(y, mn[2]);
      mn[3] = min(k, mn[3]);
    }
    cout << "Case #" << qq << ": ";
    if (accumulate(mn.begin(), mn.end(), 0) >= (int) 1e6) {
      int div = 0;
      for (int i = 0; i < 4; i++) {
        if (div >= (int) 1e6) {
          cout << 0 << " \n"[i == 3];
        } else {
          cout << min(mn[i], (int) 1e6 - div) << " \n"[i == 3];
          div += mn[i];
        }
      }
    } else {
      cout << "IMPOSSIBLE" << '\n';
    }
  }
  return 0;
}