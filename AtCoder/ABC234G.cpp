/**
 *    author: subobo
 *    created: 26.02.2022 22:50:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  // dp[i] += dp[i - j - 1] * v
  // dp[i] = sum(dp[j] * max(a[j + 1,..., i])) - sum(dp[j] * min(a[j + 1,..., i]))

  // dp[1] = dp[0] * (max(a[1]) - min(a[1]))
  // dp[2] = dp[0] * (max(a[1], a[2]) - min(a[1], a[2])) + dp[1] * (max(a[2]) - min(a[2]))
  // dp[3] = dp[0] * (max(a[1], a[2], a[3]) - min(a[1], a[2], a[3]))
  //       + dp[1] * (max(a[2], a[3]) - min(a[2], a[3])) + dp[2] * (max(a[3]) - min(a[3]))

  // max_sum = sum(dp[j + 1,..., i] * max(a[j + 1,..., i]))

  // dpM..? the value of dp[] which is led by a[top]
  // dpM..[i] += dpM..[j]
  static constexpr long long mod = 998244353;
  vector<long long> dp(n + 1), dpMax(n + 1), dpMin(n + 1);
  dp[0] = dpMax[0] = dpMin[0] = 1;
  stack<int> Max, Min;
  long long max_sum = 0, min_sum = 0;
  for (int i = 1; i <= n; i++) {
    // max
    dpMax[i] = dp[i - 1];
    while (!Max.empty() && a[Max.top()] < a[i]) {
      int j = Max.top();
      Max.pop();
      dpMax[i] = (dpMax[i] + dpMax[j]) % mod;
      max_sum = (max_sum - dpMax[j] * a[j] % mod + mod) % mod;
    }
    Max.push(i);
    max_sum = (max_sum + dpMax[i] * a[i] % mod) % mod;
    // min
    dpMin[i] = dp[i - 1];
    while (!Min.empty() && a[Min.top()] > a[i]) {
      int j = Min.top();
      Min.pop();
      dpMin[i] = (dpMin[i] + dpMin[j]) % mod;
      min_sum = (min_sum - dpMin[j] * a[j] % mod + mod) % mod;
    }
    Min.push(i);
    min_sum = (min_sum + dpMin[i] * a[i] % mod) % mod;
    // get result
    dp[i] = (max_sum - min_sum + mod) % mod;
  }
  cout << dp[n] << '\n';
  return 0;
}