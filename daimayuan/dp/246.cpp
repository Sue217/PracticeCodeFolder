/**
 *    author: subobo
 *    created: 06.03.2022 16:49:48
**/
#include <bits/stdc++.h>

using namespace std;

inline long long calc(long long x) {
  x += 1;
  if (x == 0) {
    return 0;
  }
  vector<int> a;
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  a.push_back(0);
  reverse(a.begin(), a.end());
  int m = (int) a.size() - 1;
  long long ans = 0;
  bool ok = true;
  for (int i = 1; i <= m && ok; i++) {
    for (int j = 0; j < a[i]; j++) {
      if (i != 1 && abs(j - a[i - 1]) > 2) {
        continue;
      }
      vector<vector<vector<long long>>> dp(m + 2, vector<vector<long long>> (10, vector<long long>(2)));
      if (i == 1 && j == 0) {
        dp[i][j][0] = 1;
      } else {
        dp[i][j][1] = 1;
      }
      for (int k = i + 1; k <= m; k++) {
        // dp[k][][] += dp[k - 1][][]
        for (int p = 0; p < 10; p++) {
          for (int s = 0; s < 2; s++) {
            if (dp[k - 1][p][s] != 0) {
              for (int q = 0; q < 10; q++) {
                // a[k - 1] = p, a[k] = q
                // s = 1
                if (s == 1 && abs(p - q) <= 2) {
                  dp[k][q][1] += dp[k - 1][p][1];
                }
                // s = 0
                if (s == 0) {
                  if (q == 0) {
                    dp[k][0][0] += dp[k - 1][0][0];
                  } else {
                    dp[k][q][1] += dp[k - 1][0][0];
                  }
                }
              }
            }
          }
        }
      }
      for (int j = 0; j < 10; j++) {
        ans += dp[m][j][1];
      }
    }
    if (i != 1 && abs(a[i] - a[i - 1]) > 2) {
      ok = false;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long L, R;
  cin >> L >> R;
  long long ans = calc(R) - calc(L - 1);
  cout << ans << '\n';
  return 0;
}