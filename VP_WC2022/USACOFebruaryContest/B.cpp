/**
 *    author: subobo
 *    created: 28.02.2022 11:20:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[x] = i;
  }
  int mx = b[a[0]], ans = 0;
  for (int i = 1; i < n; i++) {
    if (b[a[i]] < mx) {
      ans += 1;
    } else {
      mx = b[a[i]];
    }
  }
  cout << ans << '\n';
  return 0;
}
