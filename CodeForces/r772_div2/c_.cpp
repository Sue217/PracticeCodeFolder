/**
 *    author: subobo
 *    created: 09.03.2022 10:42:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    if (a[n - 1] > a[n]) {
      cout << -1 << '\n';
      continue;
    }
    bool ok = true;
    vector<pair<int, int>> op;
    for (int i = n - 2; i >= 1; i--) {
      if (a[i] > a[i + 1]) {
        a[i] = a[i + 1] - a[n];
        if (a[i] > a[i + 1]) {
          ok = false;
          break;
        }
        op.emplace_back(i, i + 1);
      }
    }
    if (ok) {
      cout << op.size() << '\n';
      for (auto it : op) {
        cout << it.first << " " << it.second << " " << n << '\n';
      }
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}