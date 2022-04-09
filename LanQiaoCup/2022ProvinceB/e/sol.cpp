#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int ma;
  cin >> ma;
  vector<long long> a(ma);
  for (int i = 0; i < ma; i++) {
    cin >> a[i];
  }
  int mb;
  cin >> mb;
  vector<long long> b(mb);
  for (int i = 0; i < mb; i++) {
    cin >> b[i];
  }
  int mx = ma;
  int mn = mb;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  const int mod = 1000000007;
  long long ans = 0;
  int pos = 0;
  auto power = [&](long long x, long long y)->long long {
    assert(y >= 0);
    long long ans = 1;
    while (y > 0) {
      if (y & 1) ans = ans * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ans;
  };
  for (int i = 0; i < mn; i++) {
    long long bit = max(a[i], b[i]) + 1;
    if (i == 0) {
      bit = 2;
    }
    if (i == mx - 1) {
      bit = n;
    }
    long long div = (long long) abs(a[i] - b[i]);
    ans = (ans * 10 % mod + power(bit, pos) * div) % mod;
    ++pos;
  }
  if (mx > mn) {
    for (int i = mn; i < mx; i++) {
      long long bit = a[i] + 1;
      if (i == mx - 1) {
        bit = n;
      }
      ans = (ans * 10 % mod + power(bit, pos) * (bit - 1)) % mod;
      ++pos;
    }
  }
  cout << ans << '\n';
  return 0;
}