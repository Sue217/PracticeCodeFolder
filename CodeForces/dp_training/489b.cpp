/**
 *    author: subobo
 *    created: 28.01.2022 19:36:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (auto& in : a) {
    cin >> in;
  }
  cin >> m;
  vector<int> b(m);
  for (auto& in : b) {
    cin >> in;
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int ans = 0;
  for (int pa = 0, pb = 0; pa < n && pb < m;) {
    if (abs(a[pa] - b[pb]) <= 1) {
      ans += 1;
      pa += 1;
      pb += 1;
    } else {
      if (a[pa] < b[pb]) {
        pa += 1;
      } else {
        pb += 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}