/**
 *    author: subobo
 *    created: 08.03.2022 20:22:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      ans |= a;
    }
    cout << ans << '\n';
  }
  return 0;
}