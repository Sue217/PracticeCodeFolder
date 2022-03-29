/**
 *    author: subobo
 *    created: 29.03.2022 21:14:14
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
  vector<int> pref(1, 0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pref.push_back(x + pref.back());
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + k - 1; j < n; j++) {
      int x = (pref[j] - pref[i - 1]) / (j - i + 1);
      int low = 0, high = (int) 1e9;
      while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (x >= mid) {
          low = mid;
        } else {
          high = mid;
        }
      }
      ans = max(ans, low);
    }
  }
  cout << ans << '\n';
  return 0;
}