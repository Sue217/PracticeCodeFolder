/**
 *    author: subobo
 *    created: 18.06.2022 09:32:58
 **/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<pair<int, int>> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = make_pair(a[i], b[i]);
  }
  sort(c.begin(), c.end());
  vector<int> pref(1);
  for (int i = 0; i < n; i++) {
    pref.push_back(pref.back() + c[i].first);
  }
  cout << accumulate(a.begin(), a.end(), 0) / n + 1 << '\n';
  return 0;
}