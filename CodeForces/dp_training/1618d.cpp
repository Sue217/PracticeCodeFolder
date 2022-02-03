/**
 *    author: subobo
 *    created: 03.02.2022 10:26:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int& in : a) {
      cin >> in;
    }
    sort(a.begin(), a.end());
    int ans = accumulate(a.begin(), a.begin() + n - 2 * m, 0);
    for (int i = n - 2 * m; i < n - m; i++) {
      ans += a[i] / a[i + m];
    }
    cout << ans << '\n';
  }
  return 0;
}