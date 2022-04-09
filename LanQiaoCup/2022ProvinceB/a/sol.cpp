#include <bits/stdc++.h>

using namespace std;

int main() {
  int y = 2022;
  int ans = 0;
  while (y > 0) {
    int d = y % 10;
    ans = ans * 9 + d;
    y /= 10;
  }
  cout << ans << '\n';
  return 0;
}