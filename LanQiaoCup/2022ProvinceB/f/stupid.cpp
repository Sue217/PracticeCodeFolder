#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> a(n + 1, vector<long long>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<long long>> s(n + 1, vector<long long>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int x = 1; x <= i; x++) {
        for (int y = 1; y <= j; y++) {
          // cerr << "[" << x << ", " << y << "]" << " & " << "[" << i << "," << j << "] " << s[i][j] - s[x - 1][j] - s[i][y - 1] + s[x - 1][y - 1] << '\n';
          if (s[i][j] - s[x - 1][j] - s[i][y - 1] + s[x - 1][y - 1] <= k) {
            ans += 1;
          }
        }
      }
    }
  }
  cout << ans << '\n';
  cerr << "time: " << clock() << " ms" << '\n';
  return 0;
}