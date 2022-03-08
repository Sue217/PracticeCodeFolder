/**
 *    author: subobo
 *    created: 08.03.2022 22:42:27
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
    if (a == r) {
      --r;
    } else
    if (a < l) {
      if (r / a + (r % a) < (r - 1) / a + ((r - 1) % a)) {
        --r;
      }
    }
    cout << r / a + (r % a) << '\n';
  }
  return 0;
}