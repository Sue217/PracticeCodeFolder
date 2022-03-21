/**
 *    author: subobo
 *    created: 09.02.2022 22:51:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int B;
  cin >> B;
  for (int x = 1; x <= 300; x++) {
    int y = x, z = x * x;
    string base = "", sqr = "";
    char c;
    while (y) {
      int mod = y % B;
      if (mod >= 10) {
        c = mod - 10 + 'A';
      } else {
        c = mod + '0';
      }
      base += c;
      y /= B;
    }
    while (z) {
      int mod = z % B;
      if (mod >= 10) {
        c = mod - 10 + 'A';
      } else {
        c = mod + '0';
      }
      sqr += c;
      z /= B;
    }
    string revs = sqr;
    reverse(revs.begin(), revs.end());
    reverse(base.begin(), base.end());
    if (sqr == revs) {
      cout << base << " " << sqr << '\n';
    }
  }
  return 0;
}