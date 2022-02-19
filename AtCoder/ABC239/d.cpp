/**
 *    author: subobo
 *    created: 19.02.2022 21:00:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<bool> is_prime(220, false);
  is_prime[2] = true;
  for (int i = 3; i <= 200; i++) {
    bool ok = true;
    for (int j = 2; j <= i / j; j++) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      is_prime[i] = true;
    }
  }
  for (int i = a; i <= b; i++) {
    bool ok = true;
    for (int j = c; j <= d; j++) {
      if (is_prime[i + j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
      puts("Takahashi");
      return 0;
    }
  }
  puts("Aoki");
  return 0;
}