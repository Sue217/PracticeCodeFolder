/**
 *    author: subobo
 *    created: 24.04.2022 11:31:13
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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      --b[i];
    }
    int i, j;
    vector<int> extra(n);
    for (i = j = 0; i < n && j < n; ) {
      if (a[i] == b[j]) {
        if (extra[a[i]] > 0) {
          extra[a[i]] -= 1;
        } else {
          i += 1;
        }
        j += 1;
      } else {
        extra[a[i]] += 1;
        i += 1;
      }
    }
    cout << ((i < n || j < n) ? "NO" : "YES") << '\n';
  }
  return 0;
}