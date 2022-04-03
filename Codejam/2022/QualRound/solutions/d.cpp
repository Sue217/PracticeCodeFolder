/**
 *    author:  tourist
 *    created: 02.04.2022 02:10:40       
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
      --p[i];
    }
    vector<multiset<int>> s(n);
    long long ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (!s[i].empty()) {
        if (p[i] == -1) {
          if (a[i] > *(s[i].begin())) {
            s[i].erase(s[i].begin());
            s[i].insert(a[i]);
          }
          for (int j : s[i]) {
            ans += j;
          }
        } else {
          a[i] = max(a[i], *(s[i].begin()));
          s[i].erase(s[i].begin());
          for (int j : s[i]) {
            ans += j;
          }
          s[p[i]].insert(a[i]);
        }
      } else {
        if (p[i] == -1) {
          ans += a[i];
        } else {
          s[p[i]].insert(a[i]);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
