/*
ID: sujingb1
TASK: dualpal
LANG: C++
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ofstream fout ("dualpal.out");
  ifstream fin ("dualpal.in");
  int n, m;
  fin >> n >> m;
  int it = m + 1;
  while (n) {
    bool once = false;
    for (int base = 2; base <= 10; base++) {
      string s = "";
      int t = it;
      while (t) {
        s += t % base + '0';
        t /= base;
      }
      string revs = s;
      reverse(revs.begin(), revs.end());
      if (s == revs) {
        if (!once) {
          once = true;
        } else {
          fout << it << '\n';
          n -= 1;
          break;
        }
      }
    }
    it += 1;
  }
  return 0;
}