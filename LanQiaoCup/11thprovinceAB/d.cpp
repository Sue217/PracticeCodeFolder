/**
 *    author: subobo
 *    created: 01.04.2022 17:34:31
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
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector s(11, vector<long long>(k));
  for (int i = 0; i < n; i++) {
    long long m = a[i] % k;
    for (int b = 0; b <= 10; b++) {
      s[b][m] += 1;
      m = m * 10 % k;
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long m = a[i] % k;
    int bit = (int) to_string(a[i]).size();
    ans += s[bit][(k - m) % k];
    long long d = m * (long long) pow(10, bit) % k;
    if (d == (k - m) % k) {
      ans -= 1;
    }
  }
  cout << ans << '\n';
  return 0;
}