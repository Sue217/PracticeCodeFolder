/**
 *    author: subobo
 *    created: 09.03.2022 09:56:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    long long l, r, a;
    cin >> l >> r >> a;
    long long ans = r / a + r % a;
    long long v = r - r % a - 1;
    if (v >= l) {
      ans = max(ans, v / a + v % a);
    }
    cout << ans << '\n';
  }
  return 0;
}