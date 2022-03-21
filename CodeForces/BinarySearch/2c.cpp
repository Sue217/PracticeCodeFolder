/**
 *    author: subobo
 *    created: 20.01.2022 23:22:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  if (x > y) {
    swap(x, y);
  }
  auto check = [&](long long time) {
    return (time / x + (time - x) / y) >= n;
  };
  long long l = y, r = n * x;
  while (r > l + 1) {
    long long md = (l + r) >> 1;
    if (check(md)) {
      r = md;
    } else {
      l = md;
    }
  }
  cout << r << '\n';
  return 0;
}