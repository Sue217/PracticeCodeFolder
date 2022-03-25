/**
 *    author: subobo
 *    created: 25.03.2022 19:20:15
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
  auto isPrime = [&](long long x) {
    for (long long i = 2; i <= x / i; i++) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };
  long long sq = (long long) sqrt(n);
  vector<long long> a;
  for (long long x = 2; x <= sq; x++) {
    if (n % x == 0 && isPrime(x)) {
      int cnt = 0;
      while (n % x == 0) {
        n /= x;
        ++cnt;
      }
      if (cnt % 2 != 0) {
        a.push_back(x);
      }
    }
    if (n == 1) {
      break;
    }
  }
  if (n != 1) {
    a.push_back(n);
  }
  long long ans = 1;
  for (long long it : a) {
    ans *= it;
  }
  cout << ans << '\n';
  return 0;
}