/**
 *    author: subobo
 *    created: 20.01.2022 15:24:59
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
    int l = -1, r = n;
    while (r > l + 1) {
      int md = (l + r) >> 1;
      if (seq[md] >= x) {
        r = md;
      } else {
        l = md;
      }
    }
    cout << r + 1 << '\n';
  }
  return 0;
}