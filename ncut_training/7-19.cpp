/**
 *    author: subobo
 *    created: 28.01.2022 22:13:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  bool ok = true;
  int x;
  for (int tt = 1; ; tt++) {
    cin >> x;
    if (ok && x == 250) {
      cout << tt << '\n';
      break;
    }
  }
  return 0;
}