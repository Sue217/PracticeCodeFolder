/**
 *    author:  tourist
 *    created: 02.04.2022 02:05:01       
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
    sort(a.rbegin(), a.rend());
    // a[i] >= ans - i
    int ans = n;
    for (int i = 0; i < n; i++) {
      ans = min(ans, a[i] + i);
    }
    cout << ans << '\n';
  }
  return 0;
}
