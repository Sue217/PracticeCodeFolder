/**
 *    author: subobo
 *    created: 27.03.2022 15:31:30
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1), c(n + m + 1);
  for (int i = 0; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= n + m; i++) {
    cin >> c[i];
  }
  for (int i = m; i >= 0; i--) {
    b[i] = c[i + n] / a[n];
    for (int j = 0; j <= n; j++) {
      c[i + j] -= b[i] * a[j];
    }
  }
  for (int i = 0; i <= m; i++) {
    cout << b[i] << " \n"[i == m];
  }
  return 0;
}