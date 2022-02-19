/**
 *    author: subobo
 *    created: 19.02.2022 20:32:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long x;
  cin >> x;
  if (x % 10 == 0) {
    cout << x / 10 << '\n';
  } else {
    if (x < 0) {
      cout << x / 10 - 1 << '\n';
    } else {
      cout << x / 10 << '\n';
    }
  }
  return 0;
}