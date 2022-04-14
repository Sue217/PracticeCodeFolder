/**
 *    author: subobo
 *    created: 13.04.2022 11:55:56
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
  int n, k;
  cin >> n >> k;
  constexpr int N = 1000001;
  vector<int> pr(N);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    auto power = [&](int x, int y)->long long {
      long long ans = 1;
      while(y > 0) {
        ans *= x;
        --y;
        if (ans >= N) return 0;
      }
      return ans;
    };
    long long v = 1;
    long long u = 1;
    for (int d = 2; d <= x / d; d++) {
      int cc = 0;
      if (x % d == 0) {
        while (x % d == 0) {
          ++cc;
          x /= d;
        }
        cc %= k;
        if (cc > 0) {
          v *= power(d, cc);
          u *= power(d, k - cc);
        }
      }
    }
    if (x > 1) {
      v *= x;
      u *= power(x, k - 1);
    }
    if (u >= N) u = 0;
    ans += pr[u];
    pr[v] += 1;
  }
  cout << ans << '\n';
  return 0;
}