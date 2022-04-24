/**
 *    author: subobo
 *    created: 23.04.2022 22:23:45
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<pair<int, int>> p;
    for (int i = 1; i < n; ) {
      if (a[i] == a[i - 1]) {
        int j = i;
        while (j < n && a[j] == a[j - 1]) {
          ++j;
        }
        p.emplace_back(i - 1, j - 1);
        i = j;
      } else {
        ++i;
      }
    }
    if (p.size() == 0) {
      cout << 0 << '\n';
      continue;
    }
    int u = p[0].first;
    int v = p[0].second;
    int ans = (v - u == 2 ? 1 : max(0, v - u - 2));
    if (p.size() == 1) {
      cout << ans << '\n';
      continue;
    }
    int m = (int) p.size();
    int x = p[m - 1].first;
    int y = p[m - 1].second;
    ans += y - v;
    if (v - u == 1 || v - u == 2) {
      ans -= 1;
    }
    cout << ans << '\n';
  }
  return 0;
}