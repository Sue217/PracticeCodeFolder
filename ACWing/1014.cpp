/**
 *    author: subobo
 *    created: 09.01.2022 10:30:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> alt(n);
  for (auto& in : alt) {
    cin >> in;
  }
  vector<int> up(n), down(n);
  for (int i = 0; i < n; i++) {
    up[i] = 1;
    for (int j = 0; j < i; j++) {
      if (alt[i] > alt[j]) {
        up[i] = max(up[i], up[j] + 1);
      }
    }
  }
  for (int i = n - 1; ~i; i--) {
    down[i] = 1;
    for (int j = n - 1; j > i; j--) {
      if (alt[i] > alt[j]) {
        down[i] = max(down[i], down[j] + 1);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, up[i] + down[i] - 1);
  }
  cout << res << '\n';
  return 0;
}
