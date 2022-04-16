/**
 *    author: subobo
 *    created: 15.04.2022 20:28:27
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

int main() {
  int n;
  cin >> n;
  vector<int> dp(n + 1);
  dp[0] = 1;
  constexpr int mod = (int) 1e9 + 7;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      dp[j] = (dp[j] + dp[j - i]) % mod;
    }
  }
  cout << dp[n] << '\n';
  return 0;
}