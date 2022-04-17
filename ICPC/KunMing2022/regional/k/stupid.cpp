#include <bits/stdc++.h>

using namespace std;

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
    int n, a, b;
    cin >> n >> a >> b;
    double x = (double) a / (double) b;
    int win = 0, lose = 0, played = 0;
    for (int i = 1; i <= n; i++) {
      if (played == 0) {
        win += 1;
        played += 1;
        continue;
      }
      if ((double) win / (double) played <= x) {
        win += 1;
      } else {
        lose += 1;
      }
      played += 1;
    }
    cout << win << '\n';
  }
  return 0;
}