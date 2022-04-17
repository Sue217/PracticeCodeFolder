#include <bits/stdc++.h>

using namespace std;

int main() {
  int k;
  cin >> k;
  if (k == 0) {
    cout << 9 << '\n';
    cout << "7 8 9 4 5 6 1 2 3" << '\n';
    return 0;
  }
  if (k == 1) {
    cout << "1 1 4 5 1 4" << '\n';
    return 0;
  }
  int a = 0, b = 0;
  int mn = (int) 2e8;
  for (int d = 1; d <= k / d; d++) {
    if (k % d == 0) {
      if (mn > d + k / d) {
        a = d;
        b = k / d;
        mn = d + k / d;
      }
    }
  }
  if (mn > 365) {
    cout << -1 << '\n';
    return 0;
  }
  cout << mn << '\n';
  --b;
  int st = 100000000 - a + 1;
  for (int i = 0; i < a; i++) {
    cout << st << " ";
    ++st;
  }
  st = b;
  for (int i = 0; i < b; i++) {
    cout << st << " ";
    --st;
  }
  cout << 100000000 << '\n';
  return 0;
}