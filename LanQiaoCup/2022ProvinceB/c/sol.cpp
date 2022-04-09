#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long long a, b, n;
  unsigned long long ans = 0;
  cin >> a >> b >> n;
  unsigned long long ff = 5 * a + 2 * b;
  ans += n / ff;
  ans *= 7;
  n %= ff;
  unsigned long long got = 0;
  for (int d = 0; d < 7; d++) {
    if (got >= n) {
      break;
    }
    got += (0 <= d && d < 5 ? a : b);
    ans += 1;
  }
  cout << ans << '\n';
  return 0;
}