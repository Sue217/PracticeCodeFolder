/**
 *    author: subobo
 *    created: 10.04.2022 18:57:36
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

constexpr long long mod = 1000000007;
constexpr int N = 10000001;
long long f[N][3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  f[1][0] = 1;
  f[1][1] = 0;
  f[1][2] = 1;
  for (int i = 2; i <= n; i++) {
    f[i][0] = (f[i][0] + f[i - 1][0] + f[i - 1][1] + f[i - 1][2]) % mod;
    f[i][1] = (f[i][1] + f[i - 1][1] + f[i - 1][2] * 2) % mod;
    f[i][2] = (f[i][2] + f[i - 1][0]) % mod;
  }
  cout << f[n][0] << '\n';
  return 0;
}