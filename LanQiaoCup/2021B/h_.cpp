#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long ans = 0;
  vector f(2001, vector<int>(2001));
  f[0][0] = 1;
  for (int i = 1; i <= 2000; i++) {
    for (int j = 1; j <= i; j++) {
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
      if (f[i][j] >= 1000000000) f[i][j] = 1000000001;
      ++ans;
      if (f[i][j] == n) {
        cout << ans << '\n';
        return 0;
      }
    }
  }
  for (long long d = 1; d <= 100000; d++) {
    if (d * (d - 1) / 2 == n) {
      cout << d * (d + 1) / 2 + 3 << '\n';
      return 0;
    }
  }
  cout << n * (n + 1) / 2 + 2 << '\n';
  return 0;
}

