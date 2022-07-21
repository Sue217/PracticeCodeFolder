/**
 *    author: subobo
 *    created: 21.07.2022 12:43:40
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
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> zone;
    for (int i = 0; i < n; i++) {
      int early, late;
      cin >> early >> late;
      zone.emplace_back(early, late);
    }
    sort(zone.begin(), zone.end());
    set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      // debug(s);
      if (s.empty() || zone[i].first > *(s.rbegin())) {
        s.insert(zone[i].second);
        ans += 1;
      } else {
        ans -= 1;
        break;
      }
    }
    cout << ans << '\n';
    // debug("test end");
  }
  return 0;
}