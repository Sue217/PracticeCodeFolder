/**
 *    author: subobo
 *    created: 06.04.2022 11:32:45
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
  vector a(n, vector<int>(k));
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }
  vector f(n, vector<long long>(k + 1));
  for (int i = 0; i < n; i++) {
    long long pref = 0;
    for (int j = 0; j < min(k, c[i]); j++) {
      pref += a[i][j];
      f[i][j + 1] = max(f[i][j + 1], pref);
    }
  }
  vector<long long> g(k + 1);
  cout << g[k] << '\n';
  return 0;
}