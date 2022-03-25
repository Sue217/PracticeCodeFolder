/**
 *    author: subobo
 *    created: 25.03.2022 23:03:37
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
  while (tt--) {
    long long n;
    cin >> n;
    long long k = 1;
    while (n % 2 == 0) {
      n /= 2;
      k *= 2;
    }
    if (n == 1) {
      cout << "-1" << '\n';
    } else {
      cout << min(n, 2 * k) << '\n';
    }
  }
  return 0;
}