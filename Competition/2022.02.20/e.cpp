/**
 *    author: subobo
 *    created: 20.02.2022 14:53:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> ld, rp;
  for (int i = 0; i < n; i++) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    ld.emplace_back(a, b);
    rp.emplace_back(a + x, b + y);
  }
  int x, y;
  cin >> x >> y;
  for (int i = n - 1; i >= 0; i--) {
    if (x >= ld[i].first && x <= rp[i].first && y >= ld[i].second && y <= rp[i].second) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  puts("-1");
  return 0;
}