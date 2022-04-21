#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int x;
    cin >> x;
    int hh = -1;
    bool ok = true;
    for (int i = 2; i <= 9; i++) {
      string s(to_string(x * i));
      int sum = 0;
      for (char c : s) {
        sum += c - '0';
      }
      if (hh == -1) {
        hh = sum;
        continue;
      }
      if (sum != hh) {
        ok = false;
        break;
      }
    }
    if (ok) {
      cout << hh << '\n';
    } else {
      cout << "NO" << '\n';
    }
  }
  return 0;
}