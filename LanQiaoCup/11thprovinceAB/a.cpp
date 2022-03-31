/**
 *    author: subobo
 *    created: 31.03.2022 14:46:51
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
  long long n;
  cin >> n;
  while (n) {
    cout << n << " \n"[n == 1];
    n >>= 1;
  }
  return 0;
}