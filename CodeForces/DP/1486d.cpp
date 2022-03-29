/**
 *    author: subobo
 *    created: 29.03.2022 22:48:20
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> mn(n + 1);
  int low = 1, high = n;
  while (low < high) {
    int mid = (low + high + 1) >> 1;
    int pref = 0;
    bool ok = true;
    for (int i = 1; i <= n; i++) {
      if (a[i] >= mid) {
        pref += 1;
      } else {
        pref -= 1;
      }
      mn[i] = min(mn[i - 1], pref);
      if (i >= k && pref - mn[i - k] > 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      high = mid - 1;
    } else {
      low = mid;
    }
  }
  cout << low << '\n';
  return 0;
}