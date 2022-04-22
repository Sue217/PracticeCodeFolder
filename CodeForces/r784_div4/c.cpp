/**
 *    author: subobo
 *    created: 21.04.2022 22:39:51
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
    bool odd = false;
    bool even = false;
    if (a[0] % 2 == 0) even = true;
    if (a[0] % 2 == 1) odd = true;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        if (a[i] % 2 == 0 && odd) {
          ok = false;
          break;
        }
        if (a[i] % 2 == 1 && even) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    even = false;
    odd = false;
    if (a[1] % 2 == 0) even = true;
    if (a[1] % 2 == 1) odd = true;
    ok = true;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 1) {
        if (a[i] % 2 == 0 && odd) {
          ok = false;
          break;
        }
        if (a[i] % 2 == 1 && even) {
          ok = false;
          break;
        }
      }
    }
    if (!ok) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
  }
  return 0;
}