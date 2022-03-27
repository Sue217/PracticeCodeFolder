/**
 *    author: subobo
 *    created: 27.03.2022 13:26:00
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  bool da = true;
  bool db = true;
  for (int i = 1; i < n; i++) {
    bool sa = da && (abs(a[i] - a[i - 1]) <= k) || db && (abs(a[i] - b[i - 1]) <= k);
    bool sb = da && (abs(b[i] - a[i - 1]) <= k) || db && (abs(b[i] - b[i - 1]) <= k);
    da = sa;
    db = sb;
  }
  if (da || db) {
    cout << "Yes" << '\n';
  } else {
    cout << "No" << '\n';
  }
  return 0;
}