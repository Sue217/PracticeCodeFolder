/**
 *    author: subobo
 *    created: 20.01.2022 16:22:30
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long w, h, n;
  cin >> w >> h >> n;
  long long l = 0, r = 1;
  auto check = [&](long long x) {
    return (x / w) * (x / h) >= n;
  };
  while (!check(r)) {
    r <<= 1;
  }
  while (r > l + 1) {
    long long md = (r + l) / 2;
    if (check(md)) {
      r = md;
    } else {
      l = md;
    }
  }
  cout << r << '\n';
  return 0;
}