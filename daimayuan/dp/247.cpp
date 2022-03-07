/**
 *    author: subobo
 *    created: 07.03.2022 12:16:05
**/
#include <bits/stdc++.h>

using namespace std;

vector<bool> prime(200, true);

inline long long calc(long long x) {
  x += 1;
  vector<int> a;
  while (x) {
    a.push_back(x % 10);
    x /= 10;
  }
  a.push_back(0);
  reverse(begin(a), end(a));
  int m = (int) a.size() - 1;
  const int N = m * 9;
  long long ans = 0;
  int sum = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < a[i]; j++) {
      // dp[i][j]: consider a[i], and the sum of prev of i is j
      vector<vector<long long>> dp(m + 2, vector<long long>(N + 2));
      dp[i][sum + j] = 1;
      for (int k = i + 1; k <= m; k++) {
        for (int p = 0; p <= (k - 1) * 9; p++) {
          if (dp[k - 1][p] != 0) {
            for (int q = 0; q < 10; q++) {
              dp[k][p + q] += dp[k - 1][p];
            }
          }
        }
      }
      for (int s = 2; s <= N; s++) {
        if (prime[s] && dp[m][s] != 0) {
          ans += dp[m][s];
        }
      }
    }
    sum += a[i];
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  prime[0] = prime[1] = false;
  for (int i = 2; i < 200; i++) {
    if (!prime[i]) {
      continue;
    }
    for (int j = i + i; j < 200; j += i) {
      prime[j] = false;
    }
  }
  long long L, R;
  cin >> L >> R;
  long long ans = calc(R) - calc(L - 1);
  cout << ans << '\n';
  return 0;
}