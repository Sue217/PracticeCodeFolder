/**
 *    author: subobo
 *    created: 03.02.2022 12:49:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  constexpr int N = 1000001;
  vector<bool> primes(N, true);
  primes[0] = primes[1] = false;
  for (int i = 2; i <= N / i; i++) {
    if (primes[i]) {
      for (int j = i * i; j < N; j += i) {
        primes[j] = false;
      }
    }
  }
  while (tt--) {
    int n, e;
    cin >> n >> e;
    vector<int> a(n + 1), pos;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (primes[a[i]]) {
        pos.emplace_back(i);
      }
    }
    long long ans = 0;
    for (int p : pos) {
      long long x = 0, y = 0;
      int it = p - e;
      while (it > 0) {
        if (a[it] != 1) {
          break;
        }
        it -= e;
        x += 1;
      }
      it = p + e;
      while (it <= n) {
        if (a[it] != 1) {
          break;
        }
        it += e;
        y += 1;
      }
      ans += x * y + x + y;
    }
    cout << ans << '\n';
  }
  return 0;
}