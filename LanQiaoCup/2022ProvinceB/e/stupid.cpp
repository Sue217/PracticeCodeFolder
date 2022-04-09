#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long ans = 2;
  const long long mod = 1000000007;
  for (int d = 3; d <= n; d++) {
    ans = (ans * 2 + 1) % mod;
  }
  cout << ans << '\n';
  return 0;
}