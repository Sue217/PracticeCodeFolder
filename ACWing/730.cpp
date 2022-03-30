/**
 *    author: subobo
 *    created: 29.03.2022 23:34:37
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int low = 0, high = (int) 1e5;
  while (high - low > 1) {
    int mid = (low + high) >> 1;
    int e = mid;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (a[i] > e) {
        e -= (a[i] - e);
      } else {
        e += (e - a[i]);
      }
      if (e < 0) {
        ok = false;
        break;
      }
      if (e > (int) 1e5) {
        break;
      }
    }
    if (ok) {
      high = mid;
    } else {
      low = mid;
    }
  }
  cout << high << '\n';
  return 0;
}