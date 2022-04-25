/**
 *    author: subobo
 *    created: 25.04.2022 01:18:13
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
  int tt = 100;
  cout << tt << '\n';
  mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  while (tt--) {
    int n = rng() % 100000;
    cout << n << '\n';
    for (int i = 0; i < n; i++) {
      cout << rng() % 30 << " \n"[i == n - 1];
    }
  }
  return 0;
}