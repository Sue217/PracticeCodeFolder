/**
 *    author: subobo
 *    created: 02.04.2022 21:14:50
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
  for (int qq = 1; qq <= tt; qq++) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    cout << "Case #" << qq << ": ";
    sort(a.begin(), a.end());
    int low = 1, high = 1;
    int mx = 0;
    int ans = 0;
    while (high <= n) {
      mx = max(mx, a[high]);
      if (high - low + 1 > mx) {
        ans = max(ans, high - low);
        ++low;
      }
      ++high;
    }
    ans = max(ans, high - low);
    cout << (ans == 0 ? n : ans) << '\n';
  }
  return 0;
}