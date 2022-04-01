/**
 *    author: subobo
 *    created: 01.04.2022 00:09:04
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
    int unzero = 0;
    int low = n, high = 0;
    while (unzero < n && a[unzero] == 0) {
      ++unzero;
    }
    int mx = 0;
    for (int l = unzero; l < n; ) {
      bool sign = true;
      int r = l;
      int two = 0;
      while (r < n && a[r] != 0) {
        ++r;
      }
      for (int d = l; d < r; d++) {
        sign = a[d] < 0 ? !sign : sign;
        if (a[d] == -2 || a[d] == 2) {
          two += 1;
        }
        if (sign && mx < two) {
          mx = two;
          low = l;
          high = n - d - 1;
        }
      }
      sign = true;
      two = 0;
      for (int d = r - 1; d >= l; d--) {
        sign = a[d] < 0 ? !sign : sign;
        if (a[d] == -2 || a[d] == 2) {
          two += 1;
        }
        if (sign && mx < two) {
          mx = two;
          low = d;
          high = n - r;
        }
      }
      l = r + 1;
    }
    cout << low << " " << high << '\n';
  }
  return 0;
}