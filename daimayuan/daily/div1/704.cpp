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

inline long long power(int x, int y) {
  long long ans = 1;
  while (y > 0) {
    ans *= x;
    --y;
    if (ans >= 10000000) return 0;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  constexpr int N = 10000001;
  vector<int> prime;
  vector<int> pmn(N);
  bitset<N> used;
  for (int d = 2; d < N; d++) {
    if (used[d] == 0) {
      prime.push_back(d);
      pmn[d] = d;
    }
    for (int cc = 0; prime[cc] <= (N - 1) / d; cc++) {
      used[prime[cc] * d] = 1;
      pmn[prime[cc] * d] = prime[cc];
      if (d % prime[cc] == 0) break;
    }
  }
  vector<int> pr(N);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    /*
    auto power = [&](int x, int y)->long long {
      long long ans = 1;
      while(y > 0) {
        ans *= x;
        --y;
        if (ans >= N) return 0;
      }
      return ans;
    };
    */
    long long v = 1;
    long long u = 1;
    while (x > 1) {
      int dd = x % 2 == 0 ? 2 : pmn[x];
      int cc = 0;
      while (x % dd == 0) {
        ++cc;
        x /= dd;
      }
      cc %= k;
      if (cc > 0) {
        v *= power(dd, cc);
        u *= power(dd, k - cc);
        if (u >= N) u = 0;
      }
    }
    /*
    for (int d = 0; prime[d] <= x; d++) {
      int cc = 0;
      if (x % prime[d] == 0) {
        while (x % prime[d] == 0) {
          ++cc;
          x /= prime[d];
        }
      }
      cc %= k;
      if (cc > 0) {
        v *= power(prime[d], cc);
        u *= power(prime[d], k - cc);
        if (u >= N) u = 0;
      }
    }
    if (x > 1) {
      v *= x;
      u *= power(x, k - 1);
    }
    */
    ans += pr[u];
    pr[v] += 1;
  }
  cout << ans << '\n';
  return 0;
}