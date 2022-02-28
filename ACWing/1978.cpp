/**
 *    author: subobo
 *    created: 28.02.2022 20:58:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> p;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    p.emplace_back(a, b);
  }
  sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.second < b.second;
  });
  for (int i = 0; i < n; i++) {
    p[i].second = i;
  }
  sort(p.begin(), p.end());
  int ans = 0, mx = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].second > i) {
      mx = max(mx, p[i].second);
    } else
    if (i == p[i].second && i >= mx) {
      ans += 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
