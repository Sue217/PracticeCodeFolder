/*
ID: sujingb1
TASK: palsquare
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("palsquare.out");
  ifstream fin ("palsquare.in");
  int B;
  fin >> B;
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
      fout << base << " " << sqr << '\n';
    }
  }
  return 0;
}