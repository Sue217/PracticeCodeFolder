/**
 *    author: subobo
 *    created: 19.07.2022 14:38:13
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
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
      cin >> a[i];
    }
    if (a[0] > 0 || a[1] >= 2) {
      cout << "Alice" << '\n';
      continue;
    }
    int mn = (int) 1e9;
    for (int i = 0; i <= n; i++) {
      if (a[i] > 0) {
        mn = i;
        a[i] -= 1;
        break;
      }
    }
    if (mn == (int) 1e9) {
      cout << "Bob" << '\n';
      continue;
    }
    vector<int> pref(n + 3);
    for (int i = n; i >= 0; i--) {
      pref[i] = pref[i + 1] + a[i];
    }
    cout << (pref[mn] >= mn ? "Alice" : "Bob") << '\n';
  }
  return 0;
}