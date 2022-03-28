/**
 *    author: subobo
 *    created: 27.03.2022 23:27:49
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
  while (tt--) {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }
    bool ok = true;
    int x = (int) (min_element(c.begin(), c.end()) - c.begin());
    if (c[x] == 1) {
      int p = 1;
      for (int i = 1; i < n; i++) {
        x = (x + 1) % n;
        if (c[x] <= 1 || c[x] - p > 1) {
          ok = false;
          break;
        }
        p = c[x];
      }
      cout << (ok ? "YES" : "NO") << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}