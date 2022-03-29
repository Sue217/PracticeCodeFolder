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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    fin >> a[i];
  }
  int ans = (int) 2e9;
  for (int low = 0; low + 17 <= 100; low++) {
    int high = low + 17;
    int tax = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < low) {
        tax += (int) pow(low - a[i], 2);
      } else
      if (high < a[i]) {
        tax += (int) pow(a[i] - high, 2);
      }
    }
    ans = min(ans, tax);
  }
  fout << ans << '\n';
  return 0;
}