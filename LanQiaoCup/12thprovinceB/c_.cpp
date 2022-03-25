/**
 *    author: subobo
 *    created: 25.03.2022 12:11:17
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
  vector<long long> b;
  for (long long i = 1; i <= n / i; i++) {
    if (n % i == 0) {
      b.push_back(i);
      b.push_back(n / i);
    }
  }
  sort(b.begin(), b.end());
  for (int i = 1; i < (int) b.size(); i++) {
    long long x = (long long) floor(sqrt(n * b[i]));
    if (x * x == n * b[i]) {
      cout << b[i] << '\n';
      break;
    }
  }
  return 0;
}