/*
    ID: sujingb1
    TASK: skidesign
    LANG: C++11
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("skidesign.in");
  ofstream fout ("skidesign.out");
  int n;
  fin >> n;
  vector<int> hill(n, 0);
  for (int& in : hill) {
    fin >> in;
  }
  long long ans = (long long) 2e18;
  for (int l = 1; l <= 83; l++) {
    int r = l + 17;
    long long tot = 0;
    for (int it : hill) {
      if (it < l) {
        tot += (l - it) * (l - it);
      } else
      if (it > r) {
        tot += (it - r) * (it - r);
      }
    }
    ans = min(ans, tot);
  }
  fout << ans << '\n';
  return 0;
}