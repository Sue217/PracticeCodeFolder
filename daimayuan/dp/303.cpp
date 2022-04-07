/**
 *    author: subobo
 *    created: 07.04.2022 15:40:38
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
  string in;
  cin >> in;
  string s = "s";
  s += in;
  vector<vector<long long>> f(n + 1, vector<long long>(n + 1));
  vector<vector<long long>> g(n + 1, vector<long long>(n + 1));
  static constexpr long long mod = (long long) 1e9 + 7;
  for (int d = 0; d < n; d++) {
    for (int l = 1; l + d <= n; l++) {
      int r = l + d;
      // case# 1 & 3
      if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?') && l != r) {
        // ()
        if (r == l + 1) {
          g[l][r] = (g[l][r] + 1) % mod;
        } else
        if (r - l - 1 <= k) {
          // (S) (*...*)
          int ok = 1;
          for (int p = l + 1; p < r; p++) {
            if (s[p] != '*' && s[p] != '?') {
              ok = 0;
              break;
            }
          }
          g[l][r] = (g[l][r] + ok) % mod;
          // (A)
          g[l][r] = (g[l][r] + f[l + 1][r - 1]) % mod;
          // (SA)
          for (int p = l + 1; p < r - 1 && p - l <= k; p++) {
            if (s[p] != '*' && s[p] != '?') {
              break;
            }
            g[l][r] = (g[l][r] + f[p + 1][r - 1]) % mod;
          }
          // (AS)
          for (int p = r - 1; p > l + 1 && r - p <= k; p--) {
            if (s[p] != '*' && s[p] != '?') {
              break;
            }
            g[l][r] = (g[l][r] + f[l + 1][p - 1]) % mod;
          }
        }
      }
      // case# 2
      f[l][r] = g[l][r];
      if (s[l] == '(' || s[l] == '?') {
        for (int m = l + 1; m < r; m++) {
          // AB
          long long sum = f[m + 1][r];
          // ASB
          for (int p = m + 1; p < r - 1 && p - m <= k; p++) {
            if (s[p] != '*' && s[p] != '?') {
              break;
            }
            sum = (sum + f[p + 1][r]) % mod;
          }
          f[l][r] = (f[l][r] + g[l][m] * sum % mod) % mod;
        }
      }
      cerr << l << " " << r << " " << g[l][r] << " " << f[l][r] << '\n';
    }
  }
  cout << f[1][n] << '\n';
  return 0;
}