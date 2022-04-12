#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<long long>> pref(n, vector<long long>(1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long x;
      cin >> x;
      pref[i].push_back(pref[i].back() + x);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = i; j <= m; j++) {
      long long sum = 0;
      for (int l = 0, r = 0; r < n; r++) {
        sum += pref[r][j] - pref[r][i - 1];
        while (sum > k) {
          sum -= pref[l][j] - pref[l][i - 1];
          ++l;
        }
        ans += r - l + 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
