/**
 *    author: subobo
 *    created: 20.01.2022 14:58:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> seq(n);
  for (auto& in : seq) {
    cin >> in;
  }
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    int l = 0, r = n - 1;
    bool ok = true;
    while (l <= r) {
      int md = (l + r) >> 1;
      if (seq[md] == x) {
        ok = false;
        break;
      } else {
        if (seq[md] > x) {
          r = md - 1;
        } else {
          l = md + 1;
        }
      }
    }
    if (ok) {
      puts("NO");
    } else {
      puts("YES");
    }
  }
  return 0;
}