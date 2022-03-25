/**
 *    author: subobo
 *    created: 25.03.2022 00:16:27
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
    bool one = false;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        one = true;
      }
    }
    if (!one) {
      cout << "YES" << '\n';
      continue;
    }
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 0; i < n - 1; i++) {
      if (a[i + 1] - a[i] == 1) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}