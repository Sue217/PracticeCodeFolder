/**
 *    author: subobo
 *    created: 08.02.2022 20:03:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int64_t a, b, p;
  cin >> a >> b >> p;
  auto f_add = [&](int64_t a, int64_t b) {
    int64_t ans = 0;
    while (b) {
      if (b & 1) {
        ans = (ans + a) % p;
      }
      a = (a + a) % p;
      b >>= 1;
    }
    return ans;
  };
  cout << f_add(a, b) << '\n';
  return 0;
}