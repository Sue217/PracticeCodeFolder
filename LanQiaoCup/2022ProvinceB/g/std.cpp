#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  constexpr long long mod = 1000000007;
  vector<long long> f(n + 1);
  vector<long long> g(n + 1);
  f[0] = 1;
  f[1] = 1;
  g[1] = 1;
  for (int i = 2; i <= n; i++) {
    f[i] = (f[i] + f[i - 1] + f[i - 2] + g[i - 2] * 2) % mod;
    g[i] = (g[i] + f[i - 1] + g[i - 1]) % mod;
  }
  cout << f[n] << '\n';
  return 0;
}
